#version 410 core

in vec2 uv;
in vec3 color;
flat in vec3 normal;

uniform sampler2D u_texture;
uniform vec3 u_sun_direction;
uniform vec3 u_sun_color;
uniform vec3 u_ambient;

out vec4 frag_color;

void main() {
  vec4 texel = texture(u_texture, uv);
  float diffuse = max(dot(normal, u_sun_direction), 0.0);
  vec3 light = u_ambient + u_sun_color * diffuse;

  frag_color = vec4(texel.rgb * color * light, texel.a);
}
