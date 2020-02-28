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

const int maxn = 1e5 + 5;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn];
	int cnt[maxn];
	memset(cnt, 0, sizeof cnt);
	
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int idx = 0;
	int cur = -inf;
	int mapper[maxn];
	mapper[0] = cur;
	map<int,int> hasilMapper;
	hasilMapper[mapper[0]] = -inf;
	for(i=0;i<n;i++){
		if(cur != a[i]){
			idx++;	
			mapper[idx] = a[i];
			hasilMapper[a[i]] = idx;
		}
		cnt[idx]++;
		// printf("cnt[%d]: %d\n",idx,cnt[idx]);
		cur = a[i];
	}

	if(n == 1){
		int ans = a[0]%2;
		if(ans == 0){printf("cslnb\n");}
		else{printf("sjfnb\n");}
	}else if(n == 2) {
		int tot = a[0] + a[1];
		if(tot == 0){printf("cslnb\n");}
		else{
			tot--;
			if(tot % 2 == 0){printf("cslnb\n");}
			else{printf("sjfnb\n");}
		}
	}else{
		if(a[0] == 0){
			if(cnt[1] >= 2){printf("cslnb\n"); return 0;}
		}
		for(i=0;i<=n;i++){
			if(cnt[i] >= 3){printf("cslnb\n"); return 0;}
		}
		int banyak2 = 0;
		for(i=0;i<=n;i++){
			if(cnt[i] >= 2){banyak2++;}
		}
		if(banyak2 >= 2){printf("cslnb\n"); return 0;}
		else if(banyak2 == 1) {
			for(i=1;i<=n;i++){
				if(cnt[i] >= 2) {
					int idxSebelum = mapper[i-1];
					int idxSekarang = mapper[i];
					// printf("idxSebelum: %d i-1 :%d\n",idxSebelum,i-1);
					if(idxSekarang == idxSebelum + 1 && cnt[hasilMapper[idxSebelum]] >= 1) {
						printf("cslnb\n"); return 0;
					}
				}
			}
		}
		ll selisih = 0;
		for(i=0;i<n;i++){
			if(i <= a[i]){
				selisih += (a[i] - i);
			}else{
				printf("cslnb\n");
				return 0;
			}
		}
		if(selisih % 2LL == 0){printf("cslnb\n");}
		else{printf("sjfnb\n");}

	}
	return 0;
};