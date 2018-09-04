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
	int tc,i,j;
	string kata;
	scanf("%d",&tc);
	while(tc--){
		cin>>kata;
		int n;
		scanf("%d",&n);
		while(n--){
			string word;
			cin>>word;
			if(kata.find(word) != -1){
				printf("y\n");
			}else{
				printf("n\n");
			}
		}	
	}
	
	return 0;
};