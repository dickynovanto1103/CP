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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

char s[1010][1010];

int main(){
	int r,c,i,j;
	scanf("%d %d",&r,&c);
	string com;
	cin>>com;
	for(i=0;i<r;i++){
		scanf("%s",s[i]);
	}
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(s[i][j] == 'a'){
				s[i][j] = '.';
			}
			printf("%c",s[i][j]);
		}
		printf("\n");
	}
	return 0;
};