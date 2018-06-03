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
	int n,i,j;
	scanf("%d",&n);
	int spasiAwal = n-2;
	printf("*");
	for(i=0;i<spasiAwal;i++){printf(" ");}
	printf("* ");
	for(i=0;i<n;i++){printf("*");}
	printf("\n");
	for(i=0;i<spasiAwal;i++){
		printf("*");
		for(j=0;j<spasiAwal;j++){printf(" ");}
		printf("* ");
		printf("*");
		for(j=0;j<spasiAwal;j++){printf(" ");}
		printf("*\n");
		
	}
	for(i=0;i<n;i++){printf("*");}
	printf(" ");
	printf("*");
	for(i=0;i<spasiAwal;i++){printf(" ");}
	printf("*\n");

	return 0;
};