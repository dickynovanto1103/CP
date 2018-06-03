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
	int a,b;
	scanf("%d %d",&a,&b);
	if(a==b){printf("=\n"); return 0;}
	if(a==1) {
		if(b==1){printf("=\n");}
		else{printf("<\n");}
		return 0;
	}
	if(b==1){
		if(a==1){printf("=\n");}
		else{printf(">\n");}
		return 0;
	}
	if(a==2){
		if(b==3){
			printf("<\n");
		}else if(b==4){
			printf("=\n");
		}else{
			printf(">\n");
		}
		return 0;
	}
	if(b==2){
		if(a==3){
			printf(">\n");
		}else if(a==4){
			printf("=\n");
		}else{
			printf("<\n");
		}
		return 0;
	}

	if(a>b){printf("<\n");}
	else{printf(">\n");}
	return 0;
};