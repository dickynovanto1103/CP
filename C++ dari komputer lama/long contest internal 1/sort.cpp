#include <cstdio>

using namespace std;

int main(){
	int n,i,a[1004],temp;
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%d",&a[i]);}
	for(i=1;i<=n;i++){
		if(i%2==0){//genap
			if(a[i]<a[i-1]){
				temp=a[i]; a[i]=a[i-1]; a[i-1]=temp;
			}
		}else{
			if(i>1){
				if(a[i]>a[i-1]){
					temp=a[i]; a[i]=a[i-1]; a[i-1]=temp;
				}	
			}
		}
	}
	for(i=1;i<=n;i++){
		if(i==1){printf("%d",a[i]);}
		else{printf(" %d",a[i]);}
	}
	printf("\n");
	return 0;
}