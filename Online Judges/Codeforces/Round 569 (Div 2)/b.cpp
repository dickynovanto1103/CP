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

int main(){
	int n,i,j;
	scanf("%d",&n);
	vi a(n);
	int cntNeg = 0, cnt0 = 0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i] >= 0){
			a[i] = -a[i] - 1;
		}
	}

	if(n & 1){
		//change the min
		int idxMin, minim = inf;
		for(i=0;i<n;i++){
			if(minim > a[i]){
				minim = a[i];
				idxMin = i;
			}
		}

		a[idxMin] = -a[idxMin] - 1;
		for(i=0;i<n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");

	}else{
		for(i=0;i<n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	
	return 0;
};