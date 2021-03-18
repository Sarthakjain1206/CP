#include <bits/stdc++.h>
using namespace std;

#define N 200100

typedef long long ll;

int n;
ll k, x[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %lld", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &x[i]);
        ll d = 0;
        for (int i = 1; i < n; i++)
            d = __gcd(d, abs(x[i] - x[n]));
        if ((k - x[n]) % d == 0)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}
