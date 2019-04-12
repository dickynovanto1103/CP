#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int i,j;
	ll n;
	ll a[6];
	ll minim = inf;
	int minimIdx = 9;
	scanf("%lld",&n);
	for(i=0;i<5;i++){
		scanf("%lld",&a[i]);
		if(minim > a[i]){
			minim = a[i];
			minimIdx = i;
		}
	}
	ll t = minimIdx;
	ll iterasi = (n + minim - 1) / minim;
	ll waktuKeAkhir = iterasi + (5-(minimIdx+1));
	t += waktuKeAkhir;
	// for(i=0;i<5;i++){
		
	// 	ll waktuSampeKeDia
	// 	t = max(t, iterasi + 4LL - i);
	// 	printf("iterasi: %lld i: %d ans: %lld\n",iterasi,i,iterasi + 4LL - i);
	// }

	
	printf("%lld\n",t);

	return 0;
};