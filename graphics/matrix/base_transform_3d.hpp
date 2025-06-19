#pragma once

#include "matrix_holder.hpp"

namespace graphics
{
    /// @brief 基础3D变换
    class BaseTransform3D : public MatrixHolder
    {
    private:
        /// @brief 变换原点
        glm::vec3 m_origin = glm::vec3(0.0f);
        /// @brief 位置
        glm::vec3 m_position = glm::vec3(0.0f);
        /// @brief 缩放
        glm::vec3 m_scale = glm::vec3(1.0f);

    public:
        BaseTransform3D() = default;
        BaseTransform3D(const glm::vec3 &position, const glm::vec3 &scale = glm::vec3(1.0f))
            : m_position(position), m_scale(scale) {}
        ~BaseTransform3D() override = default;

    public:
        const glm::vec3 &get_origin() const { return m_origin; }
        const glm::vec3 &get_position() const { return m_position; }
        const glm::vec3 &get_scale() const { return m_scale; }

    public:
        void set_origin(const glm::vec3 &origin)
        {
            m_origin = origin;
            _set_dirty(true);
        }

        void set_position(const glm::vec3 &position)
        {
            m_position = position;
            _set_dirty(true);
        }

        void set_scale(const glm::vec3 &scale)
        {
            m_scale = scale;
            _set_dirty(true);
        }

    public:
        void translate(const glm::vec3 &offset)
        {
            m_position += offset;
            _set_dirty(true);
        }

        void apply_scale(const glm::vec3 &ratio)
        {
            m_scale *= ratio;
            _set_dirty(true);
        }
    };

} // namespace graphics
