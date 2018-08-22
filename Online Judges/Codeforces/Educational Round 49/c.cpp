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

const int maxn = 1e6 + 6;

int a[maxn];
int cnt[10010];
int list2[maxn];
int listAssigned[10010];

void clearCnt(int cntAssigned){
	int ukuranAssigned = cntAssigned;
	for(int i=0;i<ukuranAssigned;i++){
		int idx = listAssigned[i];
		cnt[idx] = 0;
	}
}

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);

	while(tc--){
		scanf("%d",&n);
		//memset(cnt, 0 , sizeof cnt);
		int cntAssigned = 0;
		bool foundAnsMin = false;
		int minimal;
		int cnt2 = 0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(cnt[a[i]] == 0){
				listAssigned[cntAssigned] = a[i];
				cntAssigned++;
			}
			cnt[a[i]]++;
			if(cnt[a[i]] == 2){list2[cnt2] = a[i]; cnt2++;}
			if(cnt[a[i]] == 4){
				foundAnsMin = true;
				minimal = a[i];
				// break;
			}
		}
		if(foundAnsMin){
			printf("%d %d %d %d\n",minimal,minimal,minimal,minimal);
			clearCnt(cntAssigned);
			continue;
		}
		sort(list2,list2+cnt2);
		clearCnt(cntAssigned);
		int ukuran2 = cnt2;
		
		double minim = (double)inf*10.0;
		ll ans1, ans2;
		for(i=1;i<ukuran2;i++){
			ll sisi1 = list2[i], sisi2 = list2[i-1];
			ll perimeter = 2LL*(sisi1 + sisi2);
			ll luas = sisi1*sisi2;
			double nilai = (double)perimeter*(double)perimeter / (double)luas;
			// printf("sisi1: %lld sisi2: %lld nilai: %lf\n",sisi1,sisi2,nilai);
			if(minim > nilai){
				minim = nilai;
				ans1 = sisi1, ans2 = sisi2;
				// printf("minim jadi: %lf\n",minim);
			}
		}
		// printf("minim: %lf\n",minim);
		printf("%lld %lld %lld %lld\n",ans1,ans1,ans2,ans2);
	}
	return 0;
};