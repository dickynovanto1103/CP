#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int kiri = 1;
const int kanan = 0;

int main() {
	int a,b,i;
	vector<ii> P;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		P.pb(ii(a,kiri)); P.pb(ii(b,kanan));
	}
	sort(P.begin(),P.end());
	int ukuran = P.size();
	//printf("ukuran: %d\n",ukuran);
	ll ans = 0, jumlah = 0;
	for(i=0;i<ukuran;i++){
		ii front = P[i];
		if(front.second==kiri){
			ans+=jumlah;
			jumlah++;
			//printf("ans jd: %d jumlah jd: %d\n",ans,jumlah);
		}else{
			jumlah--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}