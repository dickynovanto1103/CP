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

const int maxn = 1e5 + 5;

int dx[] = {-1,1};
int dist[1000010];
bool isVisited[1000010];
bool isSpecial[1000010];

int main(){
	int n,i,j;
	int a[maxn];
	
	memset(isVisited,false,sizeof isVisited);
	memset(isSpecial,false,sizeof isSpecial);
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]); isSpecial[a[i]] = true;}
	queue<ii> q;
	dist[1] = 0; dist[1000000] = 0;
	q.push(ii(1,dist[1])); q.push(ii(1000000,dist[1000000]));
	int counter = 0;
	while(!q.empty()){
		ii front = q.front(); q.pop();
		int x = front.first, jarak = front.second;
		for(i=0;i<2;i++){
			int xbaru = x + dx[i];
			if(xbaru>=1 && xbaru<=1000000){
				if(!isVisited[xbaru]){
					isVisited[xbaru] = true;
					dist[xbaru] = dist[x] + 1;
					q.push(ii(xbaru,dist[xbaru]));
					if(isSpecial[xbaru]){
						isSpecial[xbaru] = false;
						counter++;
						// printf("masuk sini\n");
						if(counter==n){printf("%d\n",dist[xbaru]); return 0;}
					}
				}	
			}
			
		}
	}
	return 0;
};