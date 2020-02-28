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

bool isVowel(char kar) {
	return kar == 'a' || kar == 'i' || kar == 'u' || kar == 'e' || kar == 'o';
}

int main(){
	int n;
	FastSlowInput;
	// scanf("%d\n",&n);
	cin>>n;
	// printf("n: %d\n",n);
	for(int tt=1;tt<=n;tt++){
		string kata,dum;
		if(tt==1){getline(cin, dum);}
		getline(cin, kata);
		for(int i=0;i<kata.length();i++){
			if(isVowel(kata[i])){printf("%cp%c",kata[i],kata[i]);}
			else{printf("%c",kata[i]);}
		}	
		printf("\n");
	}
	
	return 0;
};