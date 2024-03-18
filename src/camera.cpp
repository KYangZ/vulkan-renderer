#include "camera.hpp"

namespace engine {

void Camera::rotateCamera(glm::vec3 rotation) {
    // Calculate the current forward and right vectors
    glm::vec3 forward = normalize(targetPosition - cameraPosition);
    glm::vec3 right = cross(forward, glm::vec3(0.0f, 0.0f, 1.0f));
    glm::vec3 up = cross(right, forward);

    // Rotate the forward vector
    glm::mat4 rotationMat = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    rotationMat = glm::rotate(rotationMat, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotationMat = glm::rotate(rotationMat, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    forward = glm::vec3(rotationMat * glm::vec4(forward, 0.0f));

    // Update the target position based on the new forward vector
    targetPosition = cameraPosition + forward;

    // Update the view matrix
    view = glm::lookAt(cameraPosition, targetPosition, up);
}

void Camera::translateCamera(glm::vec3 translation) {
    glm::vec3 forward = normalize(targetPosition - cameraPosition);
    glm::vec3 right = cross(forward, glm::vec3(0.0f, 0.0f, 1.0f));
    glm::vec3 up = cross(right, forward);

    // Apply translation to the camera position
    cameraPosition += translation;

    // Update the target position based on the new camera position
    targetPosition = cameraPosition + forward;

    // Update the view matrix
    view = glm::lookAt(cameraPosition, targetPosition, up);
}
    
} 