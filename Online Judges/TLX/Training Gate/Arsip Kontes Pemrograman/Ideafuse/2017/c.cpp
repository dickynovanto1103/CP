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
	int i,j;
	for(i=0;i<3;i++){
		getline(cin,kata);
		for(j=0;j<3;j++){
			if(kata[j] != kata[j+4]){
				printf("Geleng-Geleng\n");
				return 0;
			}
		}
	}
	printf("Angguk-Angguk\n");
	return 0;
};