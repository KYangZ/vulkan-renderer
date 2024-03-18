#pragma once

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace engine {

class Camera {
    public:
        Camera() = default;

        Camera(glm::vec3 c, glm::vec3 t, glm::mat4 p, glm::mat4 v) {
            cameraPosition = c;
            targetPosition = t;
            proj = p;
            view = v;
        }

        void rotateCamera(glm::vec3 rotation);
        void translateCamera(glm::vec3 translation);

        const glm::mat4& getProjectionMatrix() const { return proj; }
        const glm::mat4& getViewMatrix() const { return view; }
        const glm::vec3& getCameraPosition() const { return cameraPosition; }
        const glm::vec3& getTargetPosition() const { return targetPosition; }

    private:
        glm::vec3 cameraPosition{};
        glm::vec3 targetPosition{};
        glm::mat4 proj{1.f};
        glm::mat4 view{1.f};
};

}