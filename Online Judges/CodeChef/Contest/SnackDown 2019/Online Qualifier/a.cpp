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

const int maxn = 100010;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int tc,i,j,n,k;
	int a[maxn];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		sort(a,a+n,cmp);
		int bil = a[k-1];
		int ans = k;
		for(i=k;i<n;i++){
			if(a[i] != bil){
				break;
			}else{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
};