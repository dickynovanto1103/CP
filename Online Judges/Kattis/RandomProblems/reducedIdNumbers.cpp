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

const int maxn = 301;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn];
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	for(int mod=1;mod<=1000000;mod++){
		set<int> s;
		bool isDuplicated = false;
		for(i=0;i<n;i++){
			int bil = a[i]%mod;
			if(s.count(bil)){
				isDuplicated = true;
				break;
			}
			s.insert(bil);
		}
		if(!isDuplicated){printf("%d\n", mod);return 0;}
	}
	int kiri = 1, kanan = 1e6,mid, ans;
	while(kiri <= kanan) {
		mid = (kiri + kanan) / 2;
		set<int> s;
		bool isDuplicated = false;
		for(i=0;i<n;i++){
			int bil = a[i]%mid;
			if(s.count(bil)){
				isDuplicated = true; break;
			}
			s.insert(bil);
		}
		if(isDuplicated){
			kiri = mid+1;
		}else{
			ans = mid;
			kanan = mid-1;
		}
	}
	printf("%d\n",ans);
	return 0;
};