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
	stack<char> s;
	string kata;
	cin>>kata;
	int i, pjg = kata.length();
	if(pjg%2==1){printf("No\n"); return 0;}
	
	for(i=0;i<pjg;i++){
		char kar = kata[i];
		if(s.empty()){s.push(kar); }
		else{
			char karakterAtas = s.top();
			if(kar==karakterAtas){s.pop();}
			else{s.push(kar);}
		}
	}
	if(s.empty()){printf("Yes\n");}
	else{printf("No\n");}
	return 0;
};