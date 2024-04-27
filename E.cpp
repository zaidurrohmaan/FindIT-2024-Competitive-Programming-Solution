#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() 
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1), dp(n + 1);
    a[0] = 0LL;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    dp[0] = a[0];
    dp[1] = a[1];
    for (int i = 2; i <= n; i++) {
      dp[i] = a[i] + dp[i - 1];
    }
    while(q--) {
      ll l, r, bl, br;
      cin >> l >> r;
      
      bl = lower_bound(a.begin(), a.end(), l) - a.begin();
      br = lower_bound(a.begin(), a.end(), r) - a.begin() - 1;
      
      ll al = l * (bl - 1) - dp[bl - 1];
      ll ar = (dp[n] - dp[br]) - (r * (n - br));

      cout << al + ar << "\n";
    }
    return 0;
}