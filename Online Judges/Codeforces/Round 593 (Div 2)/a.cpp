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
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		int ans = 0;
		while(c >= 2 && b >= 1){
			c-=2;
			b-=1;
			ans+=3;
		}
		while(a >= 1 && b>=2){
			a--;
			b-=2;
			ans+=3;
		}
		printf("%d\n",ans);
	}
	return 0;
};