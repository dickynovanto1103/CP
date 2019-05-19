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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int a,b;
	time_t begin = clock();
	scanf("%d %d",&a,&b);
	int k = 0;
	if(a == b){printf("0\n"); return 0;}
	if(a > b){swap(a,b);}
	int selisih = b-a;
	vi listDiv;
	int i,j;
	for(i=1;i*i<=selisih;i++){
		if(selisih % i == 0) {
			int div = selisih / i;
			if(div == i){
				listDiv.pb(div);
			}else{
				listDiv.pb(i); listDiv.pb(div);
			}
		}
	}

	ll lcmLama = ((ll)a*(ll)b)/(ll)__gcd(a,b);
	int ans = 0;
	for(i=0;i<listDiv.size();i++){
		int div = listDiv[i];
		int mod = a % div;
		int k = div - mod;

		k %= div;
		ll lcm = ((ll)(a+k)*(ll)(b+k))/(ll)__gcd(a+k,b+k);
		if(lcmLama > lcm){
			lcmLama = lcm;
			ans = k;
		}else if(lcmLama == lcm) {
			ans = min(ans, k);
		}
	}
	printf("%d\n",ans);
	
	return 0;
};