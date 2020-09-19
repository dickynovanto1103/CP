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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	bool vis[10001];
	memset(vis, false, sizeof vis);
	vi listFalse;
	for(i=1;i<=n;i++){listFalse.pb(i);}
	//cari tau angka ke i dengan tanya ke i+1
	if(n == 1){
		printf("! 1\n");
		fflush(stdout);
		return 0;
	}
	bool visBil[10001];
	memset(visBil, false, sizeof visBil);
	int a[10001];
	while(listFalse.size() >= 2){
		int idx1 = listFalse.back(); listFalse.pop_back();
		int idx2 = listFalse.back(); listFalse.pop_back();
		printf("? %d %d\n",idx1, idx2);
		fflush(stdout);
		int ans1, ans2;
		scanf("%d",&ans1);
		printf("? %d %d\n",idx2, idx1);
		fflush(stdout);
		scanf("%d",&ans2);
		if(ans1 < ans2){
			a[idx2] = ans2;
			listFalse.pb(idx1);
			vis[idx2] = true;
			visBil[ans2] = true;
		}else{
			a[idx1] = ans1;
			listFalse.pb(idx2);
			vis[idx1] = true;
			visBil[ans1] = true;
		}
	}

	int miss = 0;
	for(i=1;i<=n;i++){
		if(!visBil[i]){miss = i;}
	}

	for(i=1;i<=n;i++){
		if(!vis[i]){a[i] = miss;}
	}
	printf("!");
	for(i=1;i<=n;i++){
		printf(" %d",a[i]);
	}
	printf("\n");
	fflush(stdout);	
	return 0;
};