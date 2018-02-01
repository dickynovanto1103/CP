#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main(){
	int tc,n,i,j,k,awal,akhir,ans,temp;
	vector <int> a;
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		scanf("%d %d",&n,&k);
		for(j=0;j<n;j++){
			scanf("%d",&temp);
			a.push_back(temp);
		}
		//printf("array belum terurut\n");
		//for(j=0;j<n;j++){cout<<a.at(j)<<" ";}
		sort(a.begin(),a.end());
		//printf("array terurut\n");
		//for(j=0;j<n;j++){printf("%d ",a[j]);}
		//printf("\n");
		awal=akhir=ans=0;
		//printf("k: %d\n",k);
		while(akhir<n){
			//printf("awal: %d, akhir: %d, a awal: %d, a akhir: %d\n",awal,akhir,a[awal],a[akhir]);
			
			if(a[akhir]-a[awal]<=k){ans=max(ans,akhir-awal+1);akhir++;}
			else{awal++;}
			//printf("ans sekarang: %d\n",ans);
		}
		printf("Case #%d: %d\n",i,ans);
		a.clear();
	}
	return 0;
}