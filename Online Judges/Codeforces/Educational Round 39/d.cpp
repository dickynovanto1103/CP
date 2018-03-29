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

const int maxn = 510;
string kata[maxn];
int dp[maxn][maxn];
int numberOfHoursSpend[maxn][maxn];

int main(){
	int n,m,k,i,j, p;
	
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<n;i++){cin>>kata[i];}
	for(i=0;i<=n;i++){//memset
		for(j=0;j<=m;j++){
			if(i==0){dp[i][j] = 0; numberOfHoursSpend[i][j] = 0;}
			else{dp[i][j] = inf; numberOfHoursSpend[i][j] = inf;}
			
		}
	}
	//preprocess minimal banyaknya jam yg dispend di hari i klo skip sebanyak j pelajaran
	for(i=1;i<=n;i++){
		vi listSatu;
		for(j=0;j<m;j++){
			char kar = kata[i-1][j];
			if(kar=='1'){listSatu.pb(j);}
		}
		
		for(j=0;j<=listSatu.size();j++){
			int ans = inf;
			int idxAwal = 0, idxAkhir = listSatu.size() - 1 - j;
			// printf("j: %d\n",j);
			if(j==listSatu.size()){ans = 0; numberOfHoursSpend[i][j] = ans; break;}

			while(true){
				if(idxAkhir>=listSatu.size()){break;}
				ans = min(ans, listSatu[idxAkhir] - listSatu[idxAwal] + 1);
				idxAwal++; idxAkhir++;
			}
			numberOfHoursSpend[i][j] = ans;
		}
	}
	//proses dp
	for(i=1;i<=n;i++){
		for(j=1;j<=k;j++){
			for(p=0;p<=j;p++){
				dp[i][j] = min(dp[i][j], dp[i-1][j-p] + numberOfHoursSpend[i][p]);
			}
		}
	}
	if(k==0){
		int ans = 0;
		for(i=0;i<=n;i++){
			ans+=numberOfHoursSpend[i][0];
		}
		printf("%d\n",ans);
		return 0;
	}

	printf("%d\n",dp[n][k]);
	return 0;
};