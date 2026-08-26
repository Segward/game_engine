#version 410 core

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;
layout (location = 2) in vec2 in_uv;

uniform vec2 u_position;
uniform vec2 u_size;
uniform vec2 u_uv_offset;
uniform vec2 u_uv_scale;
uniform mat4 u_projection;

out vec2 uv;

void main() {
  uv = in_uv * u_uv_scale + u_uv_offset;
  gl_Position = u_projection * vec4(in_position.xy * u_size + u_position, 0.0, 1.0);
}
