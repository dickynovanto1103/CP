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
	int tc,a[3],m;
	scanf("%d",&tc);
	while(tc--){
		for(int i=0;i<3;i++){
			scanf("%d",&a[i]);
		}
		scanf("%d",&m);
		sort(a, a+3);
		a[2] - 1 - (a[0] + a[1]) <= m && m <= a[0] + a[1] + a[2] - 3 ? printf("YES\n"): printf("NO\n");;
	}

	return 0;
};