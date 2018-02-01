#include <cstdio>

using namespace std;

int main(){
	int N,i,a,b;
	scanf("%d",&N);
	int hasil=0;a=0;b=0;
	for(i=0;i<=N;i++){
		if(i==1){
			a=0;b=i;hasil=b;
		}else if(i==0){
			hasil=0;
		}
		else{
			hasil=a+b;
			a=b;
			b=hasil;
		}
	}
	printf("hasil: %d\n",hasil);
	return 0;
}