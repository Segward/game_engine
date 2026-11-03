#version 410 core

in vec2 uv;
in vec3 color;

uniform sampler2D u_texture;

out vec4 frag_color;

void main() {
  vec4 texel = texture(u_texture, uv);
  frag_color = vec4(texel.rgb * color, texel.a);
}
