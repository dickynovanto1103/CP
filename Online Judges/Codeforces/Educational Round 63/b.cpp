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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	string kata;
	scanf("%d",&n);
	cin>>kata;
	vi list8, listGa8;
	bool vis[100010];
	memset(vis, false, sizeof vis);
	for(i=0;i<n;i++){
		if(kata[i] == '8'){list8.pb(i); }
		else{listGa8.pb(i); }
	}
	reverse(listGa8.begin(), listGa8.end()); reverse(list8.begin(), list8.end());
	int move = (n - 11) / 2;
	for(i=0;i<move;i++){
		if(list8.size() == 0){printf("NO\n"); return 0;}
		if(listGa8.size() == 0){printf("YES\n"); return 0;}
		// printf("true 8; %d ga8: %d\n",list8.back(), listGa8.back());
		vis[list8.back()] = true; vis[listGa8.back()] = true;
		list8.pop_back(); listGa8.pop_back();
	}
	int idx = -1;
	for(i=0;i<n;i++){
		if(!vis[i]){idx = i; break;}
	}
	for(i=0;i<list8.size();i++){
		if(list8[i] == idx){printf("YES\n"); return 0;}
	}
	printf("NO\n");
	return 0;
};