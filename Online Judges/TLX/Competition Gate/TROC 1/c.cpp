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
typedef vector<ii> vii;

struct pasangan{
	int com, idx, penambahan;
};

const int maxn = 1e5 + 5;

bool cmp(pasangan a, pasangan b){
	if(a.com == b.com){return a.idx < b.idx;}
	return a.com < b.com;
}

int main(){
	int n,q,i,j;
	scanf("%d %d",&n,&q);
	pasangan pas[maxn];

	set<int> s;
	set<int>::iterator it;

	int maksIdxSum = 0;
	int minimIdxPengurangan = maxn-1;

	for(i=0;i<q;i++){
		scanf("%d %d %d",&pas[i].com,&pas[i].idx,&pas[i].penambahan);
		if(pas[i].com==1){
			s.insert(pas[i].idx-1);	
			maksIdxSum = max(maksIdxSum, pas[i].idx-1);
		}else{
			s.insert(n-pas[i].idx);
			minimIdxPengurangan = min(minimIdxPengurangan, n-pas[i].idx);
		}
	}

	if(maksIdxSum < (n-1)){
		s.insert(maksIdxSum+1);	
	}
	
	if(minimIdxPengurangan > 0){s.insert(minimIdxPengurangan-1);}

	ll sum[maxn];
	map<int,int> mapper;
	int cnt = 0;
	for(it=s.begin();it!=s.end();it++){
		// printf("bil: %d\n",*it);
		mapper[*it] = cnt++;
	}

	sort(pas,pas+q, cmp);
	memset(sum, 0, sizeof sum);
	int idx;


	for(i=0;i<q;i++){
		if(pas[i].com == 2){
			idx = i;
			break;
		}
		int idxList = mapper[pas[i].idx-1];

		sum[idxList] += pas[i].penambahan;
		// printf("sum[%d] jd: %lld\n",idxList, sum[idxList]);
	}

	ll pengurangan[maxn];
	memset(pengurangan, 0, sizeof pengurangan);
	//urus buat com == 2

	for(i=idx;i<q;i++){
		int idxList = mapper[n-pas[i].idx];
		pengurangan[idxList] += pas[i].penambahan;
	}

	ll suffSum[maxn];
	memset(suffSum, 0, sizeof suffSum);
	suffSum[cnt-1] = sum[cnt-1];
	for(i=cnt-2;i>=0;i--){
		suffSum[i] = suffSum[i+1] + sum[i];
		// printf("suffSum[%d] jd: %lld\n",i,suffSum[i]);
	}

	ll suffPengurangan[maxn];
	memset(suffPengurangan, 0, sizeof suffPengurangan);
	suffPengurangan[0] = pengurangan[0];
	for(i=1;i<cnt;i++){
		suffPengurangan[i] = suffPengurangan[i-1] + pengurangan[i];
		// printf("suffPengurangan[%d]: %lld\n",i,suffPengurangan[i]);
	}

	ll tot[maxn];
	memset(tot, 0, sizeof tot);

	for(i=cnt-1;i>=0;i--){
		tot[i] = suffSum[i] - suffPengurangan[i];
	}

	ll maks = 0;
	for(i=0;i<cnt;i++){
		tot[i] = abs(tot[i]);
		maks = max(maks, tot[i]);
		// printf("tot[%d]: %lld\n",i,tot[i]);
	}
	printf("%lld\n",maks);

	return 0;
};