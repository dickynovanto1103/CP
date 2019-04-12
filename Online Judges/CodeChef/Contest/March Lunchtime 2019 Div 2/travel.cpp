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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ii intersect(ii a, ii b){
	int x = max(a.first, b.first);
	int y = min(a.second, b.second);
	if(x > y){return ii(-1,-1);}
	else{return ii(x,y);}
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	ii a[1000001];
	while(tc--){
		int n,d;
		scanf("%d %d",&n,&d);

		for(i=0;i<n;i++){
			scanf("%d",&a[i].first);
			a[i].second = i;
		}
		sort(a,a+n);
		int cnt1 = 0;
		bool isBisa = true;
		vii listSegment;
		for(i=0;i<n;i++){
			//cari banyak di kiri dan kanan
			// printf("a[%d]: %d %d\n",i,a[i].first,a[i].second);
			int idxKiri = lower_bound(a, a+n, ii(a[i].first - d, -1)) - a;
			int idxKanan = upper_bound(a, a+n, ii(a[i].first + d, -1)) - a;

			int ans = (idxKanan - idxKiri - 1);
			listSegment.pb(ii(idxKiri, idxKanan-1));
			printf("idxKiri: %d idxKanan: %d ans: %d\n",idxKiri, idxKanan, ans);
			if(ans <= 0){isBisa = false;break;}
			else if(ans == 1){cnt1++; if(cnt1 > 2){isBisa = false; break;}}
		}
		for(i=0;i<n-1;i++){
			if(intersect(listSegment[i], listSegment[i+1]) == ii(-1,-1)){isBisa = false; break;}
		}
		if(isBisa){printf("YES\n");}
		else{printf("NO\n");}
	}
	return 0;
};