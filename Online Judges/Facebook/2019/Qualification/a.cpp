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
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		string s;
		cin>>s;
		int n = s.length();
		int cntB = 0;
		for(i=1;i<n;i++){
			if(s[i] == 'B'){cntB++;}
		}
		int minim = n/2;
		int maks = n-2;
		if(cntB >= minim && cntB <= maks) {
			printf("Y\n");
		}else{
			printf("N\n");
		}
	}
	return 0;
};