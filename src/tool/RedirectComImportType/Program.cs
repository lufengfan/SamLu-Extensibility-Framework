using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace RedirectComImportType
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Input .Net assembly file path.");
            string managed_assembly_path = Console.ReadLine();
            Assembly assembly = Assembly.LoadFrom(managed_assembly_path);
            var comTypes = assembly.GetTypes().Where(t => t.GetCustomAttribute<ComImportAttribute>() != null);

            var r = comTypes.ToList();
            r.ForEach(t => Console.WriteLine(t.FullName));
            
            Console.WriteLine();
            ;
        }
    }
}
