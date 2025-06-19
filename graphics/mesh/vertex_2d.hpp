#pragma once

#include <base/base.hpp>
#include "../glm.hpp"

namespace graphics
{
    /// @brief 2D顶点
    class Vertex2D : public base::CompactObject
    {
    public:
        /// @brief 位置
        glm::vec2 position = glm::vec2(0.0f);
        /// @brief 纹理坐标
        glm::vec2 tex_coord = glm::vec2(0.0f);

    public:
        Vertex2D() = default;
        Vertex2D(const glm::vec2 &pos, const glm::vec2 &uv)
            : position(pos), tex_coord(uv) {}
        ~Vertex2D() = default;
    };

} // namespace graphics
