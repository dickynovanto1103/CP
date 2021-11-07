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

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d",&n);
		int bil;
		bool valid = true;
		for(i=1;i<=n;i++){
			scanf("%d",&bil);
			//if a[i] is divisible by all 2 ... i + 1, it means that a[i] is divisible also by lcm(2 ... i+1)
			//we want to know if bil is going to be divisible all of 2 until i + 1...if divisible, then the answer == NO
			//turns out that if i == 22, lcm (2, 3, ... 23) > 1e9, which is greater than the constraint of bil
			//so it means if i >= 22, the bil must have index between 2 until i + 1 such that bil % idx != 0, so we don't need to check it
			if(i < 22) {
				bool found = false;
				for(j=i+1;j>=2;j--){
					if(bil % j != 0) {
						found = true;
						break;
					}
				}
				valid &= found;
			}else{
				continue;
			}
		}

		valid ? puts("YES"): puts("NO");
	}
	
	return 0;
};