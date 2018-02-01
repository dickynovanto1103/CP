#include <bits/stdc++.h>

using namespace std;

int main(){
	int i,n,a[3010],dif;
	bool found,arr[3010];
	while(scanf("%d",&n)!=EOF){
		memset(arr,false,sizeof arr);
		found=true;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		if(n==1){found=true;}
		
		for(i=1;i<n && found;i++){
			if(!(abs(a[i]-a[i-1])>=1 && abs(a[i]-a[i-1])<=n-1)){found=false;}
			else{arr[abs(a[i]-a[i-1])]=true;}
		}
		for(i=1;i<n && found;i++){
			if(arr[i]==false){found=false;}
		}
		if(found){printf("Jolly\n");}
		else{printf("Not jolly\n");}
	}
	return 0;
}