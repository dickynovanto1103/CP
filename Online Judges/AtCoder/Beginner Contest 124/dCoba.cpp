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
 
string kata;

int n;

int main(){
	int k,i,j;
	
	scanf("%d %d",&n,&k);
	cin>>kata;
	
	int cnt = 0, cnt1 = 0;
	set<ii> s, s1;
	int maks = 0;
	for(i=0;i<n;i++){
		if(kata[i] == '0'){
			if(cnt1){
				maks = max(maks, cnt1);
				s1.insert(ii(i-cnt1,i-1));
				// printf("dipush 1 %d %d\n",i-cnt1, i-1);
				cnt1 = 0;
			}
			cnt++;
		}else if(kata[i] == '1') {
			cnt1++;
			if(cnt){
				s.insert(ii(i-cnt,i-1));
				// printf("dipush 0 %d %d\n",i-cnt, i-1);
				cnt = 0;
			}
		}
	}
	if(kata[i-1] == '0'){
		s.insert(ii(i-cnt, i-1));
		// printf("dipush 0 %d %d\n",i-cnt, i-1);
	}else{
		maks = max(maks, cnt1);
		s1.insert(ii(i-cnt1,i-1));
		// printf("dipush 1 %d %d\n",i-cnt1, i-1);
	}

	set<ii>::iterator it, it2;
	
	
	printf("%d\n",ans);
	return 0;
};