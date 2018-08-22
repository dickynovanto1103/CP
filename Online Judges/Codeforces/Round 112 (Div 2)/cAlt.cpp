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
ll sum[maxn];

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

	for(i=1;i<pjg;i++){
		cnt[i] += cnt[i-1];
	}

	for(i=0;i<pjg;i++){
		int bil = cnt[i];
		sum[bil]++;
		printf("sum[%d]: %lld\n",bil,sum[bil]);
	}

	ll ans = 0;
	for(i=0;i<pjg;i++){
		int banyak1 = cnt[i];
		if(banyak1 < k){continue;}
		ans += sum[banyak1 - k];
		printf("ans jd: %lld\n",ans);
	}
	printf("%lld\n",ans);
	
	return 0;
};