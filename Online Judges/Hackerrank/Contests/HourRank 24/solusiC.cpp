#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin >> t;
    for (int i=0; i<t; i++) {
        ll a,b,x;
        cin >> a >> b >> x;
        map <ll, bool> ambil;
        deque<ll> result;
        bool found = false;
        for (ll i=b; i>=a; i--) {
            if (!ambil[i]) {
                result.push_back(i);
                for (ll f=1; f*f<=i; f++) {
                    if (i%f == 0) {
                        ambil[f] = true;
                        ambil[i/f] = true;
                    }
                }
                if (result.size() == x) {
                    found = true;
                    for (ll j=0; j<x; j++) {
                        cout << result[j];
                        if (j<x-1) cout << " ";
                    }
                    cout << endl;
                    break;
                }
            }
            
                
        }
        if (!found) {
            cout << -1 << endl;
        }
    }
    return 0;
}