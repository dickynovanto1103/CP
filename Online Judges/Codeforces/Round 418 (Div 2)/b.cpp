#include <bits/stdc++.h>

using namespace std;

bool isAllOnce(int a[], int n){
	int cnt = 0;
	int listidx[n+1];
	for(int i=0;i<n;i++){listidx[i] = 0;}
	for(int i=0;i<n;i++){
		listidx[a[i]]++;
		if(listidx[a[i]]==2){return false;}
	}
	return true;
}

int main(){
	int n,i,j,a[1010],b[1010],p[1010];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]); p[i] = a[i];}
	for(i=0;i<n;i++){scanf("%d",&b[i]);}

	int listidx[1010], cnt=0;
	for(i=0;i<n;i++){
		if(a[i]!=b[i]){listidx[cnt] = i; cnt++;}
	}
	/*for(i=0;i<cnt;i++){
		printf("listidx[%d] = %d\n",i,listidx[i]);
	}*/
	if(cnt==1){
		int idx = listidx[0];
		for(i=1;i<=n;i++){
			if(i!=a[idx] && i!=b[idx]){p[idx] = i; break;}
		}
	}else{
		bool found = false;
		for(i=0;i<cnt;i++){
			int idx = listidx[i];
			p[idx] = b[idx];
			if(isAllOnce(p,n)){ found = true; break;}
			else{p[idx] = a[idx];}
			//printf("p[%d] = %d\n",idx,p[idx]);
		}
		if(!found){
			for(i=0;i<n;i++){p[i] = b[i];}//coba ganti ke a
			for(i=0;i<cnt;i++){
				int idx = listidx[i];
				p[idx] = a[idx];
				if(isAllOnce(p,n)){ found = true; break;}
				else{p[idx] = b[idx];}
				//printf("p[%d] = %d\n",idx,p[idx]);
			}	
		}
	}
	for(j=0;j<n;j++){
		if(j>0){printf(" ");}
		printf("%d",p[j]);
	}
	printf("\n");
	
	return 0;
}