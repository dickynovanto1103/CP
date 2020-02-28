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
	cin>>s;
	string hilangA, hilangB, hilangC;
	for(i=0;i<s.length();i++) {
		if(s[i] == 'a') {
			hilangB+=s[i];
			hilangC += s[i];
		}else if(s[i] == 'b'){
			hilangA += s[i];
			hilangC += s[i];
		}else{
			hilangA += s[i];
			hilangB += s[i];
		}
	}
	//consider hilang a
	int minim = s.length()/2;
	if(hilangA.size() >= minim){
		
	}
	return 0;
};