using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SamLu.Extensibility
{
    [AttributeUsage(AttributeTargets.Interface | AttributeTargets.Class | AttributeTargets.Struct, AllowMultiple = true, Inherited = true)]
    public sealed class ExtendAttribute : Attribute
    {
        private Type extendedType;

        /// <summary>
        /// 获取被扩展类型。
        /// </summary>
        public Type ExtendedType => this.extendedType;

        /// <summary>
        /// 初始化 <see cref="ExtendAttribute"/> 类的新实例，使用指定的被扩展类型。
        /// </summary>
        /// <param name="extendedType">指定的被扩展类型。</param>
        /// <exception cref="ArgumentNullException"><paramref name="extendedType"/> 的值为 null 。</exception>
        /// <exception cref="NotSupportedException"><paramref name="extendedType"/> 未标记为 <see cref="ExtensionPointAttribute"/> 。</exception>
        public ExtendAttribute(Type extendedType)
        {
            if (extendedType == null) throw new ArgumentNullException(nameof(extendedType));
            if (!extendedType.GetCustomAttributes(typeof(ExtensionPointAttribute), false).Any())
                throw new NotSupportedException($"{extendedType} 未标记为 {typeof(ExtensionPointAttribute)} 。");
        }
    }
}
