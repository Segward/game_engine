#version 410 core

layout(location = 0) in vec2 position;

uniform vec2 offset;
uniform vec2 scale;
uniform mat4 view_projection;

void main() {
  vec2 world = position * scale + offset;
  gl_Position = view_projection * vec4(world, 0.0, 1.0);
}
