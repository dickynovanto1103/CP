#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000

int a[200010],ans[200010],idxnol[200010];
int main() {
	int n, i,j;
	scanf("%d",&n);
	j = 0;
	for(i=0;i<n;i++){scanf("%d",&a[i]); if(a[i]==0){idxnol[j] = i; j++;}}
	int cnt = j;
	int bil;
	/*printf("idxnol:");d
	for(i=0;i<cnt;i++){
		printf(" %d",idxnol[i]);
	}
	printf("\n");*/
	int t = inf;
	for(i=0;i<n;i++){
		if(a[i]==0){ans[i]=0; t=0;}
		else{
			t++;
			ans[i] = t;
			
		}
	}
	t = inf;
	for(i=n-1;i>=0;i--){
		if(ans[i]==0){t=0;}
		else{
			t++;
			ans[i] = min(ans[i], t);
				
		}
	}
	for(i=0;i<n;i++){
		if(i>0){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");

	return 0;
}