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

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int a,b;
		int maks;
		scanf("%d %d",&a,&b);
		if(__gcd(a,b) == 1){printf("Finite\n");}
		else{printf("Infinite\n");}
		// maks = max(a,b);
		// int minim = min(a,b);
		// bool vis[20001];
		// for(i=0;i<=20000;i++){vis[i] = false;}
		// vis[0] = true;
		// queue<int> q;
		// q.push(0);
		// while(!q.empty()){
		// 	int front = q.front(); q.pop();
		// 	if(front + a <= 20000 && !vis[front + a]){
		// 		vis[front + a] = true;
		// 		q.push(front + a);
		// 	}
		// 	if(front + b <= 20000 && !vis[front + b]){
		// 		vis[front + b] = true;
		// 		q.push(front + b);
		// 	}
		// }
		// int cnt = 0;
		// maks = 0;
		// for(i=0;i<=20000;i++){
		// 	if(!vis[i]){
		// 		maks = max(maks, cnt);
		// 		cnt = 0;
		// 	}else{
		// 		cnt++;
		// 	}
		// }
		// maks = max(maks, cnt);
		// if(maks >= minim){printf("Finite\n");}
		// else{printf("Infinite\n");}
	}
	return 0;
};