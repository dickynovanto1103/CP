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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

string kata[1010];

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		cin>>kata[i];
	}
	bool valid = true;
	int cnt = 0;
	for(i=0;i<n-1;i++){
		set<char> s;
		for(j=0;j<m;j++){
			if(s.count(kata[i+1][j])){
				valid = false;
				// printf("i: %d\n",i+1);
				break;
			}else{
				s.insert(kata[i+1][j]);
			}
		}
		if(!valid){break;}
		else{cnt++;}
	}
	printf("%d\n",cnt);
	return 0;
};