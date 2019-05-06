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
	int n,i,j;
	n = s.length();
	string s1 = "", s2 = "";
	bool is0 = false;
	for(i=0;i<n;i++){
		if(is0){
			s1 += '0';
			s2 += '1';
			is0 = false;
		}else{
			s1 += '1';
			s2 += '0';
			is0 = true;
		}
	}
	int ans1 = 0, ans2 = 0;
	for(i=0;i<n;i++){
		if(s1[i] != s[i]){ans1++;}
		if(s2[i] != s[i]){ans2++;}
	}
	printf("%d\n",min(ans1,ans2));
	return 0;
};