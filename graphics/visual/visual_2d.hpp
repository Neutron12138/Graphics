#pragma once

#include "visual.hpp"
#include "../matrix/transform_2d.hpp"

namespace graphics
{
    /// @brief 2D可视对象
    class Visual2D : public Visual,
                     public Transform2D
    {
    public:
        Visual2D() = default;
        ~Visual2D() override = default;
    };

} // namespace graphics
