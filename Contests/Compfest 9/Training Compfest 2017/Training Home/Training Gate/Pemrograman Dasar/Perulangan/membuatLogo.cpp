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
	int n,m,l,i,j;
	char kata[110][110];
	scanf("%d %d %d\n",&n,&m,&l);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){kata[i][j]='.';}
	}
	//bagian atas
	for(i=0;i<l;i++){
		for(j=0;j<m;j++){
			kata[i][j] = '*';
		}
	}
	//bagian kiri
	for(i=0;i<n;i++){
		for(j=0;j<l;j++){
			kata[i][j] = '*';
		}
	}
	//bagian bawah
	for(i=n-l;i<n;i++){
		for(j=0;j<m;j++){
			kata[i][j] = '*';
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){printf("%c",kata[i][j]);}
		printf("\n");
	}
	return 0;
}