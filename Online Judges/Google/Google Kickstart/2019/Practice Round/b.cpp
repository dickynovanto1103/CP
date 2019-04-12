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

const int maxn = 5e6 + 6;

int a[maxn];

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		int n;
		string kata;
		scanf("%d",&n);
		cin>>kata;
		for(i=0;i<n;i++){
			a[i] = kata[i] - '0';
			if(i){a[i] += a[i-1];}
		}
		int banyak = (n+1)/2;
		int ans = 0;
		for(i=0;i<n;i++){
			int next = i + banyak - 1;
			if(next >= n){break;}
			ans = max(ans, a[next] - (i == 0? 0: a[i-1]));
		}
		printf("%d\n",ans);
	}
	return 0;
};