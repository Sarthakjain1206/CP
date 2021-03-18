#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int k, w;
    ll n;
    cin >> k >> n >> w;
    int total_money = (k * (w * (w + 1))) / 2;
    if(n >= total_money)
        cout << 0;
    else
        cout << total_money - n;
    return 0;
}
