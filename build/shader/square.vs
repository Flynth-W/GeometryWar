#version 330 core
layout (location = 0) in vec3 positions;
layout (location = 1) in vec3 colors;

out vec3 Colors;


void main()
{
  gl_Position = vec4(positions, 1.0);
  Colors=colors;
}

