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

struct pas{
	int idx,t,d,p;
};
const int maxn = 110;
pas pasangan[maxn];
int n;
bool cmp(pas a, pas b){
	return a.d < b.d;
}
int dp[maxn][2050];

int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%d %d %d",&pasangan[i].t,&pasangan[i].d,&pasangan[i].p); pasangan[i].idx = i;}
	sort(pasangan+1,pasangan+n+1,cmp);
	// printf("pasangan\n");
	// for(i=0;i<n;i++){printf("%d %d %d\n",pasangan[i].t,pasangan[i].d,pasangan[i].p);}
	//memset(dp,0,sizeof dp);
	int ans = 0, posisiWaktu=1;
	for(i=1;i<=n;i++){
		//printf("i: %d\n",i);
		//if(pasangan[i].t >= pasangan[i].d){continue;}
		for(j=1;j<=2000;j++){
			dp[i][j] = dp[i-1][j];

			if(j<pasangan[i].d && j>=pasangan[i].t){
				dp[i][j] = max(dp[i][j],dp[i-1][j-pasangan[i].t] + pasangan[i].p);
			}
			if(ans < dp[i][j]){
				ans = dp[i][j]; posisiWaktu = j;
				//printf("ans jd: %d\n",ans);
			}
		}
	}
	stack<int> listBarangDiambil;
	int idx = n;
	while(idx){
		//printf("idx: %d\n",idx);
		if(dp[idx][posisiWaktu]!=dp[idx-1][posisiWaktu]){
			posisiWaktu-=pasangan[idx].t;
			listBarangDiambil.push(pasangan[idx].idx);
			//if(posisiWaktu<0){break;}
		}
		idx--;
	}
	//print solution
	printf("%d\n",ans);
	if(listBarangDiambil.size()==0){printf("0\n"); return 0;}
	printf("%d\n",listBarangDiambil.size());
	int cnt = 0;
	while(!listBarangDiambil.empty()){
		if(cnt){printf(" ");}
		printf("%d",listBarangDiambil.top()); listBarangDiambil.pop();
		cnt++;
	}
	printf("\n");
	return 0;
};