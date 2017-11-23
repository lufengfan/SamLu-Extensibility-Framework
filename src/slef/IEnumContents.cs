using SamLu.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace SamLu.Extensibility
{
    [ComImport, Guid("EC5B84CE-352F-4911-BB1D-01E78A8A6EDA")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    [TypeLibType(TypeLibTypeFlags.FNonExtensible)]
    public interface IEnumContents
    {
        [PreserveSig]
        [return: MarshalAs(UnmanagedType.Error)]
        HRESULT Next(
            [In] uint celt,
            [MarshalAs(UnmanagedType.LPArray,
                ArraySubType = UnmanagedType.AsAny,
                SizeParamIndex = 0
            )] [In] object[] rgelt,
            [Out] out uint pceltFetched);
        
        [PreserveSig]
        [return: MarshalAs(UnmanagedType.Error)]
        HRESULT Skip([In] uint celt);
        
        [PreserveSig]
        [return: MarshalAs(UnmanagedType.Error)]
        HRESULT Reset();
        
        void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumContents ppenum);
    }
}
