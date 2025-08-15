#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        ll n, q;
        cin >> n >> q;
        vector<ll> a(n);
        for ( ll i = 0; i < n; i++ ) cin >> a[i];

        vector<ll> aa(2*n);
        vector<ll> sum( 2*n + 1, 0);
        for ( int i = 0; i < 2*n; i++ ) {
            aa[i] = a[i%n];
            sum[i+1] = sum[i] + aa[i];
        }

        auto get_sum = [&]( ll shift, ll idx, ll len ) {

            ll L = shift + idx;
            ll R = L + len;

            return sum[R] - sum[L];
        };

        while ( q-- ) {
            ll l, r;
            cin >> l >> r;
            l--, r--;

            ll ans = 0;
            ll shift1 = l/n, shift2 = r/n;
            ll idx1 = l % n, idx2 = r % n;

            if ( shift1 == shift2 ) {

                ans = get_sum( shift1, idx1, r-l+1 );
            }
            else {

                ans += get_sum( shift1, idx1, n - idx1);
                if ( shift2 - shift1 > 1 ) ans += ( shift2 - shift1 - 1) * sum[n];

                ans += get_sum( shift2, 0, idx2+1 );
            }
            cout << ans << endl;
        }
    }
    return 0;
}
