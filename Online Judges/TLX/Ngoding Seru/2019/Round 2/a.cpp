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

const int maxn = 1e5 + 5;

const int mod = 1e9 + 7;

int mul(int a, int b){
	return (ll)a*b % mod;
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int a[maxn];
	int cnt = m;
	set<int> s;
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
		if(a[i] == 0){cnt--; continue;}
		s.insert(a[i]);
	}
	int ans = 1;
	for(i=1;i<=n;i++){
		if(s.find(i) == s.end()){
			ans = mul(ans, cnt);
			// printf("ans sekarang: %d\n",ans);
		}else{
			s.erase(i);
			cnt--;
			ans = mul(ans, 1);
		}
		// printf("ans jd: %d cnt: %d\n",ans, cnt);
	}
	printf("%d\n",ans);
	return 0;
};