#pragma once

#include <base/base.hpp>

namespace graphics
{
    /// @brief 可视对象
    class Visual : virtual public base::PolymorphicObject
    {
    private:
        /// @brief 是否可见
        bool m_is_visible = true;

    public:
        Visual() = default;
        ~Visual() override = default;

    protected:
        /// @brief 当可见性改变时
        /// @param before 之前是否可见
        virtual void _on_visibility_changed(bool before) = 0;

    public:
        bool is_visible() const { return m_is_visible; }

    protected:
        /// @brief 直接设置可见性
        /// @param is_visible 是否可见
        void _set_visibility(bool is_visible) { m_is_visible = is_visible; }

        /// @brief 渲染
        virtual void _render() = 0;

    public:
        /// @brief 使自身显示（可见）
        void show()
        {
            if (m_is_visible)
                return;

            m_is_visible = true;
            _on_visibility_changed(false);
        }

        /// @brief 使自身隐藏（不可见）
        void hide()
        {
            if (!m_is_visible)
                return;

            m_is_visible = false;
            _on_visibility_changed(true);
        }

        /// @brief 请求进行渲染
        virtual void request_render()
        {
            if (m_is_visible)
                _render();
        }
    };

} // namespace graphics
