#version 330 core
layout (location = 0) out vec3 gPosition;
layout (location = 1) out vec3 gNormal;
layout (location = 2) out vec4 gColorSpec;

in vec3 fragPos;
in vec3 fragNor;
in vec2 vTex;

uniform vec3 MatAmb;
uniform vec3 MatDif;
uniform sampler2D Texture0;

void main()
{
    vec4 texColor = texture(Texture0, vTex);
    // store the fragment position vector in the first gbuffer texture
    gPosition = fragPos;
    // also store the per-fragment normals into the gbuffer
    gNormal = normalize(fragNor);
    // and the diffuse per-fragment color
    gColorSpec.rgb = MatDif;
    // store specular intensity in gAlbedoSpec's alpha component
	 //constant could be from a texture
    gColorSpec.a = 0.5;

    gColorSpec = texColor;

} 
