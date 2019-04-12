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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[n+1];
	for(i=1;i<=n;i++){
		int bil;
		scanf("%d",&bil);
		a[i] = bil;
		if(i == 1 && bil != 1){printf("-1\n"); return 0;}
	}

	for(i=1;i<=n;i++){
		if(i < a[i]){printf("-1\n"); return 0;}
	}

	printf("1");
	bool marked[n+1];
	memset(marked, false, sizeof marked);
	marked[1] = true;
	queue<int> q; //idx
	int cnt = 2;
	int prev = -1;
	for(i=n;i>=2;i--){
		if(a[i] > cnt){q.push(i);}
		else if(a[i] == cnt){
			if(a[i] <= prev){
				printf(" %d",a[i]);
				cnt++;
				marked[i] = true;
			}else{
				q.push(i);
			}
		}else{
			printf(" %d",a[i]);
			cnt++;
			marked[i] = true;
		}
		prev = a[i];
		
		while(!q.empty()){
			int front = q.front(); q.pop();
			if(front < cnt){printf(" %d",a[front]); marked[front] = true; cnt++;}
			else{
				q.push(front);
			}
		}
	}

	return 0;
};