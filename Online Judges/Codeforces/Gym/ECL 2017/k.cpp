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

const int maxn = 1e5 + 5;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		int n;
		int a,b;
		ll l[maxn];
		ll pre[maxn];
		scanf("%d %d %d",&a,&b,&n);
		l[0] = pre[0] = 0;
		for(i=1;i<=a;i++){
			scanf("%lld",&l[i]);
			pre[i] = pre[i-1] + l[i];
			// printf("pre[%d]: %lld\n",i,pre[i]);
		}
		int ans1 = a,ans2 = b;
		while(n>0) {
			//cari indeks
			// printf("mencari ans1: %d\n",ans1);
			int idx = lower_bound(pre+1,pre+a+1, ans1) - pre;
			int jawab1, jawab2;
			jawab1 = idx;
			jawab2 = ans1 - pre[idx-1];
			// printf("ans1: %d ans2; %d idx: %d jawab1: %d jawab2: %d\n",ans1,ans2,idx,jawab1,jawab2);
			if(jawab1 == ans1 && jawab2==ans2){break;}
			ans1 = jawab1; ans2 = jawab2;
			n--;
		}
		printf("%d-%d\n", ans1,ans2);

	}	
	return 0;
};