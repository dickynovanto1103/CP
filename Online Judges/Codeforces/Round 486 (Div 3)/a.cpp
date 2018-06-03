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
	int n,k,i,j;
	set<int> s;
	vi listIdx;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		if(s.find(bil) == s.end()) {
			s.insert(bil);
			listIdx.pb(i+1);
			// printf("yang dipush: %d\n",i+1);
		}
	}
	// printf("ukuran: %d\n",(int)listIdx.size());
	if(listIdx.size()>=k) {
		printf("YES\n");
		for(i=0;i<k;i++){
			if(i){printf(" ");}
			printf("%d",listIdx[i]);
		}
		printf("\n");
	}else{
		printf("NO\n");
	}
	return 0;
};