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

const int maxn = 1e5 + 5;
string kata[maxn];
int a[maxn];
map<string, int> mapper;

int main(){
	int n,k,m,i,j;
	scanf("%d %d %d",&n,&k,&m);
	for(i=1;i<=n;i++){
		cin>>kata[i];
		mapper[kata[i]] = i;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<k;i++){
		int banyak;
		scanf("%d",&banyak);
		vi listIdx;
		int minimBiaya = inf;
		for(j=0;j<banyak;j++){
			int idx;
			scanf("%d",&idx);
			minimBiaya = min(minimBiaya, a[idx]);
			listIdx.pb(idx);
		}
		for(j=0;j<banyak;j++){
			int idx = listIdx[j];
			a[idx] = minimBiaya;
			// printf("a[%d]: %d\n",idx,a[idx]);
		}
	}
	ll sum = 0;
	for(i=0;i<m;i++){
		string word;
		cin>>word;
		int idx = mapper[word];
		sum+=a[idx];
	}
	printf("%lld\n",sum);
	return 0;
};