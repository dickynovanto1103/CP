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
	int n,q,i,j;
	int a[100010];
	scanf("%d %d",&n,&q);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	while(q--){
		int com, idx;
		scanf("%d",&com);
		if(com==1){
			int newVal;
			scanf("%d %d",&idx,&newVal);
			a[idx-1] = newVal;
		}else{
			int nilaiXor;
			scanf("%d %d",&idx,&nilaiXor);
			int sum = 0, cnt = 0;
			for(i=0;i<idx;i++){
				sum^=a[i];
				//printf("sum: %d\n",sum);
				if(sum==nilaiXor){cnt++;}
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
};