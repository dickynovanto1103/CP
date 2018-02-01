#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	string kata;
	int k,i;
	cin>>kata>>k;
	set<char> s;
	int pjg = kata.length();
	if(k>pjg){printf("impossible\n"); return 0;}
	for(i=0;i<kata.length();i++){
		char kar = kata[i];
		s.insert(kar);
	}
	//printf("k: %d s: %d selisih: %d\n",k,s.size(),k-s.size());
	int selisih = k-s.size();
	if(selisih<0){
		//printf("masuk sini\n");
		printf("0\n"); return 0;
	}
	printf("%d\n",k-s.size());
	return 0;
}