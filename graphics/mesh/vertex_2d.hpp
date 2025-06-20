#pragma once

#include <base/base.hpp>
#include "../glm.hpp"

namespace graphics
{
    /// @brief 2D顶点
    class Vertex2D
    {
    public:
        /// @brief 位置
        glm::vec2 position;
        /// @brief 纹理坐标
        glm::vec2 tex_coord;

    public:
        Vertex2D() = default;
        constexpr Vertex2D(const glm::vec2 &pos, const glm::vec2 &tc = {})
            : position(pos), tex_coord(tc) {}
        ~Vertex2D() = default;
    };

    using Vertex2DArray = std::vector<Vertex2D>;

} // namespace graphics
