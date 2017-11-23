using SamLu.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace SamLu.Extensibility.FileBase
{
    [Guid("E26A074D-0308-40BF-B6F0-99FB6FD4089D")]
    [ClassInterface(ClassInterfaceType.None)]
    public class ManagedAssemblyContainer : FileBaseContainer
    {
        private Assembly assembly;

        #region AppDomain
        private static int no = 1;
        private AppDomain appDomain = null;
        public AppDomain AppDomain
        {
            get
            {
                if (this.appDomain == null)
                    this.appDomain = AppDomain.CreateDomain($"ManagedAssemblyContainer{no++}");
                return this.appDomain;
            }
        }
        #endregion

        public override IEnumContents Contents
        {
            get
            {
                Type this_type = this.GetType();
                var contents = this.assembly.GetTypes()
                    .Where(type =>
                        type.GetCustomAttributes<ContentOfAttribute>()
                            .Any(attribute => attribute.ContainerType == this_type)
                    );
                return new CoEnumContent(contents);
            }
        }

        public override HRESULT Initialize()
        {
            RemoteLoader remoteLoader = (RemoteLoader)this.AppDomain.CreateInstanceAndUnwrap(Assembly.GetAssembly(typeof(RemoteLoader)).FullName, typeof(RemoteLoader).FullName);
            this.assembly = remoteLoader.LoadAssembly(this.FileName);
            ;
            return HRESULT.S_OK;
        }

        protected override void DisposeInternal(bool disposing)
        {
            base.DisposeInternal(disposing);

            this.assembly = null;
            AppDomain.Unload(this.AppDomain);
            this.appDomain = null;
        }
    }
}
