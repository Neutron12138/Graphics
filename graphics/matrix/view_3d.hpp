#pragma once

#include "matrix_holder.hpp"

namespace graphics
{
    class View3D : public MatrixHolder
    {
    private:
        glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 1.0f);
        glm::vec3 m_world_up = UP;
        glm::vec3 m_target = glm::vec3(0.0f, 0.0f, 0.0f);

        glm::vec3 m_up = UP;
        glm::vec3 m_front = FRONT;
        glm::vec3 m_right = RIGHT;

    public:
        View3D() = default;
        ~View3D() override = default;

    public:
        const glm::vec3 &get_position() const { return m_position; }
        const glm::vec3 &get_world_up() const { return m_world_up; }
        const glm::vec3 &get_target() const { return m_target; }

        const glm::vec3 &get_up() const { return m_up; }
        const glm::vec3 &get_front() const { return m_front; }
        const glm::vec3 &get_right() const { return m_right; }

    protected:
        void _update_matrix() override
        {
            m_front = glm::normalize(m_target - m_position);
            m_right = glm::normalize(glm::cross(m_front, m_world_up));
            m_up = glm::normalize(glm::cross(m_right, m_front));

            glm::mat4 matrix = glm::lookAt(m_position, m_target, m_up);
            _set_matrix(matrix);
        }

    public:
        void set_position(const glm::vec3 &position)
        {
            m_position = position;
            _set_dirty(true);
        }

        void set_world_up(const glm::vec3 &world_up)
        {
            m_world_up = world_up;
            _set_dirty(true);
        }

        void set_target(const glm::vec3 &target)
        {
            m_target = target;
            _set_dirty(true);
        }

    public:
        void translate(const glm::vec3 &offset, bool not_rotate = false)
        {
            m_position += offset;
            if (not_rotate)
                m_target += offset;
            _set_dirty(true);
        }
    };

} // namespace graphics
