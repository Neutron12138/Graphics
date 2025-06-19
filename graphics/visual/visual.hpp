#pragma once

#include <base/base.hpp>

namespace graphics
{
    class Visual;
    using VisualRef = base::Ref<Visual>;
    using VisualWeakRef = base::WeakRef<Visual>;

    /// @brief 可视对象
    class Visual : public base::PolymorphicObject
    {
    public:
        /// @brief 渲染模式
        enum class RenderMode
        {
            /// @brief 标准
            Standard,
            /// @brief 回退
            Fallback,
        };

    public:
        Visual() = default;
        ~Visual() override = default;

    protected:
        /// @brief 渲染
        virtual void _render() = 0;

    public:
        /// @brief 请求进行渲染
        virtual void request_render() { _render(); }
    };

} // namespace graphics
