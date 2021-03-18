#include <bits/stdc++.h>
using namespace std;

#define N 200100

int n, q;
char s[N], f[N];

int add[N << 2], len[N << 2], cnt[N << 2];

void modify(int v, int d)
{
    add[v] = d;
    cnt[v] = d ? len[v] : 0;
}

void push_dn(int v)
{
    if (add[v] >= 0)
    {
        modify(v << 1, add[v]);
        modify(v << 1 | 1, add[v]);
        add[v] = -1;
    }
}

void push_up(int v)
{
    cnt[v] = cnt[v << 1] + cnt[v << 1 | 1];
}

void build(int v, int vl, int vr)
{
    cnt[v] = 0;
    len[v] = vr - vl + 1, add[v] = -1;
    if (vl == vr)
        cnt[v] = f[vl];
    else
    {
        int mi = vl + vr >> 1;
        build(v << 1, vl, mi), build(v << 1 | 1, mi + 1, vr);
        push_up(v);
    }
}

void modify(int v, int vl, int vr, int l, int r, int d)
{
    if (vl > r || l > vr)
        return;
    if (l <= vl && vr <= r)
        modify(v, d);
    else
    {
        push_dn(v);
        int mi = vl + vr >> 1;
        modify(v << 1, vl, mi, l, r, d);
        modify(v << 1 | 1, mi + 1, vr, l, r, d);
        push_up(v);
    }
}

int query(int v, int vl, int vr, int l, int r)
{
    if (vl > r || l > vr)
        return 0;
    if (l <= vl && vr <= r)
        return cnt[v];
    push_dn(v);
    int mi = vl + vr >> 1;
    return query(v << 1, vl, mi, l, r) + query(v << 1 | 1, mi + 1, vr, l, r);
}

bool go(int v, int vl, int vr)
{
    if (vl == vr)
        return cnt[v] == s[vl];
    push_dn(v);
    int mi = vl + vr >> 1;
    return go(v << 1, vl, mi) & go(v << 1 | 1, mi + 1, vr);
}

typedef pair<int, int> pii;
vector<pii> vec;

inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
template <class T>
inline void read(T &x)
{
    char c = nc(), b = 1;
    for (; !(c >= '0' && c <= '9' || c == EOF); c = nc())
        if (c == '-')
            b = -b;
    for (x = 0; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = nc())
        ;
    x *= b;
}
inline void read(char *s)
{
    char c = nc();
    int len = 0;
    for (; c == ' ' || c == '\t' || c == '\n'; c = nc())
        ;
    for (; !(c == ' ' || c == '\t' || c == '\n' || c == EOF); s[len++] = c, c = nc())
        ;
    s[len] = 0;
}
template <typename Head, typename... Tail>
inline void read(Head &H, Tail &...T)
{
    read(H), read(T...);
}

int main()
{
    int T;
    read(T);
    while (T--)
    {
        read(n, q);
        read(s + 1), read(f + 1);
        for (int i = 1; i <= n; i++)
            s[i] -= '0', f[i] -= '0';
        build(1, 1, n);
        bool ok = true;
        vec.clear();
        while (q--)
        {
            int l, r;
            read(l, r);
            vec.emplace_back(l, r);
        }
        reverse(vec.begin(), vec.end());
        for (auto p : vec)
        {
            int l = p.first, r = p.second;
            int c1 = query(1, 1, n, l, r), c0 = r - l + 1 - c1;
            if (c0 == c1)
            {
                ok = false;
                break;
            }
            else if (c0 > c1)
                modify(1, 1, n, l, r, 0);
            else
                modify(1, 1, n, l, r, 1);
        }
        ok &= go(1, 1, n);
        if (ok)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}
