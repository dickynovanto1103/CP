#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int gcd(int a, int b){return b==0? a: gcd(b,a%b);}

int main(){
	int n;
	cin>>n;
	int num,denum;
	if(n%2==1){
		num = n/2;
		denum = num+1;
		printf("%d %d\n",num,denum);
	}else{
		num = n/2;
		denum = n/2;
		while(gcd(num,denum)!=1){
			num--; denum++;
		}
		printf("%d %d\n",num,denum);
	}
	return 0;
};