using SamLu.Win32;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace SamLu.Extensibility
{
    [ComVisible(false)]
    public class CoEnumContent : IEnumContents, ICloneable
    {
        protected IEnumerable contents;

        #region Enumerator
        private IEnumerator enumerator;
        protected IEnumerator Enumerator
        {
            get
            {
                if (this.enumerator == null)
                    this.enumerator = this.contents.GetEnumerator();
                return this.enumerator;
            }
        }
        #endregion

        public CoEnumContent(IEnumerable enumerable)
        {
            this.contents = enumerable ?? throw new ArgumentNullException(nameof(enumerable));
        }
        
        public void Clone(out IEnumContents ppenum)
        {
            ppenum = new CoEnumContent(this.contents);
        }
        
        public HRESULT Next(uint celt, object[] rgelt, out uint pceltFetched)
        {
            uint ui = 0;
            while (ui < celt && this.Enumerator.MoveNext())
            {
                rgelt[ui] = this.Enumerator.Current;
                ui++;
            }
            pceltFetched = ui;
            return HRESULT.S_OK;
        }
        
        public HRESULT Reset()
        {
            this.Enumerator.Reset();
            return HRESULT.S_OK;
        }
        
        public HRESULT Skip(uint celt)
        {
            for (uint ui = 0; ui < celt; ui++)
            {
                if (!this.Enumerator.MoveNext())
                    return HRESULT.S_FALSE;
            }
            return HRESULT.S_OK;
        }

        object ICloneable.Clone()
        {
            this.Clone(out IEnumContents ppenum);
            return ppenum;
        }
    }
}
