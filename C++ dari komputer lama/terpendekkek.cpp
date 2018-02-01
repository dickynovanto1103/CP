#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> arr;

int main(){
	int N,K,i,temp;
	scanf("%d%d",&N,&K);
	while(N--){scanf("%d",&temp);arr.push_back(temp);}
	sort(arr.begin(),arr.end());
	printf("%d\n",arr[K-1]);
	return 0;
}