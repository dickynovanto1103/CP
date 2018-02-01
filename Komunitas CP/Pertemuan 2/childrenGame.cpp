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

bool cmp(const string& a, const string& b){
	return b+a < a+b;
}

int main(){
	int n,i,j;
	string kata[55];
	int maks = 0;
	int test = 1;
	while(scanf("%d",&n),n){

		for(i=0;i<n;i++){
			cin>>kata[i];
		}
		sort(kata,kata+n,cmp);
		//printf("pasangan:\n");
		
		for(i=0;i<n;i++){
			cout<<kata[i];
			//cout<<pasangan[i].first<<" "<<pasangan[i].second<<endl;
		}
		printf("\n");
	}
	return 0;
};