#version 410 core

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;
layout (location = 2) in vec2 in_uv;
layout (location = 3) in vec2 in_instance_position;
layout (location = 4) in vec2 in_instance_size;
layout (location = 5) in vec2 in_instance_uv_offset;
layout (location = 6) in vec2 in_instance_uv_scale;

uniform mat4 u_projection;
uniform mat4 u_view;

out vec2 uv;

void main() {
  uv = in_uv * in_instance_uv_scale + in_instance_uv_offset;
  gl_Position = u_projection * u_view * vec4(in_position.xy * in_instance_size + in_instance_position, in_position.z, 1.0);
}
