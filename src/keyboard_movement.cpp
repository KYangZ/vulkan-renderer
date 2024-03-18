#include "keyboard_movement.hpp"

namespace engine {

void KeyboardMovementController::moveInXZPLane(GLFWwindow* window, float dt, Camera& c) {

    glm::vec3 forward = normalize(c.getTargetPosition() - c.getCameraPosition());
    glm::vec3 right = cross(forward, glm::vec3(0.0f, 0.0f, 1.0f));
    glm::vec3 up = cross(right, forward);

    glm::vec3 rotation{0};
    if (glfwGetKey(window, keys.lookRight) == GLFW_PRESS) {
        rotation.z -= 1.0f;
    }

    if (glfwGetKey(window, keys.lookLeft) == GLFW_PRESS) {
        rotation.z += 1.0f;
    }

    if (glfwGetKey(window, keys.lookUp) == GLFW_PRESS) {
        rotation += right;
    }

    if (glfwGetKey(window, keys.lookDown) == GLFW_PRESS) {
        rotation -= right;
    }

    if (glm::dot(rotation, rotation) > std::numeric_limits<float>::epsilon()) {
        c.rotateCamera(lookSpeed * dt * glm::normalize(rotation));
    }

    glm::vec3 translation{0};

    if (glfwGetKey(window, keys.moveRight) == GLFW_PRESS) {
        translation += right;
    }

    if (glfwGetKey(window, keys.moveLeft) == GLFW_PRESS) {
        translation -= right;
    }

    if (glfwGetKey(window, keys.moveForward) == GLFW_PRESS) {
        translation += forward;
    }

    if (glfwGetKey(window, keys.moveBackward) == GLFW_PRESS) {
        translation -= forward;
    }


    if (glm::dot(translation, translation) > std::numeric_limits<float>::epsilon()) {
        c.translateCamera(moveSpeed * dt * glm::normalize(translation));
    }
}

}