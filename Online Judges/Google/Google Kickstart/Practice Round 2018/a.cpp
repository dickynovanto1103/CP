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
	int tc,i,j,p;
	int a[550], b[550];
	int counter[5500];
	int n;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		memset(counter,0,sizeof counter);
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d %d",&a[i],&b[i]);
			int minim = min(a[i],b[i]), maks = max(a[i],b[i]);
			for(j=minim;j<=maks;j++){
				counter[j]++;
			}
		}
		int q;
		scanf("%d",&q);
		vi listAns;
		while(q--){
			int kota;
			scanf("%d",&kota);
			listAns.pb(counter[kota]);
		}
		for(i=0;i<listAns.size();i++){
			if(i){printf(" ");}
			printf("%d",listAns[i]);
		}
		printf("\n");
	}
	return 0;
};