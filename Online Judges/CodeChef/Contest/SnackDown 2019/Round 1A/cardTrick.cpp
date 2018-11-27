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

const int maxn = 1e5 + 5;

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[maxn];

	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		int cur = inf+1;
		int awal1, awal2, akhir1, akhir2, cntIncreasing = 0;
		bool isValid = true;
		for(i=0;i<n;i++){

			if(a[i] < cur){
				cntIncreasing++;
				if(cntIncreasing == 1){
					awal1 = a[i];
				}else if(cntIncreasing == 2){
					awal2 = a[i];
				}else{
					isValid = false;
					break;
				}
			}else{
				if(cntIncreasing == 1){
					akhir1 = a[i];
				}else{
					akhir2 = a[i];
				}
			}

			cur = a[i];
		}
		if(!isValid){printf("NO\n");}
		else{
			if(cntIncreasing == 1){printf("YES\n");}
			else{
				if(akhir2 <= awal1){printf("YES\n");}
				else{printf("NO\n");}	
			}
			
		}
	}
	return 0;
};