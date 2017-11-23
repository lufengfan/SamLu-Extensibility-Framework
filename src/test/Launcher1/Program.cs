using SamLu.Extensibility;
using SamLu.Extensibility.FileBase;
using System;
using System.Collections.Generic;
using System.ComponentModel.Composition;
using System.ComponentModel.Composition.Hosting;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Launcher1
{
    class Program
    {
        [Export("FileName", typeof(string))]
        private static string FileName;

        static void Main(string[] args)
        {
            CompositionContainer container = new CompositionContainer(new AssemblyCatalog(Assembly.GetAssembly(typeof(Program))));
            Program.FileName = Assembly.GetAssembly(typeof(Program)).Location;
            IFileBaseContainer fileBaseContainer = new ManagedAssemblyContainer();
            container.ComposeParts(fileBaseContainer);
            ;
            fileBaseContainer.Initialize();
            ;
            IEnumContents enumContents = fileBaseContainer.Contents;
            ;

            container = new CompositionContainer(new AssemblyCatalog(Assembly.GetAssembly(typeof(Program))));
            Program.FileName = @"Package001.dll";
            fileBaseContainer = new UnmanagedCodeContainer();
            container.ComposeParts(fileBaseContainer);
            ;
            fileBaseContainer.Initialize();
            ;
            enumContents = fileBaseContainer.Contents;
            ;
            uint celt = 10U;
            object[] rgelt = new object[celt];
            enumContents.Next(celt, rgelt, out uint pceltFetched);
            ;
        }
    }
}
