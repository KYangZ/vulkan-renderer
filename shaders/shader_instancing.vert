#version 450

struct PointLight {
    vec3 lightPosition;
    vec4 lightColor;
};

layout(binding = 0) uniform UniformBufferObject {
    mat4 model;
    mat4 view;
    mat4 proj;
    vec3 cameraPos;
    vec4 ambientLightColor;
    PointLight pointLights[8];
    int numLights;
} ubo;

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec3 normal;
layout(location = 3) in vec2 inTexCoord;

// Instanced attributes
layout (location = 4) in vec3 instancePos;
layout (location = 5) in vec3 instanceRot;
layout (location = 6) in float instanceScale;

layout(location = 0) out vec3 fragColor;
layout(location = 1) out vec2 fragTexCoord;
layout(location = 2) out vec3 fragWorldPos;
layout(location = 3) out vec3 fragWorldNormal;

const vec3 LIGHT_DIRECTION = normalize(vec3(-0.5, 0.0, 1.0));
const float AMBIENT_LIGHT = 0.3;

void main() {
    gl_Position = ubo.proj * ubo.view * ubo.model * vec4(inPosition * instanceScale + instancePos, 1.0);

    vec3 normalWorldSpace = normalize((ubo.view * ubo.model * vec4(normal, 0.0)).xyz);
    float lightIntensity = AMBIENT_LIGHT + max(dot(normalWorldSpace, LIGHT_DIRECTION), 0);

    fragColor = lightIntensity * vec3(0.15 * instanceRot[0], 0.5 * instanceRot[1], 1.0);
    fragTexCoord = inTexCoord;
    return;
}