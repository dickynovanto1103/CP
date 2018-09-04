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

const int maxn = 2e5 + 5;

int main(){
	int n,i,j,a[maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int maks = 1;
	int cnt = 1;
	int last = a[0];

	for(i=1;i<n;i++){
		int bil = a[i];
		// printf("i: %d a: %d\n",i,bil);
		if(bil > 2*last){
			last = bil;
			maks = max(maks, cnt);
			// printf("cnt: %d maks: %d\n",cnt,maks);
			// printf("i:\n");
			cnt = 1;
			continue;
		}else{
			last = bil;
			cnt++;
		}
		
		// printf("maks jd: %d\n",maks);
	}
	maks = max(maks, cnt);
	printf("%d\n",maks);
	return 0;
};