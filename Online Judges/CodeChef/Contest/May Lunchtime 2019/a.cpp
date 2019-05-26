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

bool isVow(char kar) {
	return kar == 'a' || kar == 'i' || kar == 'u' || kar == 'e' || kar == 'o';
}

int main(){
	int tc,i,j;
	int n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		string kata;
		cin>>kata;
		int cnt = 0;
		for(i=0;i<n-1;i++){
			if(!isVow(kata[i]) && isVow(kata[i+1])) {
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
};