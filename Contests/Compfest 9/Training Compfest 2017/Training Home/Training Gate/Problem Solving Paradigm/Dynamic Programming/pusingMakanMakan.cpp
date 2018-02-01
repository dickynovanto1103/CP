#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const ll mod = 1000000007;

struct waktu{
	int awal, akhir;
};

int n;
waktu pas[100001];
ll memo[100001];

bool acompare(waktu a, waktu b){return a.akhir < b.akhir;}
bool bcompare(waktu a, waktu b){return a.awal < b.awal;}

ll solve(int id, int last){
	if(id==n){return 0;}
	if(pas[id].awal<=last){return solve(id+1,last);}
	if(memo[id]!=-1){return memo[id];}
	ll ans;
	ans = solve(id+1,last) + (1+solve(id+1,pas[id].akhir));
	//printf("ans jd: %lld\n",ans);
	ans%=mod;
	return memo[id] = ans;

}

int main() {
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d %d",&pas[i].awal,&pas[i].akhir);}
	sort(pas,pas+n,acompare);
	/*printf("array terurut pertama:\n");
	for(i=0;i<n;i++){
		printf("%d %d\n",pas[i].awal,pas[i].akhir);
	}
	printf("\n");*/
	int idxAwal = 0, bilAwal = pas[0].akhir;
	for(i=1;i<n;i++){
		if(pas[i].akhir>bilAwal){sort(pas+idxAwal,pas+i,bcompare); bilAwal = pas[i].akhir; idxAwal = i;}
	}
	sort(pas+idxAwal,pas+i,bcompare);
	/*printf("array:\n");
	for(i=0;i<n;i++){
		printf("%d %d\n",pas[i].awal,pas[i].akhir);
	}*/
	memset(memo,-1,sizeof memo);
	ll ans = solve(0,0)%mod;
	printf("%lld\n",ans);
	return 0;
}