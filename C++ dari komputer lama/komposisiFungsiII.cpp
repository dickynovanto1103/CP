#include <cstdio>
#include <cmath>

using namespace std;

double fungsi(int a,int b, int i, int x,int k){
	if(i==k){
		return(abs(a*x+b));
	}else{
		return(abs(a*fungsi(a,b,i+1,x,k)+b));
	}
}

int main(){
	int a,b,x,k;
	scanf("%d%d%d%d",&a,&b,&k,&x);
	printf("%.0lf\n",fungsi(a,b,1,x,k));
	return 0;
}