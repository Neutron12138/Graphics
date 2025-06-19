#pragma once

#include "visual.hpp"
#include "../matrix/transform_3d_euler.hpp"

namespace graphics
{
    /// @brief 使用欧拉角的3D可视对象
    class Visual3DEuler : public Visual,
                          public Transform3DEuler
    {
    public:
        Visual3DEuler() = default;
        ~Visual3DEuler() override = default;
    };

} // namespace graphics
