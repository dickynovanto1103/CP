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

	string kata = "VAWT{uoadobumo_hwbuuoz_rwusgsfusgsf}";
	for(int i=0;i<kata.length();i++){
		char kar = kata[i] + 12;
		if(kata[i]=='{' || kata[i]=='}') {printf("%c",kata[i]); continue;}
		if(kata[i]>=97){
			if(kar>122){kar-=26;}
		}else{
			if(kar>90){kar-=26;}
		}
		printf("%c",kar);
	}
	printf("\n");
	return 0;
};