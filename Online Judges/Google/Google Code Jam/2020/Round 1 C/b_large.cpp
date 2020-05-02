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
typedef pair<int,string> is;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<is> vis;

bool cmp(ii a, ii b){
	return a.first > b.first;
}

int main(){
	int tc,u,i,j;
	scanf("%d",&tc);

	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&u);
		int cnt[256];
		memset(cnt, 0, sizeof cnt);
		set<char> s, s1;
		set<char>::iterator it;

		for(i=0;i<10000;i++){
			ll bil;
			string st;
			cin>>bil>>st;
			s1.insert(st[0]);
			cnt[st[0]]++;
			for(j=0;j<st.size();j++){
				s.insert(st[j]);
			}
		}
		
		char zero;
		assert(s.size() == 10);
		assert(s1.size() == 9);
		for(it = s.begin(); it!=s.end();it++){
			char c = *it;
			if(s1.find(c) == s1.end()){
				zero = c;
			}
		}
		
		vector<ii> v;
		for(i='A';i<='Z';i++){
			if(cnt[i]){
				v.pb(ii(cnt[i], i));
			}
		}

		sort(v.begin(), v.end(), cmp);
		string ans = "AAAAAAAAAA";
		ans[0] = zero;
		for(i=0;i<v.size();i++){
			ii pas = v[i];
			ans[i+1] = pas.second;
		}
		cout<<ans<<endl;

	}
	
	return 0;
};