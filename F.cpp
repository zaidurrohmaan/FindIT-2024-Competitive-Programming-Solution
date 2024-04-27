#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() 
{
    ll n, c = 1, r = 2, i = 0, iMirror, expand = -1, diff = -1, maxLpsLen = 0, maxLpsCP = 0, start = -1, end = -1;
    string s;
    cin >> n >> s;
    
    n *= 2;
    n++;
    
    int L[n];
    L[0] = 0;
    L[1] = 1;
    
    for (i = 2; i < n; i++) {
      iMirror = 2 * c - i;
      expand = 0;
      diff = r - i;
      
      if (diff >= 0) {
        if (L[iMirror] < diff) L[i] = L[iMirror];
        else if(L[iMirror] == diff && r == n-1) L[i] = L[iMirror];
        else if (L[iMirror] == diff && r < n-1) {
          L[i] = L[iMirror];
          expand = 1;
        } else if (L[iMirror] > diff) {
          L[i] = diff;
          expand = 1;
        }
      } else {
        L[i] = 0;
        expand = 1;
      }
      
      if (expand == 1) {
        while(((i + L[i]) < n && (i - L[i]) > 0) 
                   && (((i + L[i] + 1) % 2 == 0) 
                       || (s[(i + L[i] + 1) / 2] 
                           == s[(i - L[i] - 1) / 2]))) {
                             L[i]++;
                           }
      }
      
      if (L[i] > maxLpsLen) {
        maxLpsLen = L[i];
        maxLpsCP = i;
      }
      
      if (i + L[i] > r) {
        c = i;
        r = i + L[i];
      }
      
      start = (maxLpsCP - maxLpsLen) / 2;
      end = start + maxLpsLen - 1;
    }
    
    start = (maxLpsCP - maxLpsLen) / 2;
    end = start + maxLpsLen - 1;
    
    cout << end - start + 1;
    return 0;
}