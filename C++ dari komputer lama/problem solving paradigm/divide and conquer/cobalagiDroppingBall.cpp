#include <cstdio>

using namespace std;

int maks;

int solve(int node, int ball){
	int left = node*2, right = left+1;
	if(left<maks && right<maks){
		if(ball%2==0){solve(right, ball/2);}
		else{solve(left,ball/2 + 1);}
	}else{return node;}
}

int main(){
	int n,i,d,ball;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&d,&ball);
		maks = 1<<d;
		printf("%d\n",solve(1,ball));
	}
	return 0;
}