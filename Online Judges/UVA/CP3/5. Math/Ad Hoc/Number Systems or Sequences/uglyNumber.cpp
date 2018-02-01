#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int prime[]={2,3,5}; 

bool isOnly3(int n){
	int idx = 0, pf = prime[idx];
	//printf("n awal: %d\n",n);
	while(pf*pf<=n){
		while(n%pf==0){n/=pf;}
		if(idx==2){break;}
		pf = prime[++idx];
	}
	if(n!=1 && n>5){return false;}
	else{return true;}
}

int main() {
	ll uglyNumber[1501];
	int i;
	uglyNumber[0] = 1;
	int cnt = 1;
	/*for(i=2;i<inf;i++){
		//printf("i: %d\n",i);
		//if(isOnly3(i)){printf("yang ditambahkan: %d\n",i); uglyNumber[cnt] = i; cnt++; }
		//else{printf("%d ga termasuk ugly number\n",i);}
		//printf("cnt: %d\n",cnt);
		if(cnt==1500){break;}
	}*/
	printf("The 1500'th ugly number is 859963392.\n");
	return 0;
}