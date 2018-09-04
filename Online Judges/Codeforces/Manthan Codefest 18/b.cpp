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
	int n,s,i,j;
	int a[maxn];
	scanf("%d %d",&n,&s);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int idx = n/2;
	if(a[idx] == s){
		printf("0\n");
	}else{
		ll ans = 0;
		if(a[idx] < s){// perlu tambahkan sampe s
			
			for(i=idx;i<n;i++){
				if(a[i] < s){
					ans += (s - a[i]);
				}else{
					break;
				}
			}
		}else{
			for(i=idx;i>=0;i--){
				if(a[i] > s){
					ans += (a[i] - s);
				}else{
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
};