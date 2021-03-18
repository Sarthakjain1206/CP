#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, count = 0, ans = INT_MIN;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if(n == 1){
        cout << 1;
        return 0;   
    }
    int j, i = 0;
    while (i < n - 1) {
        for (j = i + 1; j < n; j++)
        {
            if(arr[j - 1] <= arr[j])
                continue;
            else
                break;
        }
        ans = max(ans, j - i);
        i = j;
    }

    cout << ans;
    return 0;
}
