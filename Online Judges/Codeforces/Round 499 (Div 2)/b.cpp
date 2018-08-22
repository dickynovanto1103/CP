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

const int maxn = 1e2 + 2;

int main(){
	int n,m,i,j;
	int counter[maxn];
	scanf("%d %d",&n,&m);
	memset(counter, 0, sizeof counter);
	for(i=0;i<m;i++){
		int bil;
		scanf("%d",&bil);
		counter[bil]++;
	}
	int maks = 0;
	for(i=1;i<=100;i++){
		maks = max(maks, counter[i]);
	}
	int kiri = 0, kanan = maks, mid, ans;
	int temp[maxn];
	while(kiri<=kanan){
		mid = (kiri+kanan)/2;
		for(i=1;i<=100;i++){
			temp[i] = counter[i];
		}
		bool valid = true;
		for(i=0;i<n;i++){
			bool ketemu = false;
			for(j=1;j<=100;j++){
				if(temp[j] >= mid){
					temp[j] -= mid;
					ketemu = true;
					break;
				}
			}
			if(!ketemu){
				valid = false; break;
			}
		}
		if(valid){
			ans = mid;
			kiri = mid+1;
		}else{
			kanan = mid-1;
		}
	}
	printf("%d\n",ans);
	return 0;
};