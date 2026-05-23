#version 410 core

layout(location = 0) in vec3 in_position;

uniform vec2 u_position;
uniform vec2 u_size;

void main() {
  gl_Position = vec4(in_position.xy * u_size + u_position, 0.0, 1.0);
}
