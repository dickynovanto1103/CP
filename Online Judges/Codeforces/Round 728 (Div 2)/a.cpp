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
	int a[102];
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			a[i] = i+1;
		}
		for(i=0;i<n-1;i+=2) {
			swap(a[i], a[i+1]);
		}
		if(n%2 == 1){
			swap(a[n-1], a[n-2]);
		}
		for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("%d", a[i]);
		}
		printf("\n");
	}
	
	return 0;
};