#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int tc,i,j,a[100010],n;
	scanf("%d",&tc);
	int test = 1;
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		int ans, kiri = 0, kanan = inf, mid;
		while(kiri<=kanan){
			mid = (kiri+kanan)/2;
			int bil = 0, i=0;
			bool found = true;
			int k = mid;
			while(i<n && found){
				if(a[i]-bil>k){found = false;}
				else if(a[i]-bil == k){k--;}
				bil = a[i];
				i++;
			}
			if(found){ans = mid; kanan = mid-1;}
			else{kiri = mid+1;}
		}
		printf("Case %d: %d\n",test++,ans);
	}
	return 0;
}
