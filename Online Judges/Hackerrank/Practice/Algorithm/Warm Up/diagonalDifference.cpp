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
	int n,i,j;
	scanf("%d",&n);
	int sum1 = 0, sum2 = 0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			int bil;
			scanf("%d",&bil);
			if(i==j){sum1+=bil;}
			if((n-1-i)==j){
				//printf("yang ditambahkan: %d\n",bil);
				sum2+=bil;
			}
		}
	}
	printf("%d\n",abs(sum1-sum2));
	return 0;
};