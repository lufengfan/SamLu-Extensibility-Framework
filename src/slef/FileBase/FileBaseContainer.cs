using SamLu.Win32;
using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel.Composition;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace SamLu.Extensibility.FileBase
{
    [Guid("E8827CF1-EB93-4ED9-839D-1CE555861F2F")]
    [ClassInterface(ClassInterfaceType.None)]
    [ComDefaultInterface(typeof(IFileBaseContainer))]
    public abstract class FileBaseContainer : IFileBaseContainer, IDisposable
    {
        [Import("FileName", typeof(string))]
        public string FileName { get; protected set; }

        public abstract IEnumContents Contents { get; }

        public abstract HRESULT Initialize();

        public virtual HRESULT Dispose()
        {
            ((IDisposable)this).Dispose();
            return HRESULT.S_OK;
        }

        #region IDisposable Support
        private bool disposedValue = false; // 要检测冗余调用

        private void Dispose(bool disposing)
        {
            if (!disposedValue)
            {
                this.DisposeInternal(disposing);
            }
        }

        protected virtual void DisposeInternal(bool disposing)
        {
            if (disposing)
            {
                // TODO: 释放托管状态(托管对象)。
            }

            // TODO: 释放未托管的资源(未托管的对象)并在以下内容中替代终结器。
            // TODO: 将大型字段设置为 null。

            disposedValue = true;
        }

        // TODO: 仅当以上 Dispose(bool disposing) 拥有用于释放未托管资源的代码时才替代终结器。
        // ~FileBaseContainer() {
        //   // 请勿更改此代码。将清理代码放入以上 Dispose(bool disposing) 中。
        //   Dispose(false);
        // }

        // 添加此代码以正确实现可处置模式。
        void IDisposable.Dispose()
        {
            // 请勿更改此代码。将清理代码放入以上 Dispose(bool disposing) 中。
            Dispose(true);
            // TODO: 如果在以上内容中替代了终结器，则取消注释以下行。
            // GC.SuppressFinalize(this);
        }
        #endregion
    }
}
