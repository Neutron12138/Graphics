#pragma once

#include "base_projection_3d.hpp"

namespace graphics
{
    /// @brief 3D投影
    class Projection3D : public BaseProjection3D
    {
    private:
        /// @brief 投影类型
        ProjectionType m_projection_type = ProjectionType::Perspective;
        /// @brief 视野
        float m_fov = 75.0f;
        /// @brief 比例
        float m_aspect = 1.0f;
        /// @brief 左
        float m_left = -1.0f;
        /// @brief 右
        float m_right = 1.0f;
        /// @brief 下
        float m_bottom = -1.0f;
        /// @brief 上
        float m_top = 1.0f;

    public:
        Projection3D() = default;
        Projection3D(float fov, float aspect, float z_near = 0.1f, float z_far = 100.0f)
            : BaseProjection3D(z_near, z_far), m_fov(fov), m_aspect(aspect) { _update_matrix(); }
        ~Projection3D() override = default;

    public:
        float get_fov() const { return m_fov; }
        float get_aspect() const { return m_aspect; }
        float get_left() const { return m_left; }
        float get_right() const { return m_right; }
        float get_bottom() const { return m_bottom; }
        float get_top() const { return m_top; }

        ProjectionType get_projection_type() const override { return m_projection_type; }

    protected:
        void _update_matrix() override
        {
            glm::mat4 matrix = glm::mat4(1.0f);

            switch (m_projection_type)
            {
            case ProjectionType::Ortho:
                matrix = glm::ortho(m_left, m_right, m_bottom, m_top, get_z_near(), get_z_far());
                break;

            case ProjectionType::Frustum:
                matrix = glm::frustum(m_left, m_right, m_bottom, m_top, get_z_near(), get_z_far());
                break;

            case ProjectionType::Perspective:
                matrix = glm::perspective(m_fov, m_aspect, get_z_near(), get_z_far());
                break;
            }

            _set_matrix(matrix);
        };

    public:
        void set_projection_type(ProjectionType projection_type)
        {
            m_projection_type = projection_type;
            _set_dirty(true);
        }

        void set_ortho(float left, float right, float bottom, float top)
        {
            m_left = left;
            m_right = right;
            m_bottom = bottom;
            m_top = top;
            m_projection_type = ProjectionType::Ortho;
            _set_dirty(true);
        }

        void set_frustum(float left, float right, float bottom, float top)
        {
            m_left = left;
            m_right = right;
            m_bottom = bottom;
            m_top = top;
            m_projection_type = ProjectionType::Frustum;
            _set_dirty(true);
        }

        void set_perspective(float fov, float aspect)
        {
            m_fov = fov;
            m_aspect = aspect;
            m_projection_type = ProjectionType::Perspective;
            _set_dirty(true);
        }

    public:
        void set_fov(float fov)
        {
            m_fov = fov;
            _set_dirty(true);
        }

        void set_aspect(float aspect)
        {
            m_aspect = aspect;
            _set_dirty(true);
        }

        void set_left(float left)
        {
            m_left = left;
            _set_dirty(true);
        }

        void set_right(float right)
        {
            m_right = right;
            _set_dirty(true);
        }

        void set_bottom(float bottom)
        {
            m_bottom = bottom;
            _set_dirty(true);
        }

        void set_top(float top)
        {
            m_top = top;
            _set_dirty(true);
        }
    };

} // namespace graphics
