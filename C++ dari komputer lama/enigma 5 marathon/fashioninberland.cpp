#include <cstdio>

using namespace std;

int main(){
	int n,a[1000],i,count0;
	bool found = true;
	scanf("%d",&n);
	count0=0;
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	if(n==1){
		if(a[0]==0){found=false;}
	}else{
		for(i=0;i<n;i++){
			if(a[i]==0){count0++;}
			if(count0>1){found=false;break;}
		}
		if(count0==0){found=false;}
	}
	if(found){printf("YES\n");}
	else{printf("NO\n");}
	return 0;
}