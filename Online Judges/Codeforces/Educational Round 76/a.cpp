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
	int n,x,a,b;
	scanf("%d",&tc);
	while(tc--) {
		scanf("%d %d %d %d",&n,&x,&a,&b);
		int ans;
		ans = abs(a-b);
		if(a > b){swap(a,b);}
		// printf("%s\n", );
		int selisih1 = a - 1;
		int minim = min(selisih1, x);
		x -= minim;
		a -= minim;
		int selisih2 = n - b;
		minim = min(selisih2, x);
		x -= minim;
		b += minim;
		ans = abs(a-b);
		printf("%d\n",ans);
	}
	return 0;
};