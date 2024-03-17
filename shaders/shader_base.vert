#version 450

struct PointLight {
    vec3 lightPosition;
    vec4 lightColor;
};

layout(binding = 0) uniform UniformBufferObject {
    mat4 model;
    mat4 view;
    mat4 proj;
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

// const vec3 LIGHT_DIRECTION = normalize(vec3(0.5, 0.5, 1.0));
// const float AMBIENT_LIGHT = 0.02;

void main() {
    vec4 worldPosition = (ubo.model * vec4(inPosition * instanceScale, 1.0f)) + vec4(instancePos, 0.0f);
    gl_Position = ubo.proj * ubo.view * worldPosition;

    // if the normals are 0, there are no normals in the obj file. skip the lighting calculation.
    if (length(normal) == 0.0f) {
        fragColor = inColor;
        fragTexCoord = inTexCoord;
        return;
    }

    vec3 normalWorldSpace = normalize((ubo.model * vec4(normal, 0.0)).xyz);

    // start with ambient light
    vec3 totalLight = ubo.ambientLightColor.xyz * ubo.ambientLightColor.w;

    for (int i = 0; i < ubo.numLights; i++) {
        PointLight l = ubo.pointLights[i];

        vec3 lightDirection = l.lightPosition - worldPosition.xyz;
        float attenuation = 1.0 / dot(lightDirection, lightDirection);
        vec3 lightColor = attenuation * l.lightColor.xyz * l.lightColor.w;
        totalLight += lightColor * max(dot(normalWorldSpace, normalize(lightDirection)), 0);
    }

    fragColor = totalLight * inColor;
    fragTexCoord = inTexCoord;
}