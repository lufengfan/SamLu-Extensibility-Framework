using SamLu.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace SamLu.Extensibility.FileBase
{
    [Guid("998DFAF1-7209-4BFA-8254-F43B301A2947")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    [ContentOf(typeof(IFileBaseContainer), AllowMultiple = true)]
    [ExtensionPoint]
    public interface IFileBasePackage
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
