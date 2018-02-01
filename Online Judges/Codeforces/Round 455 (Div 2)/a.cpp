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
	string kata1, kata2;
	int i,j;
	int pjg1, pjg2;
	cin>>kata1>>kata2;
	pjg1 = kata1.length(); pjg2 = kata2.length();
	string minimalKata = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	for(i=1;i<=pjg1;i++){
		string subkata1 = kata1.substr(0,i);
		for(j=1;j<=pjg2;j++){
			string subkata2 = kata2.substr(0,j);
			string kata = subkata1+subkata2;
			if(minimalKata>kata){minimalKata = kata;}
		}
	}
	cout<<minimalKata<<endl;
	return 0;
};