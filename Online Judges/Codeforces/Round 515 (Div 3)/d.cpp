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
int a[maxn];

int main(){
	int n,m,k,i,j;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	int kiri = 0, kanan = n, mid, ans = 0;
	while(kiri <= kanan){
		mid = (kiri+kanan)/2;
		int start = n - mid;
		int box = m;
		int cap = k;
		for(i=start;i<n;i++){
			if(cap < a[i]){
				box--;
				cap = k;
				i--;
				if(box == 0){break;}
			}else{
				cap -= a[i];
			}
		}
		if(box == 0){
			kanan = mid-1;
		}else{
			ans = mid;
			kiri = mid+1;
		}
	}
	printf("%d\n",ans);
	return 0;
};