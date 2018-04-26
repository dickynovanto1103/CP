#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n = 1, i;
	int prime[] = {2,3,5,7};
	for(i=0;i<4;i++){
		cout<<"Q "<<prime[i]<<flush<<endl;
		int bil;
		cin>>bil;
		for(int j=0;j<bil;j++){
			n*=prime[i];
		}
	}
	printf("A %d\n",n);
	return 0;
};