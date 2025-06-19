#pragma once

#include "matrix_holder.hpp"

namespace graphics
{
    /// @brief 基础3D投影
    class BaseProjection3D : public MatrixHolder
    {
    public:
        /// @brief 投影类型
        enum class ProjectionType : base::Int32
        {
            /// @brief 自定义
            Custom,
            /// @brief 正交
            Ortho,
            /// @brief 平截头体
            Frustum,
            /// @brief 透视
            Perspective,
            /// @brief 全景
            Panorama,
        };

    private:
        /// @brief 近平面位置
        float m_z_near = 0.1f;
        /// @brief 远平面位置
        float m_z_far = 100.0f;

    public:
        BaseProjection3D() = default;
        BaseProjection3D(float z_near, float z_far)
            : m_z_near(z_near), m_z_far(z_far) {}
        ~BaseProjection3D() override = default;

    public:
        float get_z_near() const { return m_z_near; }
        float get_z_far() const { return m_z_far; }

        /// @brief 获取投影类型
        /// @return 投影类型
        virtual ProjectionType get_projection_type() const = 0;

    public:
        void set_z_near(float z_near)
        {
            m_z_near = z_near;
            _set_dirty(true);
        }

        void set_z_far(float z_far)
        {
            m_z_far = z_far;
            _set_dirty(true);
        }
    };

} // namespace graphics
