#pragma once

#include <glm/glm.hpp>
#include <base/base.hpp>

namespace graphics
{
    /// @brief 顶点属性
    class VertexAttribute
    {
    public:
        /// @brief 数据类型
        enum class DataType : base::Int32
        {
            /// @brief 无
            None,
            /// @brief 浮点数
            Float,
            /// @brief 整数
            Int,
            /// @brief 无符号整数
            UnsignedInt,
        };

    public:
        /// @brief 数据类型
        DataType data_type;
        /// @brief 分量总数
        base::Size count;
        /// @brief 偏移量，单位：字节
        base::Size offset;

    public:
        VertexAttribute() = default;
        constexpr VertexAttribute(DataType d, base::Size c, base::Size o)
            : data_type(d), count(c), offset(o) {}
        ~VertexAttribute() = default;

    public:
        /// @brief 获取单个分量的大小，单位：字节
        /// @return 单个分量的大小
        constexpr base::Size get_data_size() const
        {
            switch (data_type)
            {
            case DataType::Float:
                return sizeof(float);

            case DataType::Int:
                return sizeof(int);

            case DataType::UnsignedInt:
                return sizeof(unsigned int);

            default:
                return 0;
            }
        }

        /// @brief 获取整个顶点属性的大小，单位：字节
        /// @return 整个顶点属性的大小
        constexpr base::Size get_total_size() const
        {
            return count * get_data_size();
        }

        /// @brief 获取偏移指针
        /// @return 偏移指针
        constexpr const void *get_offset_pointer() const
        {
            return reinterpret_cast<const void *>(offset);
        }
    };

} // namespace graphics
