using SamLu.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace SamLu.Extensibility.FileBase
{
    [Guid("742705B8-969F-40A0-AD19-ADF3421B0E62")]
    [ClassInterface(ClassInterfaceType.None)]
    public class UnmanagedCodeContainer : FileBaseContainer
    {
        private Win32DllWrapper dllWrapper;

        public override IEnumContents Contents
        {
            get
            {
                const string FuncName_GetContentIIDCount = "GetContentIIDCount";
                const string FuncName_GetContentIIDs = "GetContentIIDs";

                uint count = 0;
                using (var procWrapper = this.dllWrapper.GetProc<GetContentIIDCount>(FuncName_GetContentIIDCount))
                {
                    count = procWrapper.Handler();
                }

                Guid[] riids = new Guid[count];
                using (var procWrapper = this.dllWrapper.GetProc<GetContentIIDs>(FuncName_GetContentIIDs))
                {
                    count = procWrapper.Handler(count, ref riids);
                }

                return new CoEnumContent(riids.Take((int)count));
            }
        }

        public override HRESULT Initialize()
        {
            this.dllWrapper = new Win32DllWrapper(this.FileName);
            ;
            return HRESULT.S_OK;
        }

        [ComVisible(false)]
        [UnmanagedFunctionPointer(CallingConvention.StdCall, SetLastError = true)]
        public delegate uint GetContentIIDCount();
        [ComVisible(false)]
        [UnmanagedFunctionPointer(CallingConvention.StdCall, SetLastError = true)]
        public delegate uint GetContentIIDs([In] uint celt, [In, Out] ref Guid[] riids);

        protected override void DisposeInternal(bool disposing)
        {
            base.DisposeInternal(disposing);

            this.dllWrapper.Dispose();
            this.dllWrapper = null;
        }
    }
}
