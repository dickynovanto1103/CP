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
	int tc,n;
	scanf("%d",&tc);
	int a[310];
	vi odd, even;
	while(tc--){
		odd.clear(); even.clear();
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i] % 2 == 1) {odd.pb(i);}
			else{even.pb(i);}
		}

		// bool found = false;
		// int x,y,z;
		// for(int i=0;i<n;i++){
		// 	for(int j=i+1;j<n;j++){
		// 		for(int k=j+1;k<n;k++){
		// 			if((a[i] + a[j] + a[k]) % 2 == 1) {
		// 				x = i, y = j, z = k;
		// 				found = true;
		// 				break;
		// 			}
		// 		}
		// 	}
		// }

		if(odd.size() == 0){puts("NO");}
		else if(odd.size() == 2 && n == 3) {puts("NO");}
		else if(odd.size() >= 3) {
			puts("YES");
			printf("%d %d %d\n", odd[0] + 1, odd[1] + 1, odd[2] + 1);
		}
		else{
			assert(even.size() >= 2);
			puts("YES");
			printf("%d %d %d\n", odd[0] + 1, even[0] + 1, even[1] + 1);
		}

		// if(found) {
		// 	printf("YES\n%d %d %d\n", x + 1, y + 1, z + 1);
		// }else{
		// 	printf("NO\n");
		// }
	}
	
	return 0;
};