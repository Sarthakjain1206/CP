#include <bits/stdc++.h>
using namespace std;

// // int main(int argc, char const *argv[])
// // {
// //     int n, k;
// //     cin >> n >> k;
// //     int arr[n];

// //     for (int i = 0; i < n; i++)
// //     {
// //         cin >> arr[i];
// //     }
// //     int ans = 0;
// //     for (int i = 0; i < k; i++)
// //     {
// //         /* code */
// //         int one = 0;
// //         int two = 0;
// //         for (int j = i; j < n; j+=k)
// //         {
// //             /* code */
// //             if(arr[j] == 1)
// //                 one++;
// //             else
// //                 two++;
// //         }
// //         ans += min(one, two);
// //     }
// //     cout << ans;
// //     return 0;
// // }

// int main(int argc, char const *argv[])
// {
//     int n;
//     cin >> n;
//     // vector<pair<char, char>> vec;
//     // char *dp;
//     string s;
//     cin >> s;
//     // char dp[s.length()];
//     vector<char> dp(s.length());
//     for (int i = 0; i < s.length(); i++)
//     {
//         dp[i] = s[i];
//     }
//     // for (int i = 0; i < s.length(); i++)
//     // {
//     //     cout << dp[i];
//     // }
//     // cout << endl;
//     for (int i = 0; i < n; i++)
//     {
//         if(i == 0) {
//             // cin >> s;
//             // dp = new char[s.length()];
//             // for (int i = 0; i < s.length(); i++)
//             // {
//             //     dp[i] = s[i];
//             // }
//         }
//         else {
//             cin >> s;
//             for (int j = 0; j < s.length(); j++) {
//                 if(dp[j] == '!')
//                     continue;
//                 else if(dp[j] != s[j]) {
//                     if(dp[j] != '?' && s[j] != '?')
//                         dp[j] = '!';
//                     else if(dp[j] == '?')
//                         dp[j] = s[j];
//                 }
//             }
//         }
//     }

//     for (int i = 0; i < s.length(); i++) {
//         if(dp[i] == '!')
//             dp[i] = '?';
//         else if(dp[i] == '?')
//             dp[i] = 'a';
//     }
//     for(int i = 0; i < s.length();i++) cout << dp[i];
//     // cout << dp;
//     // free(dp);
//     return 0;
// }



#define LL long long
using namespace std;
const int maxVal = 300002;

int main()
{
    int n;
    cin >> n;
    LL a[maxVal], l, r, k, ans[maxVal];
    LL s[maxVal];
    map<int, vector<int> > map;

    s[0] = 0;
    LL sum = LLONG_MIN, tmp;

    for (int i = 1; i < 1 + n; i++)
    {
        cin >> a[i];
        if(a[i] > 0)
            s[i] = s[i - 1] + a[i];
        else
            s[i] = s[i - 1];
        map[a[i]].push_back(i);
    }

    for(auto it = map.begin(); it != map.end(); it++)
    {
        int size = it->second.size();
        if(size >= 2)
        {
            tmp = s[it->second[size-1]] - s[it->second[0]-1];
            if(it->first < 0) tmp += it->first*2;
            if(tmp > sum)
            {
                sum = tmp, l = it->second[0], r = it->second[size-1];
            }
        }
    }
    k = 0;
    for(int i=1; i<l; i++)
        ans[k++] = i;
    for(int i=l+1; i<r; i++)
        if(a[i] < 0) ans[k++] = i;
    for(int i=r+1; i<n+1; i++)
        ans[k++] = i;

    printf("%I64d %d\n", sum, k);
    for(int i=0; i<k; i++)
        cout << ans[i] << " ";

    return 0;
}
