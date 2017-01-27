
void main() {
	vec4 pixel = gl_Color;
	gl_FragColor = vec4(1.0, 0.0, 0.0, pixel.a);
}