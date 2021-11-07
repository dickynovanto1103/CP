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

int hitung(string s, string subs) {
	int n = s.size();
	int cnt = 0;
	for(int i=0;i<n-1;i++){
		if(s[i] == subs[0] && s[i+1] == subs[1]) {
			cnt++;
		}
	}
	return cnt;
}

bool isSame(string s) {
	return hitung(s, "ab") == hitung(s, "ba");
}

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);
	while(tc--){
		string s;
		cin>>s;
		if(isSame(s)){
			cout<<s<<endl;
		}else{
			bool found = false;
			for(i=0;i<s.size();i++){
				char temp = s[i];
				s[i] = (s[i] == 'a' ? 'b': 'a');
				// printf("s[%d] jadi: %c, before: %c\n", i, s[i], temp);

				if(isSame(s)) {
					found = true;
					cout<<s<<endl;
					break;
				}

				s[i] = temp;
			}

			assert(found);
		}
	}
	
	return 0;
};