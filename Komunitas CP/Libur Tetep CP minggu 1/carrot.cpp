#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,t,k,d,i;
	scanf("%d %d %d %d",&n,&t,&k,&d);
	int cnt = 0;
	//cari waktu tanpa bikin oven
	int coban = n, cobak = k;
	int cycle = (int)(ceil((double)coban / (double)cobak));
	int time = t*cycle; //waktu untuk bikin tanpa tambahan oven
	//cari waktu dengan bikin oven
	//simulasi saja
	int totaltime = 0;
	int timer1 = t, timer2 = d;
	while(cnt<n){
		//if(t >= d){cnt=k; totaltime = t;}
		while(timer1 > timer2){
			//cetak kue dari oven kedua
			cnt+=k; timer2+=t;
		}
		totaltime = min(timer1,timer2);
		if(cnt>=n){break;}
		while(timer1 <= timer2){
			cnt+=k; timer1+=t;
		}
		totaltime = min(timer1,timer2);
		if(cnt>=n){break;}
	}
	/*printf("time tanpa oven: %d\n",time);
	printf("total time dengan oven: %d\n",totaltime);*/
	if(time <= totaltime){printf("NO\n");}
	else{printf("YES\n");}

	return 0;
}