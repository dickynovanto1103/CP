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
	int tc,i,j,n;
	string s;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		scanf("%d",&n);
		
		cin>>s;
		char lastChar = s[0];	
		int lastAns = 1;
		printf("1");	
		for(i=1;i<n;i++){
			if(s[i] > lastChar){
				lastChar = s[i];
				lastAns++;
			}else{
				lastChar = s[i];
				lastAns = 1;
			}
			printf(" %d", lastAns);
		}
		printf("\n");
	}
	
	return 0;
};