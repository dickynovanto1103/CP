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
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n, m;
vi isa[10002], hasa[10002];
bool visis[10002], vishas[10002], vishy[10002];
map<string, int> mapping;
string a, b, c;

bool dfsisa(int a, int b){
	for(int& i : isa[a]){
		if(visis[i])
			continue;
		if(i == b)
			return true;
		visis[i] = true;
		bool coba = dfsisa(i, b);
		if(coba)
			return true;
	}
	return false;
}

bool dfshasa(int a, int b){
	for(int& i:hasa[a]){
		if(i==b)
			return true;
		bool coba;
		// is-a dfs
		if(!visis[i]){
			visis[i] = true;
			coba = dfsisa(i, b);
			if(coba)
				return true;
		}
		if(vishas[i])
			continue;
		vishas[i] = true;
		coba = dfshasa(i, b);
		if(coba)
			return true;
	}
	return false;
}

bool hybrid(int a, int b){
	for(int& i: isa[a]){
		if(vishy[i])
			continue;
		vishy[i] = true;
		bool coba = hybrid(i, b);
		if(coba)
			return true;
	}
	bool coba = dfshasa(a, b);
	return coba;
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0, j=0;i<n;i++){
		cin>>a>>b>>c;
		int ida, idc;
		if(mapping.count(a))
			ida = mapping[a];
		else
			ida = mapping[a] = j++;
		if(mapping.count(c))
			idc = mapping[c];
		else
			idc = mapping[c] = j++;
		if(b=="is-a"){
			isa[ida].pb(idc);
		}
		else{
			hasa[ida].pb(idc);
		}
	}
	for(int i=1;i<=m;i++){
		memset(visis, false, sizeof visis);
		memset(vishas, false, sizeof vishas);
		memset(vishy, false, sizeof vishy);
		cin>>a>>b>>c;
		int ida = mapping[a];
		int idc = mapping[c];
		bool wew;
		if(ida != idc){
			if(b=="is-a"){
				visis[ida] = true;
				wew = dfsisa(ida, idc);
				visis[ida] = false;
			}
			else{
				vishas[ida] = true;
				wew = hybrid(ida, idc);
				vishas[ida] = false;
			}
		}
		else
			wew = true;
		cout<<"Query "<<i<<": ";
		if(wew)
			cout<<"true\n";
		else
			cout<<"false\n";
	}
	return 0;
};