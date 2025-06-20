#pragma once

#include <base/base.hpp>
#include "../glm.hpp"

namespace graphics
{
    /// @brief 3D顶点
    class Vertex3D
    {
    public:
        /// @brief 位置
        glm::vec3 position;
        /// @brief 纹理坐标
        glm::vec2 tex_coord;
        /// @brief 法线
        glm::vec3 normal;

    public:
        Vertex3D() = default;
        constexpr Vertex3D(const glm::vec3 &pos, const glm::vec2 &tc = {}, const glm::vec3 &norm = {})
            : position(pos), tex_coord(tc), normal(norm) {}
        ~Vertex3D() = default;
    };

    using Vertex3DArray = std::vector<Vertex3D>;

} // namespace graphics
