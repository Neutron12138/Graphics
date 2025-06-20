#pragma once

#include "matrix_holder.hpp"

namespace graphics
{
    /// @brief 2D变换
    class Transform2D : public MatrixHolder
    {
    private:
        /// @brief 变换原点
        glm::vec2 m_origin = glm::vec2(0.0f);
        /// @brief 位置
        glm::vec2 m_position = glm::vec2(0.0f);
        /// @brief 旋转
        float m_rotation = 0.0;
        /// @brief 缩放
        glm::vec2 m_scale = glm::vec2(1.0f);

    public:
        Transform2D() = default;
        Transform2D(const glm::vec2 &position, float rotation = 0.0f, const glm::vec2 &scale = glm::vec2(1.0f))
            : m_position(position), m_rotation(rotation), m_scale(scale) { _update_matrix(); }
        ~Transform2D() override = default;

    public:
        const glm::vec2 &get_origin() const { return m_origin; }
        const glm::vec2 &get_position() const { return m_position; }
        float get_rotation() const { return m_rotation; }
        const glm::vec2 &get_scale() const { return m_scale; }

    protected:
        void _update_matrix() override
        {
            glm::mat4 matrix = glm::mat4(1.0f);
            matrix = glm::translate(matrix, glm::vec3(m_position, 0.0f));
            matrix = glm::translate(matrix, glm::vec3(m_origin, 0.0f));
            matrix = glm::rotate(matrix, m_rotation, AXIS_Z);
            matrix = glm::scale(matrix, glm::vec3(m_scale, 1.0f));
            matrix = glm::translate(matrix, glm::vec3(-m_origin, 0.0f));
            _set_matrix(matrix);
        }

    public:
        void set_origin(const glm::vec2 &origin)
        {
            m_origin = origin;
            _set_dirty(true);
        }

        void set_position(const glm::vec2 &position)
        {
            m_position = position;
            _set_dirty(true);
        }

        void set_rotation(float rotation)
        {
            m_rotation = rotation;
            _set_dirty(true);
        }

        void set_scale(const glm::vec2 &scale)
        {
            m_scale = scale;
            _set_dirty(true);
        }

    public:
        void translate(const glm::vec2 &offset)
        {
            m_position += offset;
            _set_dirty(true);
        }

        void rotate(float radians)
        {
            m_rotation += radians;
            _set_dirty(true);
        }

        void apply_scale(const glm::vec2 &ratio)
        {
            m_scale *= ratio;
            _set_dirty(true);
        }
    };

} // namespace graphics
