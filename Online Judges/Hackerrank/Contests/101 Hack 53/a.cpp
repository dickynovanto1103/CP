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
	int a = n%8;
	if(a==0){printf("SUB\n");}
	else if(a==1){printf("LB\n");}
	else if(a==2){printf("MB\n");}
	else if(a==3){printf("UB\n");}
	else if(a==4){printf("LB\n");}
	else if(a==5){printf("MB\n");}
	else if(a==6){printf("UB\n");}
	else if(a==7){printf("SLB\n");}
	return 0;
};