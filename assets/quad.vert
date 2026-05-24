#version 410 core

layout(location = 0) in vec3 in_position;

uniform vec2 u_position;
uniform vec2 u_size;
uniform vec2 u_rotation;
uniform vec2 u_window_size;

void main() {
  vec2 local = in_position.xy * u_size;
  vec2 rotated = vec2(
    local.x * u_rotation.x - local.y * u_rotation.y,
    local.x * u_rotation.y + local.y * u_rotation.x);
  vec2 pixel = rotated + u_position;
  vec2 ndc = pixel * 2.0 / u_window_size;
  gl_Position = vec4(ndc, 0.0, 1.0);
}
