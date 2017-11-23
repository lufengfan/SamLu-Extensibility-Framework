using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace SamLu
{
    [ComVisible(false)]
    public sealed class RemoteLoader : MarshalByRefObject
    {
        public Assembly LoadAssembly(string fileName)
        {
            if (fileName == null) throw new ArgumentNullException(nameof(fileName));

            return Assembly.LoadFrom(fileName);
        }
    }
}
