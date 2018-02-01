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

int main() {
	int tc,n,m,i,j,k,l;
	ll a[101][101],money;
	scanf("%d",&tc);
	int test = 1;
	while(tc--){
		scanf("%d %d %lld",&n,&m,&money);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(i>0){a[i][j]+=a[i-1][j];}
				if(j>0){a[i][j]+=a[i][j-1];}
				if(i>0 && j>0){a[i][j]-=a[i-1][j-1];}
			}
		}
		ll maxarea = 0, uang = 0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				for(k=i;k<n;k++){
					for(l=j;l<m;l++){
						ll temp = a[k][l];
						if(i>0){temp-=a[i-1][l];}
						if(j>0){temp-=a[k][j-1];}
						if(i>0 && j>0){temp+=a[i-1][j-1];}
						if(temp>money){break;}
						else{
							ll luas = (k-i+1)*(l-j+1);
							if(luas>maxarea){
								maxarea = luas;
								uang = temp;
							}else if(luas==maxarea){uang = min(uang,temp);}
						}
					}
				}
			}
		}
		printf("Case #%d: %lld %lld\n",test++,maxarea,uang);
	}
	return 0;
}