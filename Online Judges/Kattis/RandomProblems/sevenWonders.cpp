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

int main(){
	string s;
	cin>>s;
	int i,j;
	int cntT=0, cntC=0, cntG = 0;
	for(i=0;i<s.length();i++){
		if(s[i] == 'T'){cntT++;}
		else if(s[i] == 'C'){cntC++;}
		else{cntG++;}
	}
	int ans = cntT*cntT + cntG*cntG + cntC*cntC;
	int minim = min(cntT, min(cntC, cntG));
	ans += 7*minim;
	printf("%d\n",ans);
	return 0;
};