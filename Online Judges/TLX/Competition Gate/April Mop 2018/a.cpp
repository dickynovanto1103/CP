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
	int a = 0, b = 1;
	int i,j;
	int x[110], y[110];
	for(i=1;i<=100;i++){
		printf("i: %d\n",i);
		while((a+b) < i){
			if(a==b){a = 1;}
			else{a++;}
		}
		if((a + b) == i){
			printf("i: %d jawab: %d %d\n",i,a,b);
			x[i] = a; y[i] = b;
		}
	}
	for(i=1;i<=100;i++){
		printf("%d = %d + %d\n",i,x[i],y[i]);
	}
	return 0;
};