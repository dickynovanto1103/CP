#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,tc,i,j,a[100010],sumkiri[100010],sumkanan[100010];
	scanf("%d",&tc);

	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		bool found = false;
		sumkiri[0] = 0;
		for(i=1;i<n;i++){sumkiri[i] = sumkiri[i-1]+a[i-1];}
		sumkanan[n-1] = 0;
		//sumkanan[n-1] = a[n-1];
		for(i=n-2;i>=0;i--){sumkanan[i] = sumkanan[i+1]+a[i+1];}
		/*for(i=0;i<n;i++){
			printf("i: %d, %d %d\n",i,sumkiri[i],sumkanan[i]);
		}*/
		for(i=0;i<n;i++){
			if(sumkiri[i] == sumkanan[i]){printf("YES\n"); found = true; break;}
		}
		if(!found){printf("NO\n");}
	}
	return 0;
}