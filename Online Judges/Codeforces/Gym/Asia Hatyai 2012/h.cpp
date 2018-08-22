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

struct person{
	string name;
	int d,m,y;
};

bool cmp(person a, person b){
	if(a.y == b.y){
		if(a.m ==b.m){
			return a.d < b.d;
		}
		return a.m <b.m;
	}
	return a.y < b.y;
}

int main(){
	int n,i,j;
	map<string,int> mapper;
	scanf("%d",&n);
	person pas[101];
	for(i=0;i<n;i++){
		string kata;
		int d,m,y;
		cin>>kata>>d>>m>>y;
		pas[i].name =kata;
		pas[i].d = d;
		pas[i].m = m;
		pas[i].y = y;
	}

	sort(pas,pas+n,cmp);
	cout<<pas[n-1].name<<endl<<pas[0].name<<endl;
	return 0;
};