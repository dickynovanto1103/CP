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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int dist[10];

int di[10][10][10][10];

int bfs(int awal, int akhir, int a, int b) {
	queue<int> q;
	memset(dist, -1, sizeof dist);
	int i,j;
	vi d = {a,b};
	if(awal != akhir){
		dist[awal] = 0;	
		q.push(awal);
	}else{
		
		for(i=0;i<d.size();i++)	{
			int next = (d[i] + awal)%10;
			if(dist[next] == -1){
				dist[next] = 1;
				q.push(next);
			}
		}
	}
	
	
	
	while(!q.empty()){
		int front = q.front(); q.pop();
		for(i=0;i<d.size();i++){
			int next = (d[i] + front) % 10;
			if(dist[next] == -1){
				dist[next] = dist[front] + 1;
				q.push(next);
			}
		}
	}
	return dist[akhir];
}

void precompute() {
	int i,j,k,l;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			for(k=0;k<10;k++){
				for(l=0;l<10;l++){
					int jawab = bfs(i,j,k,l);
					if(jawab <= -1){
						di[i][j][k][l] = -1;
					}else{
						di[i][j][k][l] = max(jawab-1,0);
					}
					// di[i][j][k][l] = max(-1, jawab);
				}
			}
		}
	}
}

int main(){
	string s;
	int i,j,n;
	cin>>s;
	int ans[10][10];
	precompute();
	memset(ans, 0, sizeof ans);
	n = s.length();
	for(int t=0;t<n-1;t++){
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				if(ans[i][j] == -1){continue;}
				int jawab = di[s[t]-'0'][s[t+1]-'0'][i][j];
				if(jawab == -1){
					ans[i][j] = -1;
				}else{
					ans[i][j] += jawab;
				}
			}
		}
	}
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(j){printf(" ");}
			printf("%d",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
};