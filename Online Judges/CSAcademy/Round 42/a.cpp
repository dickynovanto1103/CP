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

int main() {
	string a;
	int listkar[265],i;
	cin>>a;
	memset(listkar,0,sizeof listkar);
	for(i=0;i<a.length();i++){
		char kar = a[i];
		int bil = kar-48;
		listkar[bil]++;
	}
	for(i=0;i<=9;i++){
		if(listkar[i]!=1){break;}
	}
	if(i==10){printf("1\n");}
	else{printf("0\n");}
	return 0;
}