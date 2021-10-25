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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[2000];
	while(tc--){
		int h;
		scanf("%d %d",&n,&h);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a, a+n);
		int banyak = (h / (a[n-1] + a[n-2])) * 2;
		int sisa = h % (a[n-1] + a[n-2]);
		if(sisa == 0){

		}else if(sisa <= a[n-1]){
			banyak++;
		}else{
			banyak+=2;
		}

		printf("%d\n", banyak);
	}
	
	return 0;
};