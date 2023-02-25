#define V2 ImVec2
#define F float
F k;
int i{};
F r() { return F(rand() / 32768.f) * 2.f - 1.f; };
struct P {
	F x, y, z, a, b, c; void A() {
		x += a * k; y += b * k; z += c * k;
		F ng{ 0.008f }; z -= 5.f; F xp = x * cosf(ng) - z * sinf(ng); F zp = x * sinf(ng) + z * cosf(ng);
		x = xp; z = zp + 5.f; a -= x * k + r() * k; b -= y * k + r() * k; c -= (z - 5.0f) * k + r() * k;
	}
};
P p[64];
void FX(ImDrawList* d, V2 o, V2 b, V2 sz, ImVec4, F t)
{
	int j{};
	if (!i) { i = 1; for (P& a : p) { a = { r(),r(),r() + 5.f,r(),r(),r() }; } }
	for (P& a : p) {
		if (a.z < 0.001) continue;
		V2 s((a.x / a.z) * sz.x * 2.f + sz.x * 0.5f + o.x, (a.y / a.z) * sz.y * 2.f + sz.y * 0.5f + o.y);
		int x = (j++) % 16;
		k = cosf((j / 64.f) * 3.14592f) * 0.002f + 0.002f;
		F dist = fabsf(a.z - 5.f) / 2.5f, sc = (10.f + dist * 100.f) / a.z;
		int tr = int(ImMin(dist * 128.f, 128.f) + 127) << 24;
		ImColor col = ImColor::HSV(k * 9.f + 0.06f, 0.8f, 1.f, 1.f - sqrtf(dist));
		d->AddCircleFilled(s, sc, col, 12); a.A();
	}
}