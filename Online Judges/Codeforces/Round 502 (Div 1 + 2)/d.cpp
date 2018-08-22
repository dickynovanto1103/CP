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

const int maxn = 5e5 + 5;

char kata[maxn][12];
char word[maxn][12];
int listK[maxn];
int listSum[maxn];
vector<vi> AdjList;

int main(){
	int n,q,m;
	scanf("%d %d %d",&n,&m,&q);
	int i,j;
	int w[13];
	int counter[4099];
	for(i=0;i<n;i++){scanf("%d",&w[i]);}
	for(i=0;i<m;i++){
		scanf("%s",kata[i]);
		int sum = 0;
		for(j=0;j<n;j++){
			char kar = kata[i][j];
			int bil = kar - '0';
			sum+=(bil*(1<<j));
		}

		counter[sum]++;
	}

	AdjList.assign(4099, vi());

	for(i=0;i<q;i++){
		scanf("%s %d",word[i],&listK[i]);
		int sum = 0;
		for(j=0;j<n;j++){
			char kar = word[i][j];
			int bil = kar - '0';
			sum+=(bil*(1<<j));
		}
		AdjList[sum].pb(i);
		listSum[i] = sum;
	}

	int prefSum[101];
	int ans[maxn];
	memset(ans, -1, sizeof ans);
	for(i=0;i<q;i++){
		if(ans[i] != -1){continue;}
		memset(prefSum, 0, sizeof prefSum);
		char kar;
		// printf("word: %s i: %d\n",word[i],i);
		for(j=0;j<(1<<n);j++){
			int sum = 0;
			int binary = 0;
			for(int k=0;k<n;k++){
				if((1<<k) & j){
					kar = '1';
					binary += ((1<<k));
				}else{
					kar = '0';
				}

				if(kar == word[i][k]){
					sum+=w[k];
				}
			}
			if(sum <= 100){
				prefSum[sum] += counter[binary];
				// printf("prefSum[%d] ditambah dengan counter[%d]: %d jd: %d\n",sum,binary,counter[binary],prefSum[sum]);
			}
		}
		for(j=1;j<=100;j++){
			prefSum[j] += prefSum[j-1];
			// printf("prefSum[%d] jd: %d\n",i,prefSum[j]);
		}
		int ukuran = AdjList[listSum[i]].size();
		for(j=0;j<ukuran;j++){
			int idx = AdjList[listSum[i]][j];
			// printf("idx: %d\n",idx);
			int kminimal = listK[idx];
			ans[idx] = prefSum[kminimal];
		}

	}
	for(i=0;i<q;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
};