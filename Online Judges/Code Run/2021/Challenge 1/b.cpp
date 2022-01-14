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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int deg[111];

int main(){
	int n,i,j;
	scanf("%d",&n);
	int ans = 0;
	while(n--){
		int c, s;
		scanf("%d %d",&c,&s);
		memset(deg, 0, sizeof deg);
		for(i=0;i<s;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			deg[a]++; deg[b]++;
		}

		bool valid = true;
		for(i=0;i<c;i++){
			if(deg[i] <= 1){
				valid = false;
				break;
			}
		}
		if(valid){ans++;}
	}
	printf("%d\n", ans);
	
	return 0;
};