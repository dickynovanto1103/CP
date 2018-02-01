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

const int mod = 1e9 + 7;
const int maxn = 5001;
ll memo[maxn][maxn];
int listIdx[maxn];
int maksVal[maxn];
bool isFixed[maxn];
int n,m;
vii listAngka;

ll solve(int idx, int val){
	if(val>maksVal[idx]){
		return memo[idx][val] = 0;
	}
	if(val<maksVal[idx] && isFixed[idx]){
		return memo[idx][val] = 0;
	}
	if(idx==m){
		return memo[idx][val] = 1;
	}
	if(memo[idx][val]!=-1){return memo[idx][val];}
	memo[idx][val] = (solve(idx+1,val)%mod + solve(idx+1,val+1)%mod)%mod;
	return memo[idx][val];
}

bool isIncreasing(){
	int ukuran = listAngka.size();

	for(int i=0;i<ukuran-1;i++){
		//ii front = listAngka[i];
		if(listAngka[i+1].second < listAngka[i].second){
			//printf("angka1: %d angka2: %d\n",listAngka[i+1].second, listAngka[i].second);
			return false;
		}
	}
	return true;
}

int main(){
	int k;
	int a[maxn],i,j,l;
	int tc,tt;
	scanf("%d",&tc);
	for(tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d %d",&m,&n,&k);
		bool foundSalah = false;
		memset(listIdx,-1,sizeof listIdx);
		for(i=0;i<k;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			if(a<b){foundSalah = true;}
			listIdx[a] = b;
		}
		if(!(listIdx[m]==-1 || listIdx[m]==n)){foundSalah = true;}
		if(!(listIdx[1]==-1 || listIdx[1]==1)){foundSalah = true;}

		if(foundSalah){printf("0\n"); continue;}

		//valid
		listIdx[1] = 1; listIdx[m] = n;
		maksVal[1] = 1; maksVal[m] = n;
		isFixed[1] = true; isFixed[m] = true;
		listAngka.clear();
		for(i=1;i<=m;i++){
			if(listIdx[i]!=-1){listAngka.pb(ii(i,listIdx[i])); memo[i][listIdx[i]]=-1; maksVal[i] = listIdx[i]; isFixed[i] = true;}
		}
		int ukuran = listAngka.size();
		/*printf("listangka kedua\n");
		for(i=0;i<ukuran;i++){
			printf("%d\n",listAngka[i].second);
		}*/

		if(!isIncreasing()){printf("0\n"); continue;}

		//resetValue
		
		for(i=0;i<ukuran-1;i++){
			//printf("i: %d\n",i);
			int j = i+1;
			ii front1 = listAngka[i], front2 = listAngka[j];
			int idx1 = front1.first, idx2 = front2.first;
			int minval = front1.second, maxval = front2.second;
			for(j=idx1+1;j<=idx2-1;j++){
				int maks = min(maksVal[j-1]+1,maxval);
				//printf("MaksVal[%d]: %d\n",j-1,maksVal[j-1]);
				//printf("j: %d maks: %d\n",j,maks);
				maksVal[j] = maks;
				isFixed[j] = false;
				for(l=minval;l<=maks;l++){
					memo[j][l] = -1;
				}
			}
		}
		/*for(i=1;i<=m;i++){
			printf("maksVal[%d]: %d\n",i,maksVal[i]);
		}*/
		ll ans = solve(1,1);
		/*if(tt==5){
			printf("\n");
			for(i=1;i<=m;i++){
				for(j=1;j<=n;j++){
					if(j>1){printf(" ");}
					printf("%d",memo[i][j]);
				}
				printf("\n");
			}
		}*/
		printf("%lld\n",ans);
		listAngka.clear();
	}
	
	return 0;
};