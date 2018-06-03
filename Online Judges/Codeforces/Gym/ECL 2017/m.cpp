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
	int tc,i,j;
	int n,a[7];
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		for(i=0;i<5;i++){scanf("%d",&a[i]);}
		scanf("%d",&n);
		ll tot = 0;
		for(i=0;i<n;i++){
			int id;
			scanf("%d",&id);
			if(id<=48) {
				tot+=a[0];
			}else if(id<=56){
				tot+=a[1];
			}else if(id<=60){
				tot+=a[2];
			}else if(id<=62){
				tot+=a[3];
			}else if(id<=63) {
				tot+=a[4];
			}
		}
		printf("%lld\n",tot*10000LL);
	}
	return 0;
};