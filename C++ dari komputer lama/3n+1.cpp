#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main(){
	int a,b,i,bil,ans,cnt,temp;
	while(scanf("%d %d",&a,&b)!=EOF){
		ans=1;
		printf("%d %d ",a,b);
		if(a>b){
			temp=a;
			a=b;
			b=temp;
		}
		for(i=a;i<=b;i++){
			bil=i;cnt=1;
			//printf("bil: %d ",bil);
			while(bil!=1){
				if(bil%2==0){bil/=2;}
				else{bil=bil*3+1;}
				//printf("%d ",bil);
				cnt++;
			}
			//printf("\ncnt: %d ans: %d\n",cnt,ans);
			ans=max(ans,cnt);
		}
		printf("%d\n",ans);
	}
	return 0;
}