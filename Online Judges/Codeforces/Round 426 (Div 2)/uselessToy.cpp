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
	char kar1,kar2;
	cin>>kar1>>kar2;
	//printf("%d\n",'v');
	if(kar1=='>'){
		if(kar2=='<'){printf("undefined\n");}
		else{
			if(kar2=='^'){printf("ccw\n");}
			else{printf("cw\n");}
		}
	}else if(kar1=='<'){
		if(kar2=='>'){printf("undefined\n");}
		else{
			if(kar2=='^'){printf("cw\n");}
			else{printf("ccw\n");}
		}
	}else if(kar1=='v'){
		if(kar2=='^'){printf("undefined\n");}
		else{
			if(kar2=='>'){printf("ccw\n");}
			else{printf("cw\n");}
		}
	}else{
		if(kar2=='v'){printf("undefined\n");}
		else{
			if(kar2=='<'){printf("ccw\n");}
			else{printf("cw\n");}
		}
	}
	return 0;
}