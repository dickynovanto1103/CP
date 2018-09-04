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
	int n,k,i,j;
	int a[maxn];
	ii mapper[267];
	for(i=0;i<267;i++){
		mapper[i] = ii(-1,-1);
	}
	
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	int ans[maxn];
	for(i=0;i<n;i++){
		int minim = max(a[i] - k + 1, 0);
		// printf("minim: %d a[%d]: %d\n", minim, i, a[i]);
		if(mapper[a[i]] == ii(-1,-1)){
			if(mapper[minim] == ii(-1,-1)){
				for(j=minim;j<=a[i];j++){
					mapper[j] = ii(minim, a[i]);
				}
				ans[i] = minim;
			}else{
				int kiri = mapper[minim].first, kanan = mapper[minim].second;
				if(kiri < minim){
					for(j=kanan+1;j<=a[i];j++){
						mapper[j] = ii(kanan+1,a[i]);
					}
					ans[i] = kanan+1;
				}else{
					for(j=minim;j<=a[i];j++){
						mapper[j] = ii(minim, a[i]);
					}
					ans[i] = minim;
				}
			}
		}else{
			ans[i] = mapper[a[i]].first;
		}
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");

	return 0;
};