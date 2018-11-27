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

vi ans, elemen;

bool isBigger(vi a){
	for(int i=0;i<a.size();i++){
		// printf("%d ",a[i]);
		if(a[i] > ans[i]){
			return true;
		}else if(a[i] < ans[i]){
			return false;
		}
	}
	// printf("\n");
	return false;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	vi a;
	for(i=1;i<=n;i++){a.pb(i); ans.pb(0); elemen.pb(9);}

	do{
		vi temp;
		int gcd = 0;
		for(j=n-1;j>=0;j--){
			gcd = __gcd(gcd,a[j]);
			// printf("%d ",gcd);
			temp.pb(gcd);
		}
		reverse(temp.begin(), temp.end());
		// printf("\n");
		if(isBigger(temp)){
			for(i=0;i<n;i++){
				ans[i] = temp[i];
			}
			for(i=0;i<n;i++){
				// printf("i: %d\n",i);
				elemen[i] = a[i];
			}
		}
	}while(next_permutation(a.begin(),a.end()));
	printf("ans\n");
	for(i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	printf("elemen\n");
	for(i=0;i<n;i++){
		printf("%d ",elemen[i]);
	}
	printf("\n");
	return 0;
};