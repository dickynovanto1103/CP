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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	string s;
	int m;
	cin>>s;
	scanf("%d",&m);
	while(m--){
		int l, r, k;
		scanf("%d %d %d",&l,&r,&k);
		l--;r--;
		int len = r - l + 1;
		string sub = s.substr(l, len);
		string temp;
		for(int i=0;i<len;i++) {
			temp += " ";
		}

		for(int i=0;i<len;i++){
			int newIdx = (i + k)%len;
			temp[newIdx] = sub[i];
		}

		int idx = 0;
		for(int i=l;i<=r;i++){
			s[i] = temp[idx++];
		}
	}

	cout<<s<<endl;
	
	return 0;
};