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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		int n,i,j;
		string s;
		cin>>n>>s;
		printf("%d ",tt);
		for(i=0;i<s.size();i++){
			if(i == n-1){
				continue;
			}else{
				printf("%c",s[i]);
			}
		}
		printf("\n");
	}
	return 0;
};