template <typename a>
a b();
struct {
    template <typename c, typename... d>
    auto operator()(c e, d... f) -> decltype(g(e, f...))
    {
        g(0);
    }
} g;
struct h {
    friend g(h, auto, *);
    operator()(auto... f) { g(*this, b<decltype(f)>()...); }
} i;
struct j {k({
    j l = i(l)