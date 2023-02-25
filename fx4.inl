#define V ImVec2
#define CF d->AddCircleFilled
#define RAND(a) (float)rand()/(float)(RAND_MAX/a)
void FX(ImDrawList* d, V a, V b, V s, ImVec4 m, float t) {
	static bool o = true;
	static V bs[1000];
	if (o) {
		o = false;
		for (int i = 0; i < 1000; ++i) {
			float g = RAND(IM_PI / 2) + (IM_PI / 4);
			float r = RAND(50) + 5;
			bs[i] = V(g, r);
		}
	}
	for (int i = 0; i < 1000; ++i) {
		float
			g = bs[i].x,
			r = bs[i].y;
		r += sin(t + i) * 100;
		CF(V(r * cos(g), r * sin(g)) + (s / 2 + a) + V(r * cos(t), 0), i % 2 + 1, IM_COL32(r + 100, 50, fabs(r) + 100, 200));
	}
}