#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

void solve(int count, char source, char destination, char intermediate, int nomor){
	if(count==1){printf("%d %c %c\n",nomor,source,destination);}
	else{
		//printf("test\n");
		solve(count-1,source, intermediate, destination, nomor-1);
		//printf("test setelah 1\n");
		solve(1,source,destination,intermediate,nomor);
		//printf("test setelah 2\n");
		solve(count-1,intermediate,destination,source,nomor-1);
		//printf("test setelah 3\n");
	}
}

int main() {
	int n;
	scanf("%d",&n);
	solve(n,'A','C','B',n);
	return 0;
}