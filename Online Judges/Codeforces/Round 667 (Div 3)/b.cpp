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
	int tc,i,j,a,b,x,y,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d %d %d",&a,&b,&x,&y,&n);
		int tempa = a, tempb = b, tempn = n;
		int diff = a - x;
		int minimal = min(diff, n);
		a-=minimal; n-=minimal;
		//then reduce b
		int diffb = b - y;
		minimal = min(diffb, n);
		b-=minimal; n -= minimal;
		ll ans1 = (ll)a * b;

		a = tempa, b = tempb, n = tempn;
		diffb = b - y;
		minimal = min(diffb, n);
		b-=minimal; n -= minimal;
		diff = a - x;
		minimal = min(diff, n);
		a-=minimal; n-=minimal;

		ll ans2 = (ll)a*b;

		printf("%lld\n",min(ans1, ans2));
	}
	
	return 0;
};