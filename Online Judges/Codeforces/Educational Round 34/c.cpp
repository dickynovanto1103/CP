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
	int a[5010];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int cnt = 0;
	bool isVisited[5010];
	memset(isVisited,false, sizeof isVisited);
	for(i=0;i<n;i++){
		int curMin = a[i];
		if(isVisited[i]){continue;}
		isVisited[i] = true;
		cnt++;
		for(j=i+1;j<n;j++){
			if(a[j]>curMin && !isVisited[j]){
				curMin = a[j];
				isVisited[j] = true;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
};

