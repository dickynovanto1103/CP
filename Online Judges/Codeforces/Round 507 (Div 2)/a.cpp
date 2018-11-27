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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 25;

int main(){
	int n,i,j,a[2];
	int arr[maxn];
	scanf("%d %d %d",&n,&a[0],&a[1]);
	for(i=0;i<n;i++){scanf("%d",&arr[i]);}
	int minim = min(a[0],a[1]);
	int ans = 0;
	// printf("minim: %d\n",minim);
	for(i=0;i<n;i++){
		int j = n-i-1;
		if(i>j){break;}
		// printf("i: %d j: %d\n",i,j);
		if(arr[i] == 2 && arr[j] == 2){
			if(i==j){
				ans += minim;
			}else{
				ans += 2*minim;	
			}
			
			continue;
		}
		if(arr[i] == 2  || arr[j] == 2){
			if(arr[i] !=2){
				ans += a[arr[i]];
			}else{
				ans += a[arr[j]];
			}
		}else{
			if(arr[i] != arr[j]){
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
};