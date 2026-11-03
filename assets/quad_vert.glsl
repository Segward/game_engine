#version 410 core

layout (location = 0) in vec3 in_position;
layout (location = 2) in vec2 in_instance_position;
layout (location = 3) in vec2 in_instance_size;
layout (location = 4) in vec2 in_instance_uv_0;
layout (location = 5) in vec2 in_instance_uv_1;
layout (location = 6) in vec2 in_instance_uv_2;
layout (location = 7) in vec2 in_instance_uv_3;
layout (location = 8) in vec3 in_instance_color;

uniform mat4 u_projection;

out vec2 uv;
out vec3 color;

void main() {
  vec2 uvs[4] = vec2[4](in_instance_uv_0, in_instance_uv_1, in_instance_uv_2, in_instance_uv_3);
  uv = uvs[gl_VertexID];
  color = in_instance_color;

  gl_Position = u_projection * vec4(in_position.xy * in_instance_size + in_instance_position, 0.0, 1.0);
}
