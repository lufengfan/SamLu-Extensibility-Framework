using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace SamLu.Extensibility
{
    [AttributeUsage(AttributeTargets.Interface, AllowMultiple = true, Inherited = true)]
    public class ContentOfAttribute : Attribute
    {
        private Type containerType;

        public bool AllowMultiple { get; set; } = true;

        public Type ContainerType => this.containerType;

        public ContentOfAttribute(Type containerType)
        {
            if (containerType == null) throw new ArgumentNullException(nameof(containerType));
            if (!containerType.GetCustomAttributes(typeof(BaseContainerAttribute), false).Any())
                throw new NotSupportedException($"类型 {containerType} 不支持 {typeof(BaseContainerAttribute)} 。");

            this.containerType = containerType;
        }
    }
}
