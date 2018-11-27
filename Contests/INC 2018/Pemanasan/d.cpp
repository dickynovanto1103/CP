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
	int pjg = kata.length();
	int pjgA = 0;
	int maks = 0;
	int i,j;
	for(i=0;i<pjg;i++){
		char kar = kata[i];
		if(kar == 'a'){pjgA++;}
		else{
			maks = max(maks, pjgA);
			pjgA = 0;
		}
	}
	maks = max(maks, pjgA);
	for(i=0;i<=maks;i++){
		printf("a");
	}
	printf("\n");
	return 0;
};