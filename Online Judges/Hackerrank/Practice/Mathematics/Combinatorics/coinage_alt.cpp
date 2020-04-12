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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,k,n,a,b,c,d;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		scanf("%d %d %d %d",&a,&b,&c,&d);
		map<int,int> cnt;
		for(i=0;i<=b;i++){
			if(i*2 > n){break;}
			for(j=0;j<=a;j++){
				if((i*2 + j) > n){break;}
				cnt[i*2+j]++;
			}
		}
		int ans = 0;
		for(i=0;i<=d;i++){
			int now = i*10;
			if(now > n){break;}
			for(j=0;j<=c;j++){
				int temp = now;
				temp += (j*5);
				if(now > n){break;}
				ans += cnt[n - temp];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
};