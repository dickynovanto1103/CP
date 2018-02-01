#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int a[32],b[32],c[32],n;

int main() {
	int tc,ax,bx,cx,i;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d %d",&ax,&bx,&cx,&n);
		string kata;
		for(i=0;i<n;i++){cin>>kata; scanf("%d %d %d",&a[i],&b[i],&c[i]);printf("%d %d %d\n",a[i],b[i],c[i]);}
	}
	return 0;
}