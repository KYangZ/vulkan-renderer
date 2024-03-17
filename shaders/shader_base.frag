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

layout(binding = 1) uniform sampler2D texSampler;

layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec2 fragTexCoord;
layout(location = 2) in vec3 fragWorldPos;
layout(location = 3) in vec3 fragWorldNormal;

layout(location = 0) out vec4 outColor;

void main() {
    // start with ambient light
    vec3 totalLight = ubo.ambientLightColor.xyz * ubo.ambientLightColor.w;

    for (int i = 0; i < ubo.numLights; i++) {
        PointLight l = ubo.pointLights[i];

        vec3 lightDirection = l.lightPosition - fragWorldPos;
        float attenuation = 1.0 / dot(lightDirection, lightDirection);
        vec3 lightColor = attenuation * l.lightColor.xyz * l.lightColor.w;
        totalLight += lightColor * max(dot(normalize(fragWorldNormal), normalize(lightDirection)), 0);
    }

    outColor = vec4(totalLight * fragColor, 1.0) * texture(texSampler, fragTexCoord);
}

