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
	int a,b,r;
	scanf("%d %d %d",&a,&b,&r);
	int panjang = a / (r*2);
	int lebar = b / (r*2);
	int banyak = panjang * lebar;
	if(banyak % 2 == 0){printf("Second\n");}
	else{printf("First\n");}
	return 0;
};