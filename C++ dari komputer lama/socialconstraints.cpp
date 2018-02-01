#include <bits/stdc++.h>

using namespace std;

int memo[10];

int fac(int n){
	if(n==0 || n==1){return 1;}
	else if(memo[n]!=-1){return memo[n];}
	else{return memo[n]=n*fac(n-1);}
}

int main(){
	int n,i,m,a[21],b[21],c[21],idxa,idxb,j,cnt,k;
	int arr[10];
	bool found;
	memset(memo,-1,sizeof memo);
	
	for(i=0;i<8;i++){arr[i]=i;}
	while(scanf("%d %d",&n,&m),(n||m)){
		cnt=0;
		for(i=0;i<m;i++){
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
		}
			//printf("untuk a: %d b: %d c: %d\n",a,b,c);
			do{
				found=true;
				//for(j=0;j<n;j++){printf("%d ",arr[j]);}
						
					for(i=0;i<m;i++){
						for(j=0;j<n;j++){
							if(arr[j]==a[i] || arr[j]==b[i]){break;}
						}
						if(arr[j]==a[i]){idxa=j;}
						if(arr[j]==b[i]){idxb=j;}
						for(k=j+1;k<n;k++){
							if(arr[k]==a[i] || arr[k]==b[i]){break;}
						}
						if(arr[k]==a[i]){idxa=k;}
						if(arr[k]==b[i]){idxb=k;}

						if(c[i]>0){
							if(abs(idxa-idxb)>abs(c[i])){found=false;}
						}else{
							if(abs(idxa-idxb)<abs(c[i])){found=false;}
						}
					}
					if(found){cnt++;}
					//printf("idxa: %d idxb: %d cnt: %d\n",idxa,idxb,cnt);
			}while(next_permutation(arr,arr+n));
			if(m==0){cnt=fac(n);}
			printf("%d\n",cnt);
		}
		
	
	return 0;
}