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
	map<string, string> mapper;
	set<string> s;
	mapper["purple"] = "Power";
	mapper["green"] = "Time";
	mapper["blue"] = "Space";
	mapper["orange"] = "Soul";
	mapper["red"] = "Reality";
	mapper["yellow"] = "Mind";

	s.insert("Power");
	s.insert("Time");
	s.insert("Space");
	s.insert("Soul");
	s.insert("Reality");
	s.insert("Mind");

	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		string kata;
		cin>>kata;
		// cout<<"kata: "<<kata<<endl;
		string hasilMap = mapper[kata];
		// cout<<"hasilMap: "<<hasilMap<<endl;
		s.erase(hasilMap);
	}
	printf("%d\n",(int)s.size());
	set<string>::iterator it;
	for(it=s.begin();it!=s.end();it++){
		cout<<*it<<endl;
	}

	return 0;
};