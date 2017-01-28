uniform sampler2D texture;
float step = 1.0 / 72.0;
void main() {
	float alpha = texture2D(texture, gl_TexCoord[0].xy).a;
	
	/*
	 *    red blue
	 * yellow green
	 */

	vec2 pos = gl_TexCoord[0].xy;
	vec3 color = vec3(0.0, 0.0, 0.0);
	color.r = cos(pos.x);
	color.g = cos(pos.y);
	color.b = sin(cos(pos.x + pos.y));

	gl_FragColor = vec4(color, alpha);
}