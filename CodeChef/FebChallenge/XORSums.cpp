#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define mod 998244353
vector<unsigned int> fact(2 * 100001);

unsigned int factorial(int n) {
    
    if(n == 0 || n == 1)
        return 1;
    if(fact[n] != 0)
        return fact[n];
    unsigned val = (factorial(n - 1) * n)%mod;
    fact[n] = val;
    return val;
}
unsigned int combination(int n, int r) {
    if(n == r)
        return 1;
    if(n - r < 0)
        return 0;
        
    unsigned int a = factorial(n);
    unsigned int b = factorial(r);
    unsigned int c = factorial(n - r);
    return a / (((b % mod) * (c % mod)) % mod);
    // return factorial(n) / (factorial(r) * factorial(n - r));
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    unsigned int arr[n];
    vector<int> vec(32, 0);
    vector<int> dp(2 * 100001, 0);

    for (int i = 0; i < n; i++) {
        int temp, count = 0; cin >> temp;
        arr[i] = temp;
        while( temp > 0 ) {
            int bit = temp & 1;
            if(bit == 1) vec[31 - count]++;
            temp /= 2;
            count++;
        }
    }
    // for (int i = 0; i < vec.size(); i++)
    // {
    //     /* code */
    //     cout << vec[i]<< endl;
    // }
    int t;
    cin >> t;
    while(t--) {
        int Q;
        cin >> Q;
        // int res = 0;
        int ans = 0;
        for (int q = 1; q <= Q; q++){
            if(dp[q] != 0) {
                ans = (ans + dp[q]) % mod;
                continue;
            }
            // res = res + dp[q];
            int res = 0;
            for (int k = 1; k <= q; k += 2)
            {
                for (int i = 31; i >= 0; i--)
                {
                    if (vec[i] == 0)
                        break;
                    unsigned int weight = pow(2, 31 - i);
                    ull ans = combination(vec[i], k);
                    ull ans2 = combination(abs(vec[i] - n), q - k);
                    int val = ((((ans % mod) * (ans2 % mod)) % mod) * (weight % mod)) % mod;
                    // cout << "Val: " << val<<endl;
                    res = (res + val) % mod;
                }
                // cout << "\n";
            }
            // cout << "\nhell\n";
            ans = (ans + res)%mod;
            dp[q] = res;
        }
        cout << ans << endl;
    }

        return 0;
}


                // for (int l = 0; l < 5; l++)
                //     cout << dp[l] << " ";
                
                // cout << "\nAlready Calculated\n";






// First Code----------

// #include<bits/stdc++.h>
// using namespace std;
// typedef unsigned long long ull;
// #define mod 998244353

// ull factorial(int n) {
//     ull ans = 1;
//     while(n > 1) {
//         ans *= n;
//         --n;
//     }
//     return ans;
// }
// ull combination(int n, int r) {
//     if(n == r)
//         return 1;
    
//     return factorial(n) / (factorial(r) * factorial(n - r));
// }
// int main(int argc, char const *argv[])
// {
//     int n;
//     cin >> n;
//     unsigned int arr[n];
//     vector<int> vec(32, 0);
//     // vector<int> dp(2 * 100001, 0);

//     for (int i = 0; i < n; i++) {
//         int temp, count = 0; cin >> temp;
//         arr[i] = temp;
//         while( temp > 0 ) {
//             int bit = temp & 1;
//             if(bit == 1) vec[31 - count]++;
//             temp /= 2;
//             count++;
//         }
//     }
//     // for (int i = 0; i < vec.size(); i++)
//     // {
//     //     /* code */
//     //     cout << vec[i]<< endl;
//     // }
//     int t;
//     cin >> t;
//     while(t--) {
//         int Q;
//         cin >> Q;
//         int res = 0;
//         for (int q = 1; q <= Q; q++){
//             // if(dp[q] != 0) {
//             //    res = (res + dp[q])%mod;
//             //    continue;
//             // }
//             // res = res + dp[q];
//             for (int k = 1; k <= q; k += 2)
//             {
//                 for (int i = 31; i >= 0; i--)
//                 {
//                     if (vec[i] == 0)
//                         break;
//                     unsigned int weight = pow(2, 31 - i);
//                     ull ans = combination(vec[i], k);
//                     ull ans2 = combination(abs(vec[i] - n), q - k);
//                     res = (res + ((((ans % mod) * (ans2 % mod)) % mod) * (weight % mod)) % mod) % mod;
//                 }
//             }
//         }
//         cout << res << endl;
//     }

//         return 0;
// }
