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
	int n,m,i,j;
	string kata;
	int l,r;
	char awal, akhir;
	cin>>n>>m;
	cin>>kata;
	for(i=0;i<m;i++){
		cin>>l>>r>>awal>>akhir;	
		for(j=l-1;j<r;j++){
			if(kata[j]==awal){kata[j]=akhir;}
		}
	}
	cout<<kata<<endl;
	return 0;
};