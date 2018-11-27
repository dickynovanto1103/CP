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
	string a,b;
	cin>>a>>b;
	int i,j;
	int pjgA = a.length(), pjgB = b.length();
	int cntA = 0, cntB = 0;
	for(i=0;i<pjgA;i++){
		if(a[i] == '1'){
			cntA++;
		}
	}
	for(i=0;i<pjgB;i++){
		if(b[i] == '1'){
			cntB++;
		}
	}

	if(cntA >= cntB){printf("YES\n");}
	else{
		if(cntA % 2 == 1){
			if((cntA+1) == cntB){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}else{
			printf("NO\n");
		}
	}

	return 0;
};