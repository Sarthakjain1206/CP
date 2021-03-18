#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        long long x;
        cin >> n >> x;
        long long arr[n];
        // int arr[n];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int i = 0, j = 0, index = n, limit = INT_MAX;
        long long sum = 0;
        bool flag = true;
        while (true)
        {
            /* code */
            // cout << "N: " << n<<endl;
            bool flag2 = false;
            for (j = 0; j < n; j++)
            {
                /* code */
                if(arr[j] % x != 0 and flag) {
                    index = j;
                    flag = false;
                    limit = i + 2;
                }
                if(j == 0 and arr[j] == 0){
                    flag2 = true;
                    break;
                }
                    // break;
                sum += arr[j] * pow(x,i);
                // cout << arr[j] * pow(x,i) << endl;
                arr[j] = arr[j] / x;
            }
            n = index;
            if(n <= 0 or flag2)
                break;
            i += 1;
            if(i == limit)
                break;
            // cout << endl;
        }
        cout << sum << endl;
    }
    return 0;
}
