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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	string kata;
	int i,j,test=1;
	while(cin>>kata && kata!="end"){
		vector<stack<char> > vec;
		stack<char> s;
		s.push(kata[0]);
		vec.pb(s);
		for(i=1;i<kata.length();i++){
			char kar = kata[i];
			bool ketemu = false;
			for(j=0;j<vec.size();j++){
				
				if(kar<=vec[j].top()){vec[j].push(kar); ketemu = true;break;}
			}
			stack<char> st;
			st.push(kar);
			if(!ketemu){vec.pb(st);}
		}
		printf("Case %d: %d\n",test++,vec.size());
	}
	return 0;
};