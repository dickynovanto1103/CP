#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int N,i;
	int bil[100010];
	float ans;
	cin>>N;
	for(i=1;i<=N;i++){
		cin>>bil[i];
	}
	sort(bil,bil+N+1);

	if(N%2==0){
		printf("%.1f\n",((float)bil[N/2]+(float)bil[N/2+1])/2.0);
	}else{
		printf("%.1f\n",(float)bil[N/2+1]);
	}
	return 0;
}
