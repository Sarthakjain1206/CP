// Working----
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(ll n, ll e, ll h, ll a, ll b, ll c) {
    // cout << "I m inside\n";
    if(n <= 0)
        return 0;

    ll ans = LLONG_MAX;
    if(2*n <= e)
        ans = min(ans, n * a);
    if(3*n <= h)
        ans = min(ans, n * b);
    if(n <= e && n <= h)
        ans = min(ans, n * c);
    if((h - n)/2 >= 1 && (h - n)/2 >= (n - e)) {
        // cout << "Shake and Cake\n";
        if(b < c) {
            ll x = min(n - 1, (h - n) / 2);
            ans = min((b - c) * x + n * c, ans);
        }
        else {
            ll y = 1;
            ll z = n - e;
            ll x = max(y, z);
            ans = min(ans, (b - c) * x + n * c);
        }
    }
    
    if((e - n) >= 1 && (e + h) >= 2*n) {
        // cout << "om and shake\n";
        if(a < c) {
            ll x = min(n - 1, e - n);
            ans = min((a - c) * x + n * c, ans);
        }
        else {
            ll y = 1;
            ll z = n - h;
            ll x = max(y, z);
            ans = min(ans, (a - c) * x + n * c);
        }
    }

    if ((e / 2) >= 1 && (e / 2) >= (3 * n - h + 2) / 3) {
        // cout << "om and shake\n";
        if(a < b) {
            ll x = min(n - 1, e / 2);
            ans = min((a - b) * x + n * b, ans);
        }
        else{
            ll y = 1;
            ll z = (3 * n - h + 2) / 3;
            ll x = max(y, z);
            ans = min(ans, (a - b) * x + n * b);
        }
    }
    if(e >= 3 and h >= 4 and n >= 3){
        // cout << "all\n";
        // cout << ans << endl;
        ll temp = solve(n - 3, e - 3, h - 4, a, b, c);
        ans = min(temp == LLONG_MAX ? LLONG_MAX: a + b + c + temp, ans);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    while(t--) {
        ll n, e, h, a, b, c, y;
        cin >> n >> e >> h >> a >> b >> c;
        y = solve(n, e, h, a, b, c);
        // cout << y;
        if(y == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << y << endl;
    }
    return 0;
}
