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
	while(n--){
		cin>>kata;
		char karSekarang = '1';
		int cnt = 0;
		for(i=0;i<kata.length();i++){
			char kar = kata[i];
			if(kar==karSekarang){
				cnt++;
			}else{
				if(cnt==0){cnt = 1;}
				else if(cnt==1){printf("%c",karSekarang);}
				else{printf("%d%c",cnt,karSekarang);}

				cnt = 1;
			}
			karSekarang = kar;
		}
		if(cnt==1){printf("%c\n",karSekarang);}
		else{printf("%d%c\n",cnt,karSekarang);}
		// printf("\n");
	}
	return 0;
};