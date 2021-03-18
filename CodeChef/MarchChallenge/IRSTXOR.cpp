#include<iostream>
#include<math.h>
using namespace std;
int t;

int main(int argc, char const *argv[])
{
    cin >> t;
    while(t--) {
        unsigned int C;
        cin >> C;
        unsigned long long minPower = pow(2, ceil(log2(C + 1)));
        cout << (minPower - 1 >> 1) * ((minPower - 1 >> 1) ^ C);
    }
    return 0;
}
