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
	int tc,i,j;
	scanf("%d\n",&tc);
	while(tc--){
		string kata;
		getline(cin,kata);
		string cur = "";
		bool found = false;
		for(i=0;i<kata.length();i++){
			if(kata[i] == ' '){
				if(cur == "not"){printf("Real Fancy\n"); found = true; cur = "";break;}
				cur = "";
			}else{
				cur += kata[i];
			}
		}
		// cout<<"cur: "<<cur<<endl;
		if(cur == "not"){printf("Real Fancy\n"); found = true;}
		if(!found){printf("regularly fancy\n");}
		
	}
	return 0;
};