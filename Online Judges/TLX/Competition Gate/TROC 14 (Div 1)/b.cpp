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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

void makeStr(ll a) {
	ll awal = a;
	string s;
	while(a){
		int bil = a % 2;
		s += (bil + '0');
		a /= 2;
	}
	reverse(s.begin(), s.end());
	// cout<<awal<<" "<<s<<endl;
}

int main(){
	//9223372036854775808
	int n,i,j;
	scanf("%d",&n);
	ll a[100001];
	ll sor = 0;
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		makeStr(a[i]);
		sor ^= a[i];
	}
	if(n == 1){printf("%lld\n",a[0]); return 0;}
	ll sorAwal = sor;
	ll ans = sorAwal;
	makeStr(sor);
	sort(a, a+n);
	//attempt to change only the last number
	for(i=0;i<n;i++){
		ll last = a[i];
		sor = sorAwal;
		sor ^= last;
		vi list;
		for(j=0;j<63;j++){
			if(sor & (1LL<<j)){

			}else{
				list.pb(j);
			}
		}
		reverse(list.begin(), list.end());
		ll valNow = 0;
		for(j=0;j<list.size();j++){
			int idx = list[j];
			if((valNow + (1LL<<idx)) <= last){
				sor ^= (1LL<<idx);
				valNow += (1LL<<idx);
			}
		}
		
		ans = max(ans, sor);
		// printf("a[%d]: %lld sor: %lld ans: %lld\n", i, a[i], sor, ans);
	}

	printf("%lld\n",ans);
	return 0;
};