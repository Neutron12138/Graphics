#pragma once

#include "matrix_holder.hpp"

namespace graphics
{
    /// @brief 2D视图
    class View2D : public MatrixHolder
    {
    private:
        /// @brief 位置
        glm::vec2 m_position = glm::vec2(0.0f);
        /// @brief 旋转
        float m_rotation = 0.0f;
        /// @brief 缩放
        glm::vec2 m_zoom = glm::vec2(1.0f);

    public:
        View2D() = default;
        View2D(const glm::vec2 &position, float rotation = 0.0f, const glm::vec2 &zoom = glm::vec2(1.0f))
            : m_position(position), m_rotation(rotation), m_zoom(zoom) { _update_matrix(); }
        ~View2D() override = default;

    public:
        const glm::vec2 &get_position() const { return m_position; }
        float get_rotation() const { return m_rotation; }
        const glm::vec2 &get_zoom() const { return m_zoom; }

    protected:
        void _update_matrix() override
        {
            glm::mat4 matrix = glm::mat4(1.0f);
            matrix = glm::scale(matrix, glm::vec3(1.0f / m_zoom, 1.0f));
            matrix = glm::rotate(matrix, m_rotation, AXIS_Z);
            matrix = glm::translate(matrix, glm::vec3(-m_position, 0.0f));
            _set_matrix(matrix);
        }

    public:
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

        void set_zoom(const glm::vec2 &zoom)
        {
            m_zoom = zoom;
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
    };

} // namespace graphics
