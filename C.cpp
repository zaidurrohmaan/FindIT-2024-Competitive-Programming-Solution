#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() 
{
    ll n, r, k, sc = 0;
    cin >> n >> r >> k;
    ll b[n], x[n];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> x[i];
    
    for (int i = 0; i < n; i++) {
      sc += x[i] * b[i];
    }
    
    if (sc >= r*100) cout << "PASS";
    else cout << "NOT PASS";
    return 0;
}