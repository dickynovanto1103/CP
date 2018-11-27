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
	string kata;
	scanf("%d",&n);
	cin>>kata;
	int cnt[30];
	memset(cnt, 0, sizeof cnt);
	for(i=0;i<n;i++){
		char kar = kata[i];
		cnt[kar - 'a']++;
	}
	int cntLebihDari1 = 0;
	for(i=0;i<26;i++){
		if(cnt[i] > 0){cntLebihDari1++;}
	}
	if(cntLebihDari1 == 1){printf("NO\n");}
	else{
		printf("YES\n");
		for(i=0;i<(n-1);i++){
			if(kata[i] != kata[i+1]){
				printf("%c%c\n",kata[i],kata[i+1]);
				return 0;
			}
		}
	}
	return 0;
};