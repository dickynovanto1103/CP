#include <bits/stdc++.h>

using namespace std;

int N,numbercd, memo[1000000],a[25],listtrack[25];
vector <int> id,fix;
/*int knapsack(int type, int sisa){
	int bil1,bil2;
	if(sisa==0 || type ==numbercd){return 0;}
	else if(memo[sisa]!=-1){return memo[sisa];}
	else if(sisa < a[type]){return memo[sisa]=knapsack(type+1,sisa);}
	else{
		return memo[sisa] = max(knapsack(type+1,sisa),a[type]+knapsack(type+1,sisa-a[type]));
	}
}*/

int main(){
	int i,ans,j,sum;
	while(scanf("%d",&N)!=EOF){
		//memset(memo,-1,sizeof memo);
		scanf("%d",&numbercd);
		for(i=0;i<numbercd;i++){scanf("%d",&a[i]);}
		/*for(i=0;i<numbercd;i++){printf("%d ",a[i]);}
		printf("\n");*/
		//ans=knapsack(0,N);
		ans=-1;
		for(i=1;i<(1<<numbercd);i++){
			sum=0; id.clear();
			for(j=0;j<numbercd;j++){
				if(i & (1<<j)){id.push_back(a[j]);sum+=a[j];}
			}
			if(sum>ans && sum <=N){ans=sum; fix.clear(); for(j=0;j<id.size();j++){fix.push_back(id[j]);}}
			
		}
		//for(i=0;i<id.size();i++){printf("%d ",id[i]);}
		for(i=0;i<fix.size();i++){printf("%d ",fix[i]);}
		printf("sum:%d\n",ans);
		fix.clear();
	}
	return 0;
}
