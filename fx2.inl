#define V ImVec2
#define R rand()
#define I int
#define F float
#define S ((F)R/32767)
#define T(d,b,e)p[j].d=(b*(j&1^j>>1?1:-1))+(e*((j>1)?1:-1))+c.d+a.d;
#define X(a)I a=128+(R&127);
struct P { F x, y, vx, vy, a; I l, s, f, d; }; P p[8192] = { 0 };
void A(V o, I f) { P t; t.x = o.x; t.y = o.y; t.vx = S * 3 - 1.5; t.vy = S * 2.5 - (f ? 4 : 1); t.l = R % (f ? 50 : 99); t.s = R; t.f = f; for (I j = 0; j < 9; j++) { t.d = j; t.a = 1 - (F)j / 9; for (I i = 0; i < 8192; i++)if (!p[i].l) { p[i] = t; break; } } }
void FX(ImDrawList* d, V a, V b, V sz, ImVec4 mn, F t0) {
	I g = R; for (I i = 200; i; --i)d->AddLine(V(a.x, a.y + i), V(b.x, a.y + i), IM_COL32(0, 0, i, 255)); I e = 0; for (I i = 0; i < 8192; i++) { P& c = p[i]; if (c.l) { if (c.d)c.d--; else { srand(c.s); c.x += c.vx; c.y += c.vy; c.vy += .04; c.l -= (c.vy > 0) ? 1 : 0; F s = (S * 3 + .1) * (c.f + 1); F n = (t0 * (c.l < 0 ? 0 : 1)) + (i * S * 2.5 - 1.5); F sa = sin(n) * s; F ca = cos(n) * s; V p[4]; for (I j = 0; j < 4; j++) { T(x, sa, ca); T(y, ca, -sa); }X(r)X(g)X(b)d->AddConvexPolyFilled(p, c.f ? 4 : 3, IM_COL32(r, g, b, (c.f ? 255 : c.l) * c.a)); if (!c.l && c.f && c.a == 1) { I l = R % 40 + 15; for (I j = 0; j < l; j++)A(V(c.x, c.y), 0); } }if (c.f)e++; } }
	srand(g); if (e < 512)A(V(S * 420 - 50, 200), 1);
}