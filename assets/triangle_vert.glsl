#version 410 core

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec2 in_uv;
layout (location = 2) in vec3 in_color;

uniform mat4 u_projection;
uniform mat4 u_view;

out vec2 uv;
out vec3 color;

void main() {
  uv = in_uv;
  color = in_color;
  gl_Position = u_projection * u_view * vec4(in_position, 1.0);
}
