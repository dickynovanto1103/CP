#include <cstdio>

using namespace std;

int maks;

int solve(int node, int ball){
	int left = node*2;
	int right = left+1;
	if(left<maks && right<maks){
		if(ball%2==0){solve(right,ball/2);}
		else{solve(left,ball/2 + 1);}
	}else{return node;}
}

int main(){
	int tc,i,j,d,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&d,&n);
		maks = 1<<d;
		printf("%d\n",solve(1,n));
	}
	return 0;
}