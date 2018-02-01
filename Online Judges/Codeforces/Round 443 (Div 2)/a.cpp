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
	
	int n,i,j, mulai, jarak;
	scanf("%d",&n);
	ll ans;
	for(i=0;i<n;i++){
		scanf("%d %d",&mulai,&jarak);
		if(i==0){ans = mulai;}
		else{
			ll waktu = mulai;
			while(ans>=waktu){
				waktu+=jarak;
			}
			ans = waktu;
		}
	}
	printf("%lld\n",ans);
	// for(i=0;i<n;i++){
	// 	scanf("%d %d",&start[i],&d[i]);
	// 	if(!i){curwaktu = start[i];}
	// 	else{
	// 		int sum = start[i];
	// 		//printf("curwaktu: %d i:%d\n",curwaktu,i);
	// 		while(curwaktu>=sum){
	// 			//printf("sum: %d\n",sum);
	// 			sum+=d[i];
	// 		}
	// 		curwaktu = sum;
	// 		printf("curwaktu jd: %d\n",curwaktu);
	// 	}
	// }
	// printf("%d\n",curwaktu);
	
	return 0;
};