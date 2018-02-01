#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i,k,sisa,cnt;
	scanf("%d %d",&n,&k);
	sisa=4*60-k;
	cnt=1;
	i=1;
	while(sisa>=i*5){
		sisa-=i*5;
		cnt++;
		if(cnt>n){break;}
		i++;
	}
	cnt--;
	printf("%d\n",cnt);
	return 0;
}