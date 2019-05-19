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
	string str;
	set<string> st;

	while(getline(cin, str)) {
		stringstream s(str);
		string kata;
		bool first = true;
		while(s >> kata) {
			string lower = "";
			if(!first){printf(" ");}
			for(int i=0;i<kata.length();i++){
				lower += tolower(kata[i]);
			}
			if(st.find(lower) != st.end()){
				printf(".");
			}else{
				cout<<kata;
				st.insert(lower);
			}
			first = false;
		}
		printf("\n");
	}
	return 0;
};