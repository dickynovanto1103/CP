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
	ll a[100010],m,k;
	int i,j,tc,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %d %lld",&m,&n,&k);
		for(i=0;i<n;i++){scanf("%lld",&a[i]);}
		ll volumeAwal = m;
		ll cnt = 0;
		while(true){
			for(i=0;i<n;i++){
				m+=k;
				//printf("m: %lld\n",m);
				if(a[i]<=m){//masih cukup...ambil saja airnya
					m-=a[i]; cnt++;
					//printf("m abis dikurangin a[%d] = %lld: %lld\n",i,a[i],m);
					if(m==0){break;}
				}
				else{break;}
				
			}
			//printf("m sekarang: %d\n",m);
			if(i<n){ printf("cnt: %d\n",cnt);break;}
			else{
				if(m>=volumeAwal){printf("ga berkurang coy\n");break;}
				if(m==0){printf("cnt: %d\n",cnt);break;}
			}
		}
	}
	return 0;
}