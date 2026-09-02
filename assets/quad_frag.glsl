#version 410 core

in vec2 uv;

uniform sampler2D u_texture;

out vec4 frag_color;

void main() {
  vec4 color = texture(u_texture, uv);
  if (color.a < 0.01) discard;

  frag_color = color;
}
