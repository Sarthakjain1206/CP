#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    while(t--) {
        unsigned int arr[10];
        for (int i = 0; i < 10; i++)
            cin >> arr[i];

        unsigned int k;
        cin >> k;
        int index = 9;
        while(arr[index] <= k) {
            k -= arr[index];
            if(k < 0)
                k = 0;
            index--;
        }
        cout << index << endl;
    }


    return 0;
}
