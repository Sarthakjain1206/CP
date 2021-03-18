#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        long count = 0;
        bool flag = false;

        for (int i = 0; i < n; i++) {
            if(i + 1 < arr[i]) {
                cout << "Second\n";
                flag = true;
                break;
            }
            else
                count += i + 1 - arr[i];
        }
        if(!flag) {
            if(count & 1 == 0)
                cout << "Second\n";
            else
                cout << "First\n";
        }
    }
    return 0;
}