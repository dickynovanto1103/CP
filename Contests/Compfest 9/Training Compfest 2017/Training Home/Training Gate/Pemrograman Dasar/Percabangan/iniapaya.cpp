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
	string kata;
	cin>>kata;
	if(kata[0]=='-'){
		if(kata[1]=='0'){printf("nol\n");}
		else{printf("bilangan bulat negatif\n");}
	}else if(kata[0]>='a' && kata[0]<='z'){printf("kata\n");}
	else if(kata[0]=='0'){printf("nol\n");}
	else if(kata[0]>='1' && kata[0]<='9'){printf("bilangan bulat positif\n");}
	return 0;
}