#include<bits/stdc++.h>
using namespace std;


void printDivisors(int n, unordered_set<int> &set)
{
    for (int i = 1; i*i < n; i++) {
        if (n % i == 0)
            set.insert(i);
    }
    for (int i = sqrt(n); i >= 1; i--) {
        if (n % i == 0)
            set.insert(i);
    }
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    while(t--) {
        unordered_set<int> set;
        int l, r;
        cin >> l >> r;
        for (int i = l; i <= r; i++) {
            printDivisors(i, set);
        }

        for (int i = 2; i <= 2000000000; i++) {
            if(set.find(i) == set.end()) {
                cout << i << endl;
            }
        }                
    }
    return 0;
}