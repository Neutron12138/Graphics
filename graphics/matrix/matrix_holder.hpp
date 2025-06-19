#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include <base/base.hpp>
#include "../glm.hpp"

namespace graphics
{
    /// @brief 矩阵持有者
    class MatrixHolder : virtual public base::PolymorphicObject
    {
    private:
        /// @brief 矩阵
        glm::mat4 m_matrix = glm::mat4(1.0f);
        /// @brief 矩阵是否过期
        bool m_is_dirty = false;

    public:
        MatrixHolder() = default;
        ~MatrixHolder() override = default;

    public:
        bool is_dirty() const { return m_is_dirty; }
        const glm::mat4 &get_matrix() const { return m_matrix; }

        const glm::mat4 &update_and_get_matrix()
        {
            if (m_is_dirty)
            {
                _update_matrix();
                m_is_dirty = false;
            }
            return m_matrix;
        }

    protected:
        void _set_matrix(const glm::mat4 &matrix) { m_matrix = matrix; }
        void _set_dirty(bool is_dirty) { m_is_dirty = is_dirty; }

        /// @brief 更新矩阵
        virtual void _update_matrix() = 0;

    public:
        /// @brief 请求更新矩阵
        void request_update()
        {
            if (!m_is_dirty)
                return;

            _update_matrix();
            m_is_dirty = false;
        }
    };

} // namespace graphics
