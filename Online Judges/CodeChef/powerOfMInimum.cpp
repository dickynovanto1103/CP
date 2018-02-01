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


const int maxn = 1000000;
int counter[maxn+10];

int main(){
	int n, i,j;

	scanf("%d",&n);
	int bil, maks = -inf;
	for(i=0;i<n;i++){
		scanf("%d",&bil);
		maks = max(maks,bil);
		counter[bil]++;
	}
	int ans = 0;
	for(i=1;i<=maxn;i++){
		if(counter[i]) {
			ans+=counter[i];
			for(j=i*2;j<=maks;j+=i) {
				counter[j] = counter[j]-counter[i];
				if(counter[j]<0){counter[j]=0;}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
};