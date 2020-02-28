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
	string s;
	int i,j;
	cin>>s;
	int pjg = s.length();
	int cnt = 0;
	int ans = -1;
	for(i=0;i<pjg;i++){
		if(s[i] == '1') {
			ans = i;
			break;
		}
	}
	if(ans == -1){
		printf("0\n");
		return 0;
	}

	for(i=pjg-1;i>=ans;i-=2){
		cnt++;	
	}
	if(i == ans-2){
		int cnt1 = 0;
		for(i=ans+1;i<pjg;i++){
			if(s[i] == '1'){
				cnt1++;
			}
		}
		if(cnt1){

		}else{
			cnt--;
		}
	}
	printf("%d\n",cnt);
	return 0;
};