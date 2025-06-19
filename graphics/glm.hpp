#pragma once

#include <glm/glm.hpp>

namespace graphics
{
    /// @brief X轴
    static constexpr glm::vec3 AXIS_X = glm::vec3(1.0f, 0.0f, 0.0f);
    /// @brief Y轴
    static constexpr glm::vec3 AXIS_Y = glm::vec3(0.0f, 1.0f, 0.0f);
    /// @brief Z轴
    static constexpr glm::vec3 AXIS_Z = glm::vec3(0.0f, 0.0f, 1.0f);

    /// @brief 正X轴
    static constexpr glm::vec3 POSITIVE_X = AXIS_X;
    /// @brief 负X轴
    static constexpr glm::vec3 NEGATIVE_X = -POSITIVE_X;
    /// @brief 正Y轴
    static constexpr glm::vec3 POSITIVE_Y = AXIS_Y;
    /// @brief 负Y轴
    static constexpr glm::vec3 NEGATIVE_Y = -POSITIVE_Y;
    /// @brief 正Z轴
    static constexpr glm::vec3 POSITIVE_Z = AXIS_Z;
    /// @brief 负Z轴
    static constexpr glm::vec3 NEGATIVE_Z = -POSITIVE_Z;

    /// @brief 左方向
    static constexpr glm::vec3 LEFT = NEGATIVE_X;
    /// @brief 右方向
    static constexpr glm::vec3 RIGHT = POSITIVE_X;
    /// @brief 上方向
    static constexpr glm::vec3 UP = POSITIVE_Y;
    /// @brief 下方向
    static constexpr glm::vec3 DOWN = NEGATIVE_Y;
    /// @brief 前方向
    static constexpr glm::vec3 FRONT = NEGATIVE_Z;
    /// @brief 后方向
    static constexpr glm::vec3 BACK = POSITIVE_Z;

} // namespace graphics
