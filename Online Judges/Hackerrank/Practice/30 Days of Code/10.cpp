#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,i;
	vector<int> a;
	scanf("%d",&n);
	//printf("binary representation of %d: ",n);
	while(n>0){
		int remainder = n%2;
		n/=2;
		a.push_back(remainder);
	}
	
	int cnt =0, ans=-1;
	/*for(i=a.size()-1; i>=0;i--){
		printf("%d",a[i]);
	}**/
	//printf("\n");
	for(i=a.size()-1; i>=0;i--){
		if(a[i]==1){cnt++;}
		else{ans = max(ans,cnt); cnt=0;}
	}
	ans = max(ans,cnt);
	printf("%d\n",ans);
	return 0;
}