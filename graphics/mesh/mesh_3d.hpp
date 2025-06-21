#pragma once

#include "base_mesh.hpp"
#include "vertex_3d.hpp"

namespace graphics
{
    class Mesh3D;
    using Mesh3DRef = base::Ref<Mesh3D>;
    using Mesh3DWeakRef = base::WeakRef<Mesh3D>;

    /// @brief 3D网格
    class Mesh3D : public BaseMesh
    {
    public:
        /// @brief 位置属性
        static constexpr VertexAttribute POSITION_ATTRIB = VertexAttribute(VertexAttribute::DataType::Float, 3, 0);
        /// @brief 纹理坐标属性
        static constexpr VertexAttribute TEXCOORD_ATTRIB = VertexAttribute(VertexAttribute::DataType::Float, 2, sizeof(glm::vec3));
        /// @brief 法线属性
        static constexpr VertexAttribute NORMAL_ATTRIB = VertexAttribute(VertexAttribute::DataType::Float, 3, sizeof(glm::vec3) + sizeof(glm::vec2));

        static Mesh3DRef convert(const BaseMeshRef &mesh) { return std::dynamic_pointer_cast<Mesh3D>(mesh); }

    private:
        /// @brief 顶点
        Vertex3DArray m_vertices;

    public:
        Mesh3D() = default;
        Mesh3D(const Vertex3DArray &vertices) : m_vertices(vertices) {}
        ~Mesh3D() override = default;

    public:
        base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::Mesh3D); }
        base::Size get_raw_vertices_size() const override { return m_vertices.size() * sizeof(Vertex3D); }
        const void *get_raw_vertices() const override { return m_vertices.data(); }
        base::Size get_vertex_size() const override { return sizeof(Vertex3D); }

    public:
        const VertexAttribute &get_position_attrib() const override { return POSITION_ATTRIB; }
        const VertexAttribute &get_tex_coord_attrib() const override { return TEXCOORD_ATTRIB; }
        bool has_normal_attrib() const override { return true; }
        const VertexAttribute &get_normal_attrib() const override { return NORMAL_ATTRIB; }

    public:
        Vertex3D &get_vertex(base::Size index) { return m_vertices[index]; }
        const Vertex3D &get_vertex(base::Size index) const { return m_vertices[index]; }
        void reserve(base::Size size) { m_vertices.reserve(size); }
        void add_vertex(const Vertex3D &vertex) { m_vertices.push_back(vertex); }
        void remove_vertex(Vertex3DArray::const_iterator iter) { m_vertices.erase(iter); }
    };

} // namespace graphics
