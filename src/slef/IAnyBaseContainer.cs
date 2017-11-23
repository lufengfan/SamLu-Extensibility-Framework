using SamLu.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace SamLu.Extensibility
{
    [ComImport, Guid("EE354106-0DDC-43A6-A896-6FB3E5F53D72")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    [TypeLibType(TypeLibTypeFlags.FNonExtensible)]
    [ExtensionPoint]
    public interface IAnyBaseContainer
    {
        IEnumContents Contents
        {
            [return: MarshalAs(UnmanagedType.Interface)]
            get;
        }
        
        [PreserveSig]
        [return: MarshalAs(UnmanagedType.Error)]
        HRESULT Initialize();
        
        [PreserveSig]
        [return: MarshalAs(UnmanagedType.Error)]
        HRESULT Dispose();
    }
}
