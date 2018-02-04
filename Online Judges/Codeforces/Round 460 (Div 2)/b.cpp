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

int sumBil(int n){
	int sum = 0;
	while(n>0){
		int bil = n%10;
		sum+=bil;
		n/=10;
	}
	return sum;
}

int main(){
	int cnt = 0;
	int idx,i;
	scanf("%d",&idx);
	for(i=10;i<100000000;i++){
		if(sumBil(i)==10){
			cnt++;
			// printf("bil: %d\n",i);
			if(cnt==idx){
				printf("%d\n",i);
				return 0;
			}
		}
	}
	return 0;
};