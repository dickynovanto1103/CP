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

bool isReal(char kar){
	return kar !='?';
}

int main(){
	int n,i,j;
	string kata;
	cin>>n>>kata;
	vi listIdx;
	bool valid = false;
	if(n==1){
		if(isReal(kata[0])){printf("No\n");}
		else{printf("Yes\n");}
		return 0;
	}

	for(i=0;i<n;i++){
		if(kata[i]=='?'){listIdx.pb(i);}
	}

	for(i=0;i<(n-1);i++){
		if(isReal(kata[i]) && isReal(kata[i+1]) && kata[i]==kata[i+1]){printf("No\n"); return 0;}
	}

	for(i=0;i<listIdx.size();i++){
		int idx = listIdx[i];
		if(idx==0 || idx==(n-1)){valid = true;}
		else{
			if(isReal(kata[idx-1]) && isReal(kata[idx+1])){
				if(kata[idx-1] == kata[idx+1]){printf("Yes\n"); return 0;}
			}
			if(!isReal(kata[idx-1])){printf("Yes\n"); return 0;}
			if(!isReal(kata[idx+1])){printf("Yes\n"); return 0;}
		}
	}
	if(valid){printf("Yes\n");}
	else{printf("No\n");}

	return 0;
};