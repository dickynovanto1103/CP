#include <bits/stdc++.h>

using namespace std;

int a[600010];

int main(){
	int i;
	int cnt=0;
	while(scanf("%d",&a[cnt])!=EOF){
		cnt++;
	}
	bool isNaik;

	if(a[0]>=a[1]){isNaik = false;}//inisialisasi nilai bool
	else{isNaik = true;}
	int cur = a[0];
	int ans = 0;
	for(i=0;i<cnt-1;i++){
		if(a[i+1] > a[i]){
			if(!isNaik){
				//curmax = a[i+1];	
				isNaik= true;
				ans = max(ans,abs(cur-a[i]));
				cur = a[i];
			}
		}else if(a[i+1] < a[i]){
			if(isNaik){
				isNaik = false;
				ans = max(ans,abs(cur-a[i]));
				cur = a[i];
			}
		}
	}
	ans = max(ans,abs(cur-a[i]));
	printf("%d\n",ans);
	return 0;
}