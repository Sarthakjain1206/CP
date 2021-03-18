#include<bits/stdc++.h>
using namespace std;

long long calc(long long a, long long b, long long c) {
    return abs(a - b) + abs(a - c) + abs(b - c);
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr + n);
        // long long ans = LLONG_MIN;
        // for (int i = 1; i < n - 1; i++)
        //     ans = max(ans, calc(arr[0], arr[n-1], arr[i]));
        

        long long val1 = abs(arr[0] - arr[n - 1]) + abs(arr[0] - arr[1]) + abs(arr[1] - arr[n - 1]);
        long long val2 = abs(arr[0] - arr[n - 1]) + abs(arr[0] - arr[n - 2]) + abs(arr[n - 2] - arr[n - 1]);
        cout << max(val2, val1)<<endl;
        // cout << ans << endl;
    }

    return 0;
}
