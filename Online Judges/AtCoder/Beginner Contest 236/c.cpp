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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

map<string, int> mapper;
bool isTrue[100019];

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	string a[100010], b[100010];
	for(int i=0;i<n;i++){
		cin>>a[i];
		mapper[a[i]] = i;
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
		int idx = mapper[b[i]];
		isTrue[idx] = true;
	}

	for(int i=0;i<n;i++){
		if(isTrue[i]){
			puts("Yes");
		}else{
			puts("No");
		}
	}
	
	return 0;
};