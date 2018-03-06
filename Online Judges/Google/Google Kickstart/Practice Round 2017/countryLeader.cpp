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
typedef pair<int,string> ii;
typedef vector<ii> vii;

const int maxn = 110;

ii pas[maxn];

int main(){
	int tc,tt,n;
	int i,j;
	string kata[maxn];
	scanf("%d",&tc);

	for(tt=1;tt<=tc;tt++){
		scanf("%d",&n);
		string dummy;
		// cin>>dummy;
		int maks = 0; string kataMaks;
		for(i=0;i<n;i++){
			if(i==0){getline(cin,dummy);}
			getline(cin,kata[i]);
			// printf("kata[%d]: ",i); cout<<kata[i]<<endl;
			set<char> s;
			for(j=0;j<kata[i].length();j++){
				if(kata[i][j]==' '){continue;}
				s.insert(kata[i][j]);
			}
			int ukuran = s.size();
			if(ukuran > maks){
				maks = ukuran;
				kataMaks = kata[i];
			}else if(ukuran == maks){
				kataMaks = min(kataMaks, kata[i]);
			}

		}
		printf("Case #%d: ",tt); cout<<kataMaks<<endl;
	}
	return 0;
};