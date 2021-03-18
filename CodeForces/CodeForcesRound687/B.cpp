#include <bits/stdc++.h>
using namespace std;

#define N 10010

int n, d;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &n, &d);
        while (n--)
        {
            int a;
            scanf("%d", &a);
            if (a % d == 0)
                puts("YES");
            else
            {
                int r = a % d + d * 10;
                if (a >= r)
                    puts("YES");
                else
                {
                    bool fg = false;
                    for (int i = 1; i <= 100; i++)
                    {
                        int r = a - d * i;
                        if (r >= 0 && r % 10 == 0)
                            fg = true;
                    }
                    if (fg)
                        puts("YES");
                    else
                        puts("NO");
                }
            }
        }
    }

    return 0;
}
