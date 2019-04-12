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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isValid(string kata){
	if(kata[0] >= 'A' && kata[0] <= 'Z'){return false;}
	int i;
	int pjg = kata.length();
	for(i=0;i<pjg;i++){
		char kar = kata[i];
		if((kar >= 'A' && kar <= 'Z') || (kar >= 'a' && kar <= 'z')){

		}else{
			return false;
		}
	}
	int cnt = 1;
	for(i=0;i<pjg;i++){
		char kar = kata[i];
		if(kar >= 'A' && kar <= 'Z'){
			cnt++;
		}
	}
	if(cnt<=7){return true;}
	else{
		return false;
	}
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	string kata;
	while(tc--){
		cin>>kata;
		if(isValid(kata)){printf("YES\n");}
		else{printf("NO\n");}
	}
	return 0;
};