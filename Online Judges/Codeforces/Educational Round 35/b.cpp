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

int main(){
	int n,a,b,i;
	scanf("%d %d %d",&n,&a,&b);
	int minim = min(a,b);
	for(i=1;i<=minim;i++){
		int banyakDariA = a/i, banyakDariB = b/i;
		//printf("i: %d dari A: %d dariB: %d\n",i,banyakDariA,banyakDariB);
		if((banyakDariB+banyakDariA)>=n){
			continue;
		}else{
			break;
		}
	}
	printf("%d\n",i-1);
	return 0;
};