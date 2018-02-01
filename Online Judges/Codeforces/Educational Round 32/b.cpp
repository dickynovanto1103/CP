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
	string kata;
	scanf("%d",&n);
	cin>>kata;
	int x = 0, y = 0;
	for(i=0;i<kata.length();i++){
		char kar = kata[i];
		if(kar=='D'){y--;}
		else if(kar=='U'){y++;}
		else if(kar=='L'){x--;}
		else if(kar=='R'){x++;}
	}
	//printf("x: %d y: %d\n",);
	int total = abs(x) + abs(y);
	printf("%d\n",n-total);
	return 0;
};