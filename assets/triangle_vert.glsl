#version 410 core

layout (location = 1) in vec2 in_uv;
layout (location = 2) in vec3 in_instance_position_0;
layout (location = 3) in vec3 in_instance_position_1;
layout (location = 4) in vec3 in_instance_position_2;
layout (location = 5) in vec3 in_instance_color;

uniform mat4 u_projection;
uniform mat4 u_view;

out vec2 uv;
out vec3 color;
flat out vec3 normal;

void main() {
  uv = in_uv;
  color = in_instance_color;
  normal = normalize(cross(in_instance_position_1 - in_instance_position_0, in_instance_position_2 - in_instance_position_0));

  vec3 positions[3] = vec3[3](in_instance_position_0, in_instance_position_1, in_instance_position_2);
  gl_Position = u_projection * u_view * vec4(positions[gl_VertexID], 1.0);
}
