#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n,a[25], memo[22][210];

int solve(int id, int val){
	if(id==n || val==0){return 0;}
	if(val < a[id]){return solve(id+1, val);}
	if(memo[id][val]!=-1){return memo[id][val];}
	return memo[id][val] = max(solve(id+1,val), a[id] + solve(id+1, val-a[id]));
}

int main() {
	int tc,i,j;
	string kata;
	scanf("%d",&tc);
	cin>>ws;
	while(tc--){
		getline(cin,kata);
		int ukuran = kata.length();
		int bil = 0;
		int cnt = 0;
		for(i=0;i<ukuran;i++){
			if(kata[i]==' '){a[cnt] = bil; bil=0; cnt++;}
			else{bil*=10; bil+=kata[i]-'0';}
		}
		a[cnt] = bil;
		cnt++;
		n = cnt; int total = 0;
		for(i=0;i<n;i++){	
			total+=a[i];
		}
		if(total%2==1){printf("NO\n");}
		else{
			memset(memo,-1,sizeof memo);
			int jawab = solve(0,total/2);
			int jawab2 = total-jawab;
			if(jawab==jawab2){printf("YES\n");}
			else{printf("NO\n");}
		}
		//cout<<kata<<endl;
	}
	return 0;
}