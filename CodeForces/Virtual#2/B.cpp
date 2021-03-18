#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,m;
    cin >> n;
    int boys[n];
    for (int i = 0; i < n; i++)
        cin >> boys[i];
    cin >> m;
    int girls[m];
    for (int i = 0; i < m; i++)
        cin >> girls[i];

    sort(boys, boys + n);
    sort(girls, girls + m);

    // for (int i = 0; i < n; i++)
    //     cout << boys[i] << " ";
    // cout << "\n";
    // for (int i = 0; i < m; i++)
    //     cout << girls[i] << " ";
    // cout << "\n";
    
    int last = 0, pairs = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++ ) {
            if(abs(girls[j] - boys[i]) <= 1) {
                pairs += 1;
                girls[j] = 1001;
                // last = j + 1;
                break;
            }
        }
    }
    cout <<pairs << endl;
    // lower_bound()
    return 0;
}

// #include <iostream>
// #include <math.h>
// using namespace std;

// int countPaths(int n)
// {
//     int zB = 1;

//     int zADC = 0;

//     for (int i = 1; i <= n; i++)
//     {

//         int nzB = zADC * 3;

//         int nzADC = (zADC * 2 + zB);

//         zB = nzB;
//         zADC = nzADC;
//     }

//     // returns steps
//     return zB;
// }

// // Driver Code
// int main()
// {
//     long n;
//     long mod = pow(10, 9) + 7;
//     cin >> n;
//     cout << countPaths(n) % mod;

//     return 0;
// }
