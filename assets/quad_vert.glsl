#version 410 core

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec2 in_uv;
layout (location = 2) in vec2 in_instance_position;
layout (location = 3) in vec2 in_instance_size;
layout (location = 4) in vec3 in_instance_color;

uniform mat4 u_projection;

out vec2 uv;
out vec3 color;

void main() {
  uv = in_uv;
  color = in_instance_color;
  gl_Position = u_projection * vec4(in_position.xy * in_instance_size + in_instance_position, 0.0, 1.0);
}
