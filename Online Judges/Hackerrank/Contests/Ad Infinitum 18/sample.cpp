#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map <ll, ll> squareroot; 
ll det (ll a, ll b, ll c)
{
    return b*b-4*a*c; 
}
int main()
{   
    for (ll g=1;g<=100000; g++) squareroot[g*g]=g; 
    ll T; cin >> T; 
    for (ll g=0; g<T; g++)
    {
        ll answer=0; 
        ll n, k, t, o; cin >> n >> k >> t >> o; 
        for (ll a=1; a<=t; a++)
        {
            ll first=1; 
            ll second=-k; 
            ll third=a*a-a*n; 
            ll l=det(first, second, third); 
            ll squarerootl=squareroot[l]; 
            if (squarerootl*squarerootl==l)
            {
                ll check1=-second+squarerootl, check2=-second-squarerootl; 
                if (check1%2==0)
                {
                    check1/=2; 
                    if (check1>=1 && check1<=o)
                    answer++; 
                }
                if (check2%2==0 && squarerootl!=0) 
                {
                    check2/=2; 
                    if (check2>=1 && check2<=o)
                    answer++; 
                } 
            }
        }
        cout << answer << '\n'; 
    }
}