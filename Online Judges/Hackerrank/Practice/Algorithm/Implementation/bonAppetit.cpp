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
	int n,i,j,k;
	scanf("%d %d",&n,&k);
	int a[maxn];
	int sum = 0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]); 
		if(i == k){continue;}
		sum += a[i];
	}
	int b;
	scanf("%d",&b);
	int bagi2 = sum/2;
	if(bagi2 == b){
		printf("Bon Appetit\n");
	}else{
		printf("%d\n",abs(bagi2-b));
	}

	return 0;
};