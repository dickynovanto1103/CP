#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i,j,tc,minim,idx,sum,ans;
	int a[10][10];
	int urutan[8];
	bool tag[10];
	scanf("%d",&tc);

	while(tc--){
		
		scanf("%d",&n);
		for(i=0;i<8;i++){urutan[i]=i;}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		idx=0;
		ans=1000000000;
		do{
			sum=0;
			/*printf("urutan:");
			for(i=0;i<n;i++){printf(" %d",urutan[i]);}
			printf("\n");*/
			memset(tag,true,sizeof tag);
			for(i=0;i<n;i++){
				minim=100000;
				//printf("untuk i: %d\n",i);
				for(j=0;j<n;j++){
					if(tag[j]){
						if(minim > a[urutan[i]][j]){
							idx=j;
							minim=a[urutan[i]][j];
							//printf("urutan i: %d j: %d idx sekarang: %d minim: %d\n",urutan[i],j,idx,minim);
						}
					}
				}
				tag[idx]=false;
				sum+=minim;
			}

			ans=min(ans,sum);
			//printf("sum: %d ans: %d\n",sum,ans);
		}while(next_permutation(urutan,urutan+n));
		
		printf("%d\n",ans);
	}
	return 0;
}