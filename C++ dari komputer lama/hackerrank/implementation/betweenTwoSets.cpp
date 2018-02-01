#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n,m,a[10],b[10],i,x,minim,maks,j,ans;
	scanf("%d %d",&n,&m);
	bool found = false;
	minim = 1000; maks = -1; ans = 0;
	for(i=0;i<n;i++){scanf("%d",&a[i]); minim = min(minim,a[i]);}
	for(i=0;i<m;i++){scanf("%d",&b[i]); maks = max(maks, b[i]);}
	for(x=minim;x<=maks;x++){
		found = false;
		for(i=0;i<n;i++){
			if(x % a[i] != 0){found = true; break;}
		}
		if(!found){
			for(i=0;i<m;i++){
				if(b[i] % x != 0){found = true; break;}
			}	
			//printf("found: %d x: %d\n",found,x);
			if(!found){ans++;}
		}
		
		

	}
	printf("%d\n",ans);
	return 0;
}