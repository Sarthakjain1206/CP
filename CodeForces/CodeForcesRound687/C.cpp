#include <bits/stdc++.h>
using namespace std;

#define N 200100

typedef long long ll;

int n;
ll a[N], d[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < 2 * n; i++)
            scanf("%lld", &d[i]);
        sort(d, d + 2 * n);
        bool ok = true;
        d[2 * n] = a[n] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (d[2 * i] != d[2 * i + 1])
                ok = false;
            ll del = d[2 * i + 2] - d[2 * i];
            if (del == 0 || del % (2 * (i + 1)) != 0)
                ok = false;
            a[i] = a[i + 1] - del / (2 * (i + 1));
        }
        if (ok && a[0] > 0)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}