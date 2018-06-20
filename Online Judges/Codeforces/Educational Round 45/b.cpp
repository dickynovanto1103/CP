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

const int maxn = 2e5 + 3;
bool isVisited[maxn];
int n;

void dfs(int idx, int batas, int keKanan) {
	int i;
	queue<int> q;
	if(!isVisited[idx]){
		isVisited[idx] = true;
		// printf("idx: %d\n",idx);
		q.push(idx);
	}
	while(!q.empty()){
		int front = q.front(); q.pop();
		if(keKanan && (front+1)<=batas ){
			if(!isVisited[front+1]){
				isVisited[front + 1] = true;
				// printf("yang dipush: %d\n", front+1);
				q.push(front+1);
			}
		}
		if(!keKanan && ((front-1)>=batas)){
			if(!isVisited[front-1]) {
				isVisited[front-1] = true;
				// printf("yang dipush: %d\n", front-1);
				q.push(front-1);
			}
		}
	}
}


int main(){
	int k,i,j;
	int a[maxn];
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	sort(a,a+n);

	memset(isVisited,false,sizeof isVisited);
	for(i=1;i<n;i++){
		// printf("proses a[%d]: %d minus k: %d = %d\n",i,a[i], k, a[i]-k);
		int idx = lower_bound(a,a+n,a[i] - k) - a;

		// printf("idx: %d\n",idx);
		if(a[idx] < a[i]){
			int idxUpperBound = lower_bound(a,a+n,a[i]) - a;
			if(idx<i){
				//mark sampe i-1;
				dfs(idx,idxUpperBound-1,1);
				dfs(idxUpperBound-1,idx,0);
				// printf("coba dfs dari %d ke %d\n",idx,i-1);
			}	
		}
		
	}
	int cnt = 0;
	for(i=0;i<n;i++){
		if(!isVisited[i]){cnt++;}
	}
	printf("%d\n", cnt);
	return 0;
};