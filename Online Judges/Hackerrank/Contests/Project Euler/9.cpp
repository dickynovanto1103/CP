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

int listAns[2000000];

int main(){
	int a,b,i,j;
	int cnt = 0;
	for(i=2;i<3000;i++){
		for(j=1;j<i;j++){
			// printf("i: %d j: %d --> ",i,j);
			a = i*i - j*j;
			b = 2*i*j;
			int c = i*i + j*j;
			// printf("%d %d %d ",a, b, c);
			if(__gcd(a,__gcd(b,c)) == 1){
				if((a+b+c)>3000){
					listAns[cnt] = (a+b+c);
					cnt++;
				}
			}
		}
	}
	printf("size: %d\n",cnt);
	return 0;
};