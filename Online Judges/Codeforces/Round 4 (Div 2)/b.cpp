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
	int n,i,j,sum;
	int minTime[35], maxTime[35];
	scanf("%d %d",&n,&sum);
	int minimSum = 0, maksSum = 0;
	for(i=0;i<n;i++){
		scanf("%d %d",&minTime[i], &maxTime[i]);
		minimSum += minTime[i];
		maksSum += maxTime[i];
	}
	int ans[35], tempSum = 0, sisa[35];
	if(sum >= minimSum && sum <= maksSum){
		printf("YES\n");
		for(i=0;i<n;i++){
			ans[i] = minTime[i];
			tempSum+=ans[i];
		}
		if(tempSum < sum){
			int sisaUntukKeSum = sum - tempSum;
			for(i=0;i<n;i++){
				int tambahanUntukKeMax = maxTime[i] - ans[i];
				if(tambahanUntukKeMax < sisaUntukKeSum){
					sisaUntukKeSum -= tambahanUntukKeMax;
					ans[i] += tambahanUntukKeMax;
				}else{
					int tambah = sisaUntukKeSum;
					ans[i] += tambah;
					sisaUntukKeSum = 0;
				}
			}
		}
		for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("%d",ans[i]);
		}
		printf("\n");


	}else{
		printf("NO\n");
	}
	return 0;
};