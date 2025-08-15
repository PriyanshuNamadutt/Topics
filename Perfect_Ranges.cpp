#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
	while ( t-- ) {
	    int n; cin >> n;
	    vector<int> a(n), b(n);
	    for ( int i = 0; i < n; i++ ) cin >> a[i];
	    for ( int i = 0; i < n; i++ ) cin >> b[i];
	    
	    vector<int> pa(n), pb(n);
	    long long ans = 1LL * n;
	    for ( int i = 1; i < n; i++ ) {
	        pa[i] = ( a[i] > a[i-1] ) ? pa[i-1] + 1 : 0;
	        pb[i] = ( b[i] > b[i-1] ) ? pb[i-1] + 1 : 0;
	        
	        if ( a[i] > b[i-1] ) pa[i] = max( pa[i], pb[i-1] + 1);
	        if ( b[i] > a[i-1] ) pb[i] = max( pb[i], pa[i-1] + 1);
	        
	        ans += 1LL * max( pa[i], pb[i] );
	    }
	    cout << ans << endl;
	}
	return 0;

}
