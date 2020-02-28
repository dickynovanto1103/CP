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
	int a,b;
	char s[20],k[20];
	while(scanf("%s %d %s %d",s,&a,k,&b) !=EOF){
		if(s[0] == 'B') {
			if(k[0] == 'C'){
				if(a >= 2*b){printf("Tobby\n");}
				else{printf("Naebbirac\n");}
			}else if(k[0] == 'B'){
				if(a > b){printf("Tobby\n");}
				else if(a == b){printf("Draw\n");}
				else{printf("Naebbirac\n");}
			}else if(k[0] == 'D') {
				if(b >= 2*a) {
					printf("Naebbirac\n");
				}else{
					printf("Tobby\n");
				}
			}
		}else if(s[0] == 'C') {
			if(k[0] == 'C'){
				if(a > b){printf("Tobby\n");}
				else if(a == b){printf("Draw\n");}
				else{printf("Naebbirac\n");}
			}else if(k[0] == 'B'){
				if(b >= 2*a){printf("Naebbirac\n");}
				else{printf("Tobby\n");}
			}else if(k[0] == 'D') {
				if(a >= 2*b){printf("Tobby\n");}
				else{printf("Naebbirac\n");}
			}
		}else { //D
			if(k[0] == 'C'){
				if(b >= 2*a){printf("Naebbirac\n");}
				else{printf("Tobby\n");}
			}else if(k[0] == 'B'){
				if(a >= 2*b){printf("Tobby\n");}
				else{printf("Naebbirac\n");}
			}else if(k[0] == 'D') {
				if(a > b){printf("Tobby\n");}
				else if(a == b){printf("Draw\n");}
				else{printf("Naebbirac\n");}
			}
		}
	}
	return 0;
};