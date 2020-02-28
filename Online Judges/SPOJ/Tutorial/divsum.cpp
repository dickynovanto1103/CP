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
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		ll sum = 0;
		for(i=1;i*i<=n;i++){
			if(n % i == 0){
				int satu = n/i;
				int dua = i;
				if(satu != dua){
					if(satu < n){sum += satu;}
					if(dua < n){sum += dua;}
				}else{
					if(satu < n){sum += satu;}
				}
				
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
};