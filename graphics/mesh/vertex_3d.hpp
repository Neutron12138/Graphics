#pragma once

#include <base/base.hpp>
#include "../glm.hpp"

namespace graphics
{
    /// @brief 3D顶点
    class Vertex3D : public base::CompactObject
    {
    public:
        /// @brief 位置
        glm::vec3 position = glm::vec3(0.0f);
        /// @brief 纹理坐标
        glm::vec2 tex_coord = glm::vec2(0.0f);
        /// @brief 法线
        glm::vec3 normal = glm::vec3(0.0f);

    public:
        Vertex3D() = default;
        Vertex3D(const glm::vec3 &pos, const glm::vec2 &uv, const glm::vec3 &norm)
            : position(pos), tex_coord(uv), normal(norm) {}
        ~Vertex3D() = default;
    };

} // namespace graphics
