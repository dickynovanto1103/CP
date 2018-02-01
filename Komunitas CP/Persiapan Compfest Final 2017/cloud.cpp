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
typedef pair<string,int> ii;
typedef vector<ii> vii;

const int maxn = 500001;
string kata[maxn];
vector<string> ans;

int main(){
	ios_base::sync_with_stdio(0);
	int n,i,j;
	cin>>n;
	
	for(i=0;i<n;i++){cin>>kata[i];}
	
	for(i=n-2;i>=0;i--){
		bool found = false;
		for(j=0;j<kata[i].length();j++){
			if(kata[i][j] > kata[i+1][j]){
				found = true;
				break;
			}else if(kata[i][j] < kata[i+1][j]){break;}
		}
		if(found){kata[i] = kata[i].substr(0,j);}

	}
	for(i=0;i<n;i++){
		cout<<kata[i]<<endl;
	}

	return 0;
};