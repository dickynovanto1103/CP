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
	int cnt[26];
	memset(cnt, 0, sizeof cnt);
	scanf("%d",&n);
	if(n==1){printf("Yes\n"); return 0;}
	string kata;
	cin>>kata;
	for(i=0;i<n;i++){
		char kar = kata[i];
		cnt[kar-'a']++;
	}
	for(i=0;i<26;i++){
		if(cnt[i]>=2){printf("Yes\n"); return 0;}
	}
	printf("No\n");
	return 0;
};