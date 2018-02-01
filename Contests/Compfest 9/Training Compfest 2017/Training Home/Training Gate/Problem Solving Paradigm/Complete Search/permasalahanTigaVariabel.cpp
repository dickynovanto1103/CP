#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int i,j,k,n,cnt=0;
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			if(i+j<=n){
				for(k=0;k<=n;k++){
					if(i+j+k==n){cnt++; break;}
				}
			}else{
				break;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}