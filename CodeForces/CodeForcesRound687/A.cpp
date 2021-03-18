#include <bits/stdc++.h>
using namespace std;

#define N 111

int n, a[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int ans = 0;
        for (int i = 1, j = 1; i <= n; i = j)
        {
            while (j <= n && a[j] == a[i])
                j++;
            ans = max(ans, j - i);
        }
        printf("%d\n", ans);
    }

    return 0;
}
