#define V ImVec2
#define R d->AddRectFilled
#define C(x) IM_COL32((sin(x) + 1) * 255 / 2, (cos(x) + 1) * 255 / 2, 99, 255)
#include <set>
void FX(ImDrawList* d, V a, V b, V s, ImVec4, float t) {
    static auto z = 0.f;
    if (t > z + 2) z += 2;
    auto c = C(z + 2);
    R(a, b, C(z));
    for (auto B = b.x, i = 0.f, o = s.y / 8; i < 8; ++i, B = b.x) {
        if (auto w = (i / 7) * .2f, x = std::max(t - z - w, 0.f); t - z < w + 1)
            B = a.x + (x < .5 ? 8 * x * x * x * x : std::min(1 - pow(-2 * x + 2, 4.f) / 2, 1.f)) * s.x;
        R(V(a.x, a.y + o * i), V(B, a.y + o * i + o), c);
    }
}