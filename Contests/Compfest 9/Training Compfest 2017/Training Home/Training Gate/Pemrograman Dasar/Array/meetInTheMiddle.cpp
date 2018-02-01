#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,a[110],i,j;

	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	i=0; j = n-1;
	vi b;
	while(i<=j){
		if(i==j){b.pb(a[i]); break;}
		else{b.pb(a[i]); b.pb(a[j]); i++; j--;}	
	}
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",b[i]);
	}
	printf("\n");
	return 0;
}