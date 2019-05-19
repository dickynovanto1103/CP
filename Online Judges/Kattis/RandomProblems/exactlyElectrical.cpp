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

int main(){
	int a,b,a1,b1,c;
	scanf("%d %d %d %d %d",&a,&b,&a1,&b1,&c);
	int selisih = abs(a-a1) + abs(b-b1);
	if(selisih > c){printf("N\n");}
	else{
		c -= selisih;
		if(c & 1){printf("N\n");}
		else{printf("Y\n");}
	}
	return 0;
};