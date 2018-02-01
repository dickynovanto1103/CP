#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc,i,hh1,hh2,mm1,mm2;
	string kata1,kata2;
	char kar1,kar2;
	int sum1, sum2;
	scanf("%d",&tc);
	while(tc--){
		cin>>kata1>>kata2;
		hh1 = (kata1[0]-'0')*10 + (kata1[1]-'0');
		hh2 = (kata2[0]-'0')*10 + (kata2[1]-'0');
		mm1 = (kata1[3]-'0')*10 + (kata1[4]-'0');
		mm2 = (kata2[3]-'0')*10 + (kata2[4]-'0');
		kar1 = kata1[5]; kar2 = kata2[5];
		if(hh1==12){hh1 = 0;}
		if(hh2==12){hh2 = 0;}
		sum1 = hh1*60 + mm1;
		sum2 = hh2*60 + mm2;

		if(kar1=='P'){sum1 += 12*60;}
		if(kar2=='P'){sum2 += 12*60;}
		if(sum1 > sum2){printf("First\n");}
		else{printf("Second\n");}
	}
	return 0;
}