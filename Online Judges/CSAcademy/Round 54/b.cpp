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

string kata[100010];

int main(){
	int n,i,j;
	int cnt[256];
	memset(cnt,0,sizeof cnt);
	scanf("%d",&n);
	for(i=0;i<n;i++){cin>>kata[i]; cnt[kata[i][0]]++;}
	int ans = 0;
	for(i=0;i<n;i++){
		int pjg = kata[i].length();
		cnt[kata[i][0]]--;
		int idx;
		bool foundValid = true;
		for(j=0;j<pjg;j++){
			char kar = kata[i][j];
			if(cnt[kar]){cnt[kar]--;}
			else{idx = j; foundValid = false;break;}
		}
		if(foundValid){idx = pjg; ans++;}
		for(j=0;j<idx;j++){
			char kar = kata[i][j];
			cnt[kar]++;
		}
		cnt[kata[i][0]]++;
	}
	printf("%d\n",ans);
	return 0;
};