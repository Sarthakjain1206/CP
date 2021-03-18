// 11 => 6odds + 5evens

// odds => 2n + 1
// 5 => 2(2) + 1  => 2(k - 1) + 1

// lets say k = 8

// 4 => 2(k - odds_nos)

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    long long n, k;
    cin >> n >> k;
    long long evenNumbers = n / 2;
    long long oddNumbers = n - evenNumbers;

    if(k <= oddNumbers)
        cout << 2*(k - 1) + 1;
    else
        cout << 2*(k - oddNumbers);
    return 0;
}
