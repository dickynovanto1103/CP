#include <bits/stdc++.h>
using namespace std;

int main(){
	int bil,n,i,a[1000],x;
	scanf("%d %d",&n,&x);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	int patokan = 1000000000;
	int ans;
	for(i=0;i<n;i++){
		int selisih = abs(x-a[i]);
		if(patokan > selisih){
			patokan = selisih;
			ans = a[i];
		}else if(patokan == selisih){
			ans = min(ans,a[i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}