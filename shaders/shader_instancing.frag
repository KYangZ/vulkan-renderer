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

layout(binding = 1) uniform sampler2D texSampler;

layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec2 fragTexCoord;
layout(location = 2) in vec3 fragWorldPos;
layout(location = 3) in vec3 fragWorldNormal;

layout(location = 0) out vec4 outColor;

void main() {
    outColor = vec4(fragColor, 1.0) * texture(texSampler, fragTexCoord);
}

