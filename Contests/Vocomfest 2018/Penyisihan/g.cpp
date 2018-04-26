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

struct pasangan{
	ll awal, akhir;
};

pasangan pas[10];

bool cmp(pasangan a, pasangan b){
	if(a.awal == b.awal){return a.akhir < b.akhir;}
	return a.awal < b.awal;
}

ll convertYearToSecond(ll a){
	return a*20LL*50LL*24LL*60LL*60LL;
}

ll convertMonthToSecond(ll a){
	return a*50LL*24LL*60LL*60LL;	
}

ll convertDayToSecond(ll a){
	return a*24LL*60LL*60LL;	
}

ll convertHourToSecond(ll a){
	return a*60LL*60LL;
}

ll convertMinuteToSecond(ll a){
	return a*60LL;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		ll a[15];

		for(i=0;i<4;i++){
			for(j=0;j<12;j++){
				scanf("%lld",&a[j]);
			}
			pas[i].awal = convertYearToSecond(a[2]) + convertMonthToSecond(a[1]) + convertDayToSecond(a[0]) + convertHourToSecond(a[3]) + convertMinuteToSecond(a[4]) + a[5];
			pas[i].akhir = convertYearToSecond(a[2+6]) + convertMonthToSecond(a[1+6]) + convertDayToSecond(a[0+6]) + convertHourToSecond(a[3+6]) + convertMinuteToSecond(a[4+6]) + a[5+6];
			// printf("pas[%d].awal: %lld pas[%d].akhir: %lld\n",i,pas[i].awal,i,pas[i].akhir);	
			// if(i==3){
				
			// }
			
		}

		sort(pas,pas+3,cmp);
		// printf("setelah terurut\n");
		bool isCollide = false;
		for(i=0;i<3;i++){
			if((pas[i].akhir < pas[3].awal && pas[i].awal < pas[3].awal) || (pas[i].awal > pas[3].akhir && pas[i].akhir > pas[3].akhir)){continue;}
			else{isCollide = true;}
			// if(pas[i].akhir >= pas[3].awal && pas[]){isCollide = true; break;}
			
			// printf("pas[%d].awal: %lld pas[%d].akhir: %lld\n",i,pas[i].awal,i,pas[i].akhir);	
		}
		if(isCollide){printf("COLLIDE\n");}
		else{printf("OK\n");}
		// printf("terakhir pas[%d].awal: %lld pas[%d].akhir: %lld\n",3,pas[3].awal,3,pas[3].akhir);	
		
	}
	return 0;
};