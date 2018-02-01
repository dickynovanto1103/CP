#include <bits/stdc++.h>

using namespace std;

bool isseven(int bil){
	int a;
	if(bil%7==0){return true;}
	else{
		while(bil!=0){
			a=bil%10;
			if(a==7) return true;
			bil/=10;
		}
		if(bil==0) return false;	
		
	}
}

int main(){
	int n,m,k,i,j,cntorg=0;

	while(scanf("%d %d %d",&n,&m,&k),(n||m||k)){
		bool putar=false;
		i=cntorg=1;
		int counter=0;
		while(1){
			if(!putar){if(isseven(i) && cntorg==m){counter++;}cntorg++;}
			else{if(isseven(i) && cntorg==m){counter++;}cntorg--;}
			i++;
			if(cntorg==n+1){putar=true;cntorg=n-1;}
			else if(cntorg==0){putar=false;cntorg=2;}
			if(counter==k){printf("%d\n",--i);break;}
		}
	}
	return 0;
}