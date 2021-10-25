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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

void printChar(char c, int n) {
	for(int i=0;i<n;i++){
		printf("%c", c);
	}
}

void printBracket(int n) {
	printChar('(', n);
	printChar(')', n);
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		if(n==1){printf("()\n"); continue;}
		printBracket(n);
		printf("\n");

		for(i=1;i<n;i++){
			int banyakDua = n - i;
			printBracket(i);
			printBracket(banyakDua);
			printf("\n");
		}
	}
	
	return 0;
};