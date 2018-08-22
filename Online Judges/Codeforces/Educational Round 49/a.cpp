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
	int n;
	string kata;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		cin>>kata;
		bool valid = true;
		for(i=0;i<(n/2);i++){
			int j = n-1-i;
			char kar1 = kata[i], kar2 = kata[j];
			if(abs(kar1 - kar2) % 2 == 1){
				valid = false;
				break;
			}
			int selisih = abs(kar1 - kar2);
			if(selisih > 2){valid = false; break;}
		}
		if(valid){printf("YES\n");}
		else{printf("NO\n");}
	}
	return 0;
};