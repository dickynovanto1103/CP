#include <bits/stdc++.h>

using namespace std;
#define mininf -1000000000


int main(){
	int ans;
	int tc,n,maxbil,a,i;
	scanf("%d",&tc);
	while(tc--){
		ans=maxbil=mininf;
		i=0;
		scanf("%d",&n);
		while(n--){
			scanf("%d",&a);
			if(!i){maxbil=a;i++;}
			else{
				if(maxbil-a>ans) ans=maxbil-a;
				if(a>maxbil){maxbil=a;}
			}
		}
		printf("%d\n",ans);
	}
	return 0;	
}