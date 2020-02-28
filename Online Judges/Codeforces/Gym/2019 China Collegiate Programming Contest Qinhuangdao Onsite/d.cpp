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
		ll n;
		scanf("%lld",&n);
		ll bil = 1;
		bool valid = false;
		for(i=1;i<=18;i++){
			if(bil % n == 0){
				valid = true;
				break;
			}
			bil*=10;
		}
		if(valid){printf("No\n");}
		else{printf("Yes\n");}
	}
	return 0;
};