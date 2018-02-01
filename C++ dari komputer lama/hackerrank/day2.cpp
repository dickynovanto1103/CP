#include <bits/stdc++.h>

using namespace std;

int main(){
	double bil,ex,temp;
	int tip, tax,ans;
	scanf("%lf %d %d",&bil,&tip,&tax);
	temp=bil;
	ex=(temp*(double)tip/100.0);
	bil=bil+ex;
	//printf("The total meal cost is %lf dollars.\n",bil);
	ex=(temp*(double)tax/100.0);
	bil=bil+ex;
	//printf("The total meal cost is %lf dollars.\n",bil);
	ans=round(bil);
	printf("The total meal cost is %d dollars.\n",ans);
	return 0;
}