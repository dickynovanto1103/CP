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

int main(){
	int tc,u,i,j;
	scanf("%d",&tc);

	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&u);
		set<char> st;
		set<char>::iterator it;
		string list[10001];
		ll listBil[10001];

		for(i=0;i<10000;i++){
			ll bil;
			string s;
			cin>>bil>>s;
			list[i] = s;
			listBil[i] = bil;
			for(j=0;j<s.size();j++){
				st.insert(s[j]);
			}
		}

		
		vector<char> v;
		
		int idx = 0;
		for(it=st.begin();it!=st.end();it++){
			v.pb(*it);
		}
		
		assert(v.size() >= 9);
		if(v.size() == 9){
			for(i=0;i<26;i++){
				if(st.find(i + 'A') == st.end()){
					v.pb(i + 'A');
					break;
				}
			}	
		}
		
		int pos[256];

		string jawab = "";
		do{
			int ukuran = v.size();
			for(i=0;i<ukuran;i++){
				pos[v[i]] = 0;
				if(ukuran == 9){
					pos[v[i]] = i+1;
				}else{
					pos[v[i]] = i;	
				}
			}
			bool valid = true;
			for(i=0;i<10000;i++){
				string s = list[i];
				ll bil = 0;
				for(j=0;j<s.size();j++){
					char c = s[j];
					bil *= 10;
					bil += pos[c];
				}
				if(bil == 0){valid = false; break;}
				if(bil > listBil[i]){valid = false; break;}
			}
			if(valid){
				for(i=0;i<v.size();i++){
					jawab += v[i];
				}
			}
		}while(next_permutation(v.begin(), v.end()));
		cout<<jawab<<endl;
	}
	
	return 0;
};