#pragma once

#include "vertex_attribute.hpp"

namespace graphics
{
    class BaseMesh;
    using BaseMeshRef = base::Ref<BaseMesh>;
    using BaseMeshWeakRef = base::WeakRef<BaseMesh>;

    /// @brief 基础网格
    class BaseMesh : public base::Resource
    {
    public:
        /// @brief 资源类型
        enum class ResourceType : base::Int64
        {
            /// @brief 无
            None,
            /// @brief 2D网格
            Mesh2D,
            /// @brief 3D网格
            Mesh3D,
        };

    public:
        BaseMesh() = default;
        ~BaseMesh() override = default;

    public:
        //
        // 顶点数据
        //

        /// @brief 获取原始顶点数据大小，单位：字节
        /// @return 原始顶点数据大小
        virtual base::Size get_raw_vertices_size() const = 0;

        /// @brief 获取原始顶点数据
        /// @return 原始顶点数据
        virtual const void *get_raw_vertices() const = 0;

        /// @brief 获取顶点大小，单位：字节
        /// @return 顶点大小
        virtual base::Size get_vertex_size() const = 0;

    public:
        //
        // 顶点属性
        //

        /// @brief 是否有位置属性
        /// @return 是否有位置属性
        virtual bool has_position_attrib() const { return true; }

        /// @brief 获取位置属性
        /// @return 位置属性
        virtual const VertexAttribute &get_position_attrib() const = 0;

        /// @brief 是否有纹理坐标属性
        /// @return 是否有纹理坐标属性
        virtual bool has_tex_coord_attrib() const { return true; }

        /// @brief 获取纹理坐标属性
        /// @return 纹理坐标属性
        virtual const VertexAttribute &get_tex_coord_attrib() const = 0;

        /// @brief 是否有法线属性
        /// @return 是否有法线属性
        virtual bool has_normal_attrib() const = 0;

        /// @brief 获取法线属性
        /// @return 法线属性
        virtual const VertexAttribute &get_normal_attrib() const = 0;
    };

} // namespace graphics
