#pragma once

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace engine {

class Camera {
    public:
        Camera() = default;

        Camera(glm::vec3 pos, glm::mat4 p, glm::mat4 v) {
            position = pos;
            proj = p;
            view = v;
        }

        void rotateCamera(glm::vec3 rotation);
        void translateCamera(glm::vec3 translation);

        const glm::mat4& getProjectionMatrix() const { return proj; }
        const glm::mat4& getViewMatrix() const { return view; }
        const glm::vec3& getPosition() const { return position; }

    private:
        glm::vec3 position{};
        glm::mat4 proj{1.f};
        glm::mat4 view{1.f};
};

}