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
	map<string,int> mapper;
	mapper["monday"] = 1;
	mapper["tuesday"] = 2;
	mapper["wednesday"] = 3;
	mapper["thursday"] = 4;
	mapper["friday"] = 5;
	mapper["saturday"] = 6;
	mapper["sunday"] = 7;
	string hari1,hari2;
	
	cin>>hari1>>hari2;
	
	int idx1 = mapper[hari1], idx2 = mapper[hari2];
	int diff[]={3,0,3,2,3,2,3,3,2,3,2,3};
	int perbedaan = idx2-idx1;
	
	if(perbedaan<0){perbedaan+=7;}
	for(int i=0;i<12;i++){
		if(perbedaan==diff[i]){printf("YES\n"); return 0;}
	}
	printf("NO\n");	
	
	return 0;
};