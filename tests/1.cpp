#include <iostream>
#include "../graphics/graphics.hpp"

int main()
{
    constexpr graphics::Vertex2D v1({}, {});
    constexpr graphics::Vertex3D v2({}, {}, {});

    std::cout << (sizeof(graphics::Vertex2D) == 2 * sizeof(glm::vec2)) << std::endl
              << std::is_trivial_v<graphics::Vertex2D> << std::endl
              << (sizeof(graphics::Vertex3D) == 2 * sizeof(glm::vec3) + sizeof(glm::vec2)) << std::endl
              << std::is_trivial_v<graphics::Vertex3D> << std::endl
              << std::endl;

    constexpr graphics::VertexAttribute va(graphics::VertexAttribute::DataType::Float, 3, 0);
    std::cout << std::is_trivial_v<graphics::VertexAttribute> << std::endl
              << (va.get_data_size() == sizeof(GLfloat)) << std::endl
              << (va.get_total_size() == 3 * sizeof(GLfloat)) << std::endl
              << (va.get_offset_pointer() == nullptr) << std::endl
              << std::endl;

    graphics::Mesh2D mesh1 = graphics::Vertex2DArray{
        graphics::Vertex2D(),
    };
    graphics::Mesh3D mesh2 = graphics::Vertex3DArray{
        graphics::Vertex3D(),
    };

    return 0;
}
