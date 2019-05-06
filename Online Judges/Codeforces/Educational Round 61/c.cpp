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

const int maxn = 5010;

int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	int l[maxn], r[maxn], cnt[maxn];
	memset(cnt, 0, sizeof cnt);
	int i,j;
	for(i=0;i<q;i++){
		scanf("%d %d",&l[i],&r[i]);
		for(j=l[i];j<=r[i];j++){
			cnt[j]++;
		}
	}
	int on = 0;
	for(i=1;i<=n;i++){
		if(cnt[i]){on++;}
	}
	int cnt1[maxn];
	memset(cnt1, 0, sizeof cnt1);
	int ans = 0;
	for(i=0;i<q;i++){
		for(j=l[i];j<=r[i];j++){
			cnt[j]--;
			if(cnt[j] == 0){on--;}
		}
		for(j=1;j<=n;j++){
			cnt1[j] = (cnt[j] == 1 ? 1 : 0);
			if(j > 1){cnt1[j] += cnt1[j-1];}
		}
		for(j=i+1;j<q;j++){
			int kiri = l[j], kanan = r[j];
			int banyak1 = cnt1[kanan] - cnt1[kiri-1];
			ans = max(ans, on - banyak1);
		}
		for(j=l[i];j<=r[i];j++){
			cnt[j]++;
			if(cnt[j] == 1){on++;}
		}
	}
	printf("%d\n",ans);
	return 0;
};