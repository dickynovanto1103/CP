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
	int hh,mm,dd;
	char kar1,kar2;
	scanf("%d:%d:%d%c%c",&hh,&mm,&dd,&kar1,&kar2);
	if(kar1=='P'){
		if(hh!=12){
			hh+=12;	
		}
		
	}else{
		if(hh==12){
			hh=0;
		}
	}
	printf("%02d:%02d:%02d\n",hh,mm,dd);
	return 0;
};