#include <bits/stdc++.h>

using namespace std;
string memo[36];
string f(int N) {
  if (N == 0) return "a";
  if (N == 1) return "b";
  if (N == 2) return "c";
  if(memo[N]!=""){
  	return memo[N];
  }
  return (memo[N] = f(N - 1) + f(N - 2) + f(N - 3));
}

int main(){

	for(int i=0;i<=35;i++){memo[i]="";}
	int n,k,i;
	string listkata[36];
	for(int i=0;i<=35;i++){listkata[i]="";}
	listkata[0] = "a"; listkata[1] = "b"; listkata[2] = "c";
	for(i=3;i<=35;i++){
		listkata[i] = listkata[i-1]+listkata[i-2]+listkata[i-3];
		//cout<<listkata[i]<<" i: "<<i<<endl;
	}
	//printf("test\n");
	scanf("%d %d",&n,&k);
	string kata = listkata[n];
	cout<<"kata: "<<kata<<endl;
	printf("panjang kata: %d\n",kata.length());
	k--;
	
	printf("%c\n",kata[k]);
	return 0;
}