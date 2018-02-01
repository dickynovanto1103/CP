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
	int n,k,a[110],i;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	for(i=0;i<n;i++){
		if(a[i]>=8){
			k-=8;
			int sisa = a[i]-8;
			a[i+1] +=sisa;
		}
		else{k-=a[i];}
		if(k<=0){printf("%d\n",i+1); break;}
	}
	if(k>0){printf("-1\n");}
	return 0;
}