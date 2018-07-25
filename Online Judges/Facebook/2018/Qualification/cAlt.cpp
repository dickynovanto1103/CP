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
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		int n;
		printf("Case #%d: ",tt);
		string kata;
		cin>>kata;
		n = kata.length();
		char karPertama = kata[0];
		string penambahan = "";
		penambahan+=karPertama;
		for(i=1;i<n;i++){
			if(karPertama == kata[i]){
				break;
			}else{
				penambahan+=kata[i];
			}
		}

		string kataBaru = penambahan+kata;
		string ambil = kataBaru.substr(0,n);
		if(ambil == kata){
			printf("Impossible\n");
		}else{
			cout<<kataBaru<<endl;
		}
		
	}
	return 0;
};