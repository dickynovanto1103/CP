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
	string s;
	int n,i,j;
	cin>>s;
	n = s.size();
	vi satu, dua;
	for(i=0;i<n-1;i++){
		if(s[i] == 'A' && s[i+1] == 'B'){satu.pb(i);}
		if(s[i] == 'B' && s[i+1] == 'A'){dua.pb(i);}
	}
	if(satu.size() ==0 || dua.size() == 0){printf("NO\n"); return 0;}
	for(i=0;i<satu.size();i++){
		int nilai = satu[i];
		int depan = dua.front(), bel = dua.back();
		if(abs(nilai - depan) > 1 || abs(nilai-bel) > 1){printf("YES\n"); return 0;}
	}
	printf("NO\n");
	
	return 0;
};