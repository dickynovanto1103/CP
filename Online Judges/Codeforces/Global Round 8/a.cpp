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
	int tc,i,j,a,b,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&a,&b,&n);
		bool kiri = (a <= b ? true:false);
		int step = 0;
		while(a <= n && b <= n){
			if(kiri){
				a += b;
				kiri = false;
			}else{
				b += a;
				kiri = true;
			}
			step++;
		}
		printf("%d\n",step);
	}
	
	return 0;
};