#!/bin/bash

mkdir -p build/shaders/
/Users/koryyang/VulkanSDK/1.3.275.0/macOS/bin/glslc ./shaders/shader_base.vert -o ./build/shaders/vert.spv
/Users/koryyang/VulkanSDK/1.3.275.0/macOS/bin/glslc ./shaders/shader_base.frag -o ./build/shaders/frag.spv