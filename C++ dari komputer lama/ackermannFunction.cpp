#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,l,r,v,len,i,temp,j,cnt,bil,curcnt,ansbil;
	while(scanf("%d %d",&a,&b),(a||b)){
		
		if(a>b){
			temp=a;
			a=b;
			b=temp;
		}
		printf("Between %d and %d, ",a,b);
		j=0;
		ansbil=a;
		
		curcnt=0;
		for(i=a;i<=b;i++){
			if(i==0){continue;}
			bil=i;
			cnt=0;
			//printf("bil: %d ",bil);
			do{
				if(bil%2==0){bil/=2;}
				else{bil=bil*3+1;}
				//printf("%d ",bil);
				cnt++;
			}while(bil>1);

			
			if(i==1){cnt=3;}
			//printf("cnt: %d curcnt: %d\n",cnt,curcnt);
			if(cnt>curcnt){
				curcnt=cnt;ansbil=i;
			}
			//printf("curcnt skrg: %d, ansbil: %d\n",curcnt,ansbil);
		}
		printf("%d generates the longest sequence of %d values.\n",ansbil,curcnt);
	}
	return 0;
}