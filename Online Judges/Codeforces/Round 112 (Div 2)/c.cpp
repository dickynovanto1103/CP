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

const int maxn = 1e6 + 5;
int cnt[maxn];

int main(){
	int k,i,j;
	string kata;
	scanf("%d",&k);
	cin>>kata;
	int pjg = kata.length();

	for(i=0;i<pjg;i++){
		char kar = kata[i];
		if(kar == '1'){
			cnt[i] = 1;
		}
	}
	// printf("cnt[0]: %d\n", cnt[0]);
	for(i=1;i<pjg;i++){
		cnt[i] += cnt[i-1];
		// printf("cnt[%d]: %d\n",i,cnt[i]);
	}
	ll ans = 0;
	for(i=0;i<pjg;i++){
		char kar = kata[i];
		if(kar == '1'){//cari yang maksimal aja bernilai cnt sama
			if(k==0){continue;}
			int lower = lower_bound(cnt, cnt+pjg, cnt[i]+k-1) - cnt;
			lower = max(lower, i);
			int upper = upper_bound(cnt, cnt+pjg, cnt[i]+k-1) - cnt - 1;
			if(lower == pjg){continue;}
			// printf("1 lower: %d upper: %d\n", lower, upper);
			ll banyak = upper - lower + 1;
			ans += banyak;
		}else{//cari lowerbound nilai cnt+1 dan upperbound nilai cnt+1
			int lower = lower_bound(cnt,cnt+pjg, cnt[i] + k) - cnt;
			lower = max(lower, i);
			int upper = upper_bound(cnt, cnt+pjg, cnt[i] + k) - cnt - 1;
			if(lower == pjg){continue;}
			// printf("0 lower: %d upper: %d\n", lower, upper);
			ll banyak = upper - lower + 1;
			ans += banyak;
		}
		
	}
	printf("%lld\n",ans);
	return 0;
};