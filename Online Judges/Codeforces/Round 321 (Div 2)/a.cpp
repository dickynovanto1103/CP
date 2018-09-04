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

const int maxn = 1e5 + 5;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int kiri = 0;
	int maks = 1;
	while(true){
		int bil = a[kiri];
		for(i=kiri+1;i<n;i++){
			if(a[i] < bil){
				break;
			}
			bil = a[i];
		}
		maks = max(maks, i-kiri);
		kiri = i;
		if(kiri == n){break;}
	}
	printf("%d\n",maks);
	
	return 0;
};