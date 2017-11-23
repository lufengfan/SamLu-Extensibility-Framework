using SamLu.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace SamLu.Extensibility.FileBase
{
    [ComImport, Guid("1296BFC3-4282-4D34-BF17-E4E564ED83D7")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    [TypeLibType(TypeLibTypeFlags.FNonExtensible)]
    [BaseContainer]
    [Extend(typeof(IAnyBaseContainer))]
    public interface IFileBaseContainer : IAnyBaseContainer
    {
        string FileName
        {
            [return: MarshalAs(UnmanagedType.BStr)]
            get;
        }
    }
}
