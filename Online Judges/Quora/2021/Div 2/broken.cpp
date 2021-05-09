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

vi parseString(string s) {
	vi a;
	int num = 0;
	for(int i=0;i<s.length();i++){
		if(s[i] == ' '){
			if(num > 0) {
				a.pb(num);	
			}
			
			num = 0;
		}else if(s[i] == '-' && s[i+1] == '1'){
			i++;
		}else{
			num *= 10;
			num += s[i] - '0';
		}
	}
	if(num > 0) {
		a.pb(num);	
	}
	return a;
}

int main(){
	int n,i,j;
	scanf("%d\n",&n);
	string str;
	// cin>>s;
	srand(time(NULL));

	for(i=0;i<n;i++){
		// printf("i: %d n: %d\n",i, n);
		getline(cin, str);
		set<int> s;
		set<int>::iterator it;
		vi ans = parseString(str);
		for(j=0;j<ans.size();j++){
			s.insert(ans[j]);
		}
		// printf("str:\n");
		// cout<<str<<endl;
		int maxTambahan = 0;
		for(j=10;j<1000;j++){
			if(s.find(j) == s.end()){
				s.insert(j);
				maxTambahan--;
				if(maxTambahan <= 0){
					break;
				}
			}
		}
		// for(int val : ans){
		// 	s.erase(val);
		// }

		vi sisa;
		for(it=s.begin();it!=s.end();it++){
			sisa.pb(*it);
		}
		int bilRand = rand()%sisa.size();
		// printf("i: %d\n",i);

		cout<<sisa[bilRand]<<endl;
	}
	
	return 0;
};