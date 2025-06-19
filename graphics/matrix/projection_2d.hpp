#pragma once

#include "matrix_holder.hpp"

namespace graphics
{
    /// @brief 2D投影
    class Projection2D : public MatrixHolder
    {
    private:
        /// @brief 屏幕宽度
        float m_width = 1.0f;
        /// @brief 屏幕高度
        float m_height = 1.0f;

    public:
        Projection2D() = default;
        Projection2D(float width, float height)
            : m_width(width), m_height(height) { _update_matrix(); }
        ~Projection2D() override = default;

    public:
        float get_width() const { return m_width; }
        float get_height() const { return m_height; }

    protected:
        void _update_matrix() override
        {
            glm::mat4 matrix = glm::ortho(0.0f, m_width, m_height, 0.0f, -1.0f, 1.0f);
            _set_matrix(matrix);
        }

    public:
        void set_width(float width)
        {
            m_width = width;
            _set_dirty(true);
        }

        void set_height(float height)
        {
            m_height = height;
            _set_dirty(true);
        }
    };

} // namespace graphics
