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
	int n;
	scanf("%d",&n);
	if(n<0){n = -n;}
	int sum = 0;
	while(n>0){
		int bil = n%10;
		sum+=bil;
		n/=10;
	}
	printf("%d\n",sum);
	return 0;
};