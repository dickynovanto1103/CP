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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

vector<vi> AdjList;
int n;
int a[maxn];

bool isValid(int mid) {
	int i,j;
	vector<vi> listPromo;
	int temp[maxn];
	for(i=1;i<=n;i++){
		temp[i] = a[i];
	}
	listPromo.assign(2*maxn + 1000, vi());
	for(i=1;i<=n;i++){
		if(AdjList[i].size() == 0){continue;}
		int idx = lower_bound(AdjList[i].begin(), AdjList[i].end(), mid) - AdjList[i].begin();
		if(idx == AdjList[i].size()){idx--;}
		if(idx < 0){continue;}
		if(AdjList[i][idx] > mid){
			idx--;
		}
		if(idx < 0){continue;}
		
		listPromo[AdjList[i][idx]].pb(i);
	}
	int burle = 0;
	int day = 1;
	while(day <= mid) {
		burle++;
		for(i=0;i<listPromo[day].size();i++){
			int jenis = listPromo[day][i];
			int biaya = min(temp[jenis], burle);
			temp[jenis] -= biaya;
			burle -= biaya;
		}
		day++;
	}
	for(i=1;i<=n;i++){
		if(temp[i]){
			int biaya = temp[i]*2;
			if(burle < biaya){return false;}
			burle -= biaya;
		}
	}
	return true;
}

int main(){
	int m,i,j;
	scanf("%d %d",&n,&m);
	
	AdjList.assign(maxn, vi());
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<m;i++){
		int d,t;
		scanf("%d %d",&d,&t);
		AdjList[t].pb(d);
	}
	for(i=1;i<=n;i++){
		sort(AdjList[i].begin(), AdjList[i].end());
	}

	int kiri = 1, kanan = 400110, mid, ans;
	while(kiri<=kanan) {
		mid = (kiri+kanan)/2;
		if(isValid(mid)){
			ans = mid;
			kanan = mid-1;
		}else{
			kiri = mid+1;
		}
	}
	printf("%d\n",ans);

	return 0;
};