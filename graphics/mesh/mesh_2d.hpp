#pragma once

#include "base_mesh.hpp"
#include "vertex_2d.hpp"

namespace graphics
{
    class Mesh2D;
    using Mesh2DRef = base::Ref<Mesh2D>;
    using Mesh2DWeakRef = base::WeakRef<Mesh2D>;

    /// @brief 2D网格
    class Mesh2D : public BaseMesh
    {
    public:
        /// @brief 位置属性
        static constexpr VertexAttribute POSITION_ATTRIB = VertexAttribute(VertexAttribute::DataType::Float, 2, 0);
        /// @brief 纹理坐标属性
        static constexpr VertexAttribute TEXCOORD_ATTRIB = VertexAttribute(VertexAttribute::DataType::Float, 2, sizeof(glm::vec2));
        /// @brief 法线属性
        static constexpr VertexAttribute NORMAL_ATTRIB = VertexAttribute(VertexAttribute::DataType::None, 0, 0);

        static Mesh2DRef convert(const BaseMeshRef &mesh) { return std::dynamic_pointer_cast<Mesh2D>(mesh); }

    private:
        /// @brief 顶点
        Vertex2DArray m_vertices;

    public:
        Mesh2D() = default;
        Mesh2D(const Vertex2DArray &vertices) : m_vertices(vertices) {}
        ~Mesh2D() override = default;

    public:
        base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::Mesh2D); }
        base::Size get_raw_vertices_size() const override { return m_vertices.size() * sizeof(Vertex2D); }
        const void *get_raw_vertices() const override { return m_vertices.data(); }
        base::Size get_vertex_size() const override { return sizeof(Vertex2D); }

    public:
        const VertexAttribute &get_position_attrib() const override { return POSITION_ATTRIB; }
        const VertexAttribute &get_tex_coord_attrib() const override { return TEXCOORD_ATTRIB; }
        bool has_normal_attrib() const override { return false; }
        const VertexAttribute &get_normal_attrib() const override { return NORMAL_ATTRIB; }

    public:
        Vertex2D &get_vertex(base::Size index) { return m_vertices[index]; }
        const Vertex2D &get_vertex(base::Size index) const { return m_vertices[index]; }
        void reserve(base::Size size) { m_vertices.reserve(size); }
        void add_vertex(const Vertex2D &vertex) { m_vertices.push_back(vertex); }
        void remove_vertex(Vertex2DArray::const_iterator iter) { m_vertices.erase(iter); }
    };

} // namespace graphics
