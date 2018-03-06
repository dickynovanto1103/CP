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
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;
const ll mod = 1e9 + 7;

ll a[maxn], minim[4*maxn], maks[4*maxn], gcd[4*maxn];

iii cancel = make_pair(ii(-1,-1),-1);

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}
void build(int node, int l, int r){
	if(l==r){
		minim[node] = l*a[l]; minim[node]%=mod;
		maks[node] = minim[node];
		gcd[node] = a[l];
	}else{
		int mid = (l+r)/2;
		build(left(node),l,mid);
		build(right(node),mid+1,r);
		gcd[node] = __gcd(gcd[left(node)], gcd[right(node)]);
		ll calonMinim = l*gcd[node];
		calonMinim%=mod;
		minim[node] = min(min(minim[left(node)], minim[right(node)]), calonMinim);
		maks[node] = max(maks[left(node)], maks[right(node)]);
	}
}

iii query(int node, int l, int r, int i, int j){
	if(r < i || l > j){return make_pair(ii(-1,-1),-1);}
	if(i<=l && r<=j){return make_pair(ii(minim[node], maks[node]), gcd[node]);}
	int mid = (l+r)/2;
	iii ans1 = query(left(node), l,mid,i,j);
	iii ans2 = query(right(node), mid+1, r, i, j);
	
	if(ans1==cancel){return ans2;}
	if(ans2==cancel){return ans1;}
	iii ans;
	ll hasilGCD = __gcd(ans1.second, ans2.second);
	ll calonMinim = l*hasilGCD;
	calonMinim%=mod;
	ll minimal = min(min(ans1.first.first, ans2.first.first), calonMinim);
	ll maksimal = max(ans1.first.second, ans2.first.second);
	ll GCD = __gcd(ans1.second,ans2.second);

	ans = make_pair(ii(minimal,maksimal), GCD);
	return ans;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	build(1,1,n);
	ll ans = 0;
	for(i=2;i<=n;i++){
		for(j=1;j<=n;j++){
			int batasKanan = j+i-1;
			if(batasKanan>n){break;}
			
			iii jawab = query(1,1,n,j,batasKanan);
			ll ansPartial = ((jawab.first.second - jawab.first.first)*(ll)i);
			ansPartial%=mod;
			printf("kiri: %d kanan: %d ansPartial: %lld minim: %lld maks: %lld\n",j,batasKanan,ansPartial,jawab.first.first, jawab.first.second);
			
			ans+=ansPartial;
			ans%=mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
};