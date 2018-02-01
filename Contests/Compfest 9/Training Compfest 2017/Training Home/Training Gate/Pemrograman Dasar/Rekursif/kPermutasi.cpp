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
	int n,k,a[10],i,j;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){a[i] = i+1;}
	do{
		for(i=0;i<n-1;i++){
			if(abs(a[i]-a[i+1])>k){break;}
		}
		if(i==n-1){
			for(i=0;i<n;i++){
				if(i){printf(" ");}
				printf("%d",a[i]);
			}
			printf("\n");
		}
	}while(next_permutation(a,a+n));
	return 0;
}