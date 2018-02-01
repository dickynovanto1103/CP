#include <bits/stdc++.h>

using namespace std;
#define inf 1e18
typedef long long ll;
typedef vector<int> vi;
int main(){
	ll bil;
	ll arr[65];
	ll W;
	int i;
	for(i=0;i<=100;i++){
		if(pow(2,i)>1e18){break;}
		arr[i] = (ll)pow(2,i);
	}
	scanf("%lld",&W);
	
	//tentukan jumlah
	vi ans;
	for(i=59;i>=0;i--){
		if(arr[i]<=W){
			if(W==0){break;}
			else{W-=arr[i]; ans.push_back(i);}
		}
	}
	// printf("yang diambil idx: %d dengan nilai: %lld\n",i,arr[i]);
	reverse(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();i++){
		if(i>0){printf(" ");}
		printf("%d",ans[i]+1);
	}
	return 0;
}