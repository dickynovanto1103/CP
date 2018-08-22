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

int cnt1[27], cnt2[27];

bool isSame(){
	for(int i=0;i<26;i++){
		if(cnt1[i] != cnt2[i]){return false;}
	}
	return true;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	string kata1,kata2;
	cin>>kata1>>kata2;
	
	memset(cnt1,0,sizeof cnt1); memset(cnt2,0,sizeof cnt2);
	for(i=0;i<n;i++){
		int kar = kata1[i] - 'a';
		cnt1[kar]++;
	}
	for(i=0;i<n;i++){
		int kar = kata2[i] - 'a';
		cnt2[kar]++;
	}

	if(!isSame()){printf("-1\n"); return 0;}
	vi ans;
	for(i=n-1;i>=0;i--){
		char kar = kata2[i];
		// printf("kar: %c\n",kar);
		if(kar == kata1[i]){continue;}
		vi listIdx;
		for(j=i-1;j>=0;j--){
			if(kar == kata1[j]){
				// printf("j: %d\n",j);
				break;
			}
		}
		int idx = j;
		for(j=idx;j<i;j++){
			swap(kata1[j], kata1[j+1]);
			ans.pb(j);
		}
	}
	printf("%d\n",(int)ans.size());
	for(i=0;i<ans.size();i++){
		if(i){printf(" ");}
		printf("%d",ans[i]+1);
	}
	printf("\n");
	return 0;
};