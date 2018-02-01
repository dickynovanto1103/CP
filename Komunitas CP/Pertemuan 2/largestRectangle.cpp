#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 100010;

int main(){
	int n,i,j;
	ll a[maxn];
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++){scanf("%lld",&a[i]);}
		i=0;
		stack<ll> s;
		ll maks = 0, area;
		while(i<n){
			if(s.empty() || a[s.top()]<=a[i]){
				s.push(i++);
			}else{
				int idx = s.top(); s.pop();
				area = a[idx]*(s.empty()? i: i-s.top()-1);
				maks = max(maks,area);
			}
		}
		while(!s.empty()){
			int idx = s.top(); s.pop();
			area = a[idx]*(s.empty()? i: i-s.top()-1);
			maks = max(maks,area);
		}
		printf("%lld\n",maks);
	}
	return 0;
};