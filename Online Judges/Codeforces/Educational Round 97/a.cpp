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
	int tc,i,j,l,r;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&l, &r);
		int mod = l % (r+1);
		if(mod >= (r+2)/2) {
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
};