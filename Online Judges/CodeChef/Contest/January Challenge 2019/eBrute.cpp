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
	int tc,i,j,k;
	int n,p;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&p);
		int maks = 0;
		int cntMaks = 0;
		for(i=1;i<=p;i++){
			for(j=1;j<=p;j++){
				for(k=1;k<=p;k++){
					int nilai = (((n%i)%j)%k)%n;
					if(nilai == maks){
						cntMaks++;
					}else if(nilai > maks){
						maks = nilai;
						cntMaks = 1;
					}
				}
			}
		}	
		printf("%d\n",cntMaks);
	}
	

	return 0;
};