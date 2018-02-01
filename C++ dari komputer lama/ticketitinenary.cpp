#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n,tc,i,j,hh,mm,a;
	char kota[20],waktu[10];
	string kata[110];
	int gmt[110];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s %s",&kota,&waktu);
		kata[i]=(string)kota;
		a=0;
		for(j=4;j<strlen(waktu);j++){
			a*=10;
			a+=waktu[j]-'0';
		}
		if(waktu[3]=='-'){a*=-1;}
		gmt[i]=a;
		//printf("untuk kota %s diperoleh gmt : %d\n",kota,a);
	}
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		
	}
	return 0;
}