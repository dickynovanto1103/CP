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

const int maxn = 1000010;
ll a[maxn];

set<ll> s;
set<ll>::iterator it, it2;

int main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		s.insert(i);
	}
	
	for(i=0;i<n;i++){
		it2 = s.find(i);
		ll bil = a[i];
		ll batasBawah = max((ll)i-a[i],0LL);
		it = s.lower_bound(batasBawah);
		if(it==it2){continue;}
		else{
			s.erase(it,it2);
		}
		
	}
	printf("%d\n",s.size());
	return 0;
};