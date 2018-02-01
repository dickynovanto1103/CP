#include <bits/stdc++.h>

using namespace std;
#define inf 10000000
int main(){
	int tc,i,j,k,l,m,a[51][51],r,c,jarak,sum,ans,idx;
	char kata[51][51];
	bool found;
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		found=true; ans=inf;
		scanf("%d %d",&r,&c);
		for(j=0;j<r;j++){
			scanf("%s",kata[j]);
		}

		for(j=0;j<c && found;j++){
			sum=0;
			for(l=0;l<r;l++){
				
				jarak=inf; idx=inf;
				for(k=j;k>=0;k--){if(kata[l][k]=='0'){idx=k; break;}}

				jarak=min(jarak,abs(idx-j));
				//printf("pertama idx: %d j: %d jarak: %d\n",idx,j,jarak);
				idx=inf;
				for(k=j;k<c;k++){if(kata[l][k]=='0'){idx=k; break;}}
				jarak=min(jarak,abs(idx-j));
				//printf("kedua idx: %d j: %d jarak: %d\n",idx,j,jarak);
				sum+=jarak;
				//printf("sum: %d\n",sum);
			}
			//printf("sum total: %d\n",sum);
			if(sum>=10000000-110){found=false;}
			ans=min(ans,sum);
		}
		if(!found){ans=-1;}
		
		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}