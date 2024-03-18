#include "camera.hpp"

namespace engine {

void Camera::rotateCamera(glm::vec3 rotation) {
    view = glm::rotate(view, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    view = glm::rotate(view, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    view = glm::rotate(view, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
}

void Camera::translateCamera(glm::vec3 translation) {
    view = glm::translate(view, glm::vec3(translation.x, translation.y, translation.z));
    position += translation;
}
    
} 