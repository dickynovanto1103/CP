#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	char kar;
	int a,b;
	scanf("%d %c %d",&a,&kar,&b);
	int ans;
	if(kar=='+'){ans = a+b;}
	else if(kar=='-'){ans = a-b;}
	else if(kar=='*'){ans = a*b;}
	else if(kar=='/'){ans = a/b;}
	else{
		ans = a%b;
	}
	printf("%d\n",ans);
	return 0;
}