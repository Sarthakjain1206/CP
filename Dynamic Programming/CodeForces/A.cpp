#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    while(t--) {
        int n, v, risk, not_riks, res = 0;
        cin >> n >> v;
        int arr[n];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] >= 80 or arr[i] <= 10)
                risk++;
        }
        not_riks = n - risk;
        res += ceil((double)risk / v) + ceil((double)not_riks / v);
        cout << res << endl;
    }
    return 0;
}
