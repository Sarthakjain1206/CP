#include <bits/stdc++.h>
using namespace std;

#define N 5050

int n;
typedef long long ll;
struct pnt
{
    int x, y;
    void in()
    {
        scanf("%d %d", &x, &y);
    }
    ll dist(const pnt &p) const
    {
        return 1ll * (x - p.x) * (x - p.x) + 1ll * (y - p.y) * (y - p.y);
    }
} p[N];

bool vis[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        p[i].in();
    p[0].x = p[0].y = -1e9 - 7;
    for (int i = 1, c = 0; i <= n; i++)
    {
        ll mx = 0;
        int k = -1;
        for (int j = 1; j <= n; j++)
        {
            if (vis[j])
                continue;
            ll d = p[c].dist(p[j]);
            if (d > mx)
                mx = d, k = j;
        }
        c = k;
        vis[c] = 1;
        printf("%d ", c);
    }
    puts("");

    return 0;
}
