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

int main(){
	int ans[110];
	int i,j,n;
	scanf("%d",&n);
	ans[1] = 1;
	for(i=2;i<=n;i++){
		printf("bil: %d ->",i);
		int maks = 0, sum;
		for(j=2;j<=i;j++){
			if(i%j==0){
				int banyakPotongan = i/j;
				if(j<i){
					sum=(banyakPotongan*ans[j]) + 1;	
				}else{
					sum=(i+1);
				}
				maks = max(maks,sum);
			}
			
		}
		ans[i] = maks;
		printf("%d\n",maks);
	}
	return 0;
};