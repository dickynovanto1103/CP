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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e4 + 4;

int main(){
	int tc,i,j;
	scanf("%d",&tc);

	double cnt2[maxn], cnt5[maxn];
	cnt2[0] = 0, cnt5[0] = 0;
	for(i=1;i<maxn;i++){
		cnt2[i] = cnt2[i-1] + log10(2);
		cnt5[i] = cnt5[i-1] + log10(5);
		// if(i < 100){
		// 	printf("2; %lf 5: %lf\n", cnt2[i], cnt5[i]);
		// }
	}

	while(tc--){
		int a,b;
		scanf("%d %d",&a,&b);
		int digit = min(a,b);
		a -= digit; b-=digit;
		// printf("digitAwal: %d a: %d b: %d\n",digit, a,b );
		int maks = max(a,b);
		if(a == maks) {
			digit += floor(cnt2[a]) + 1;		
		}else{
			digit += floor(cnt5[b]) + 1;		
		}
		printf("%d\n",digit );
	}

	return 0;
};