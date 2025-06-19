#pragma once

#include "base_transform_3d.hpp"

namespace graphics
{
    /// @brief 使用欧拉角的3D变换
    class Transform3DEuler : public BaseTransform3D
    {
    public:
        /// @brief 欧拉角旋转顺序
        enum class RotationOrder : base::Int32
        {
            XYZ,
            XZY,
            YXZ,
            YZX,
            ZXY,
            ZYX,
        };

        static glm::mat4 rotate_x(const glm::mat4 &matrix, float angle) { return glm::rotate(matrix, angle, AXIS_X); }
        static glm::mat4 rotate_y(const glm::mat4 &matrix, float angle) { return glm::rotate(matrix, angle, AXIS_Y); }
        static glm::mat4 rotate_z(const glm::mat4 &matrix, float angle) { return glm::rotate(matrix, angle, AXIS_Z); }

    private:
        /// @brief 旋转顺序
        RotationOrder m_rotation_order = RotationOrder::XYZ;
        /// @brief 旋转
        glm::vec3 m_rotation = glm::vec3(0.0f);

    public:
        Transform3DEuler() = default;
        Transform3DEuler(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale)
            : BaseTransform3D(position, scale), m_rotation(rotation) { _update_matrix(); }
        ~Transform3DEuler() override = default;

    public:
        RotationOrder get_rotation_order() const { return m_rotation_order; }
        const glm::vec3 &get_rotation() const { return m_rotation; }

    protected:
        void _update_matrix() override
        {
            glm::mat4 matrix = glm::mat4(1.0f);
            matrix = glm::translate(matrix, get_position());
            matrix = glm::translate(matrix, get_origin());

            switch (m_rotation_order)
            {
            case RotationOrder::XYZ:
                matrix = rotate_z(matrix, m_rotation.z);
                matrix = rotate_y(matrix, m_rotation.y);
                matrix = rotate_x(matrix, m_rotation.x);
                break;

            case RotationOrder::XZY:
                matrix = rotate_y(matrix, m_rotation.y);
                matrix = rotate_z(matrix, m_rotation.z);
                matrix = rotate_x(matrix, m_rotation.x);
                break;

            case RotationOrder::YXZ:
                matrix = rotate_z(matrix, m_rotation.z);
                matrix = rotate_x(matrix, m_rotation.x);
                matrix = rotate_y(matrix, m_rotation.y);
                break;

            case RotationOrder::YZX:
                matrix = rotate_x(matrix, m_rotation.x);
                matrix = rotate_z(matrix, m_rotation.z);
                matrix = rotate_y(matrix, m_rotation.y);
                break;

            case RotationOrder::ZXY:
                matrix = rotate_y(matrix, m_rotation.y);
                matrix = rotate_x(matrix, m_rotation.x);
                matrix = rotate_z(matrix, m_rotation.z);
                break;

            case RotationOrder::ZYX:
                matrix = rotate_x(matrix, m_rotation.x);
                matrix = rotate_y(matrix, m_rotation.y);
                matrix = rotate_z(matrix, m_rotation.z);
                break;
            }

            matrix = glm::scale(matrix, get_scale());
            matrix = glm::translate(matrix, -get_origin());
            _set_matrix(matrix);
        }

    public:
        void set_rotation_order(RotationOrder rotation_order)
        {
            m_rotation_order = rotation_order;
            _set_dirty(true);
        }

        void set_rotation(const glm::vec3 &rotation)
        {
            m_rotation = rotation;
            _set_dirty(true);
        }

    public:
        void rotate(const glm::vec3 &rotation)
        {
            m_rotation += rotation;
            _set_dirty(true);
        }

        void rotate_x(float angle)
        {
            m_rotation.x += angle;
            _set_dirty(true);
        }

        void rotate_y(float angle)
        {
            m_rotation.y += angle;
            _set_dirty(true);
        }

        void rotate_z(float angle)
        {
            m_rotation.z += angle;
            _set_dirty(true);
        }
    };

} // namespace graphics
