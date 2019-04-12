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
	string kata;
	cin>>kata;
	stack<int> s;
	vii a;
	int i,j,k;
	const int pjg = kata.length();
	for(i=0;i<pjg;i++){
		char kar = kata[i];
		if(kar == '('){s.push(i);}
		else if(kar == ')'){
			int bil = s.top(); s.pop();
			a.pb(ii(bil, i));
		}
	}
	int ukuran = a.size();
	set<string> s1;
	for(i=0;i<(1<<ukuran);i++){
		bool isPrinted[pjg];
		memset(isPrinted, true, sizeof isPrinted);
		for(j=0;j<ukuran;j++){

			
			if((1<<j) & i){
				ii pas = a[j];
				isPrinted[pas.first] = false;
				isPrinted[pas.second] = false;
			}
			
		}
		string temp = "";
		for(j=0;j<pjg;j++){
			if(isPrinted[j]){temp += kata[j];}
		}
		if(temp != "" && temp!=kata){s1.insert(temp);}
	}
	set<string>::iterator it;
	for(it=s1.begin();it!=s1.end();it++){
		cout<<*it<<endl;
	}
	return 0;
};