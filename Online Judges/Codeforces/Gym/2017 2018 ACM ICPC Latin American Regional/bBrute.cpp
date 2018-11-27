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

bool isVowel(char kar) {
	return kar == 'a' || kar == 'i' || kar == 'u' || kar == 'e' || kar == 'o';
}

int main(){
	string kata;
	cin>>kata;
	string temp = kata;
	int n = kata.length(),i,j;
	sort(kata.begin(), kata.end());
	do{
		string coba = "";
		for(i=0;i<n;i++){
			char kar = kata[i];
			coba += kar;
			if(isVowel(kar)){
				reverse(coba.begin(), coba.end());
			}
		}
		if(coba == temp){
			for(i=0;i<n;i++){
				printf("%c",kata[i]);
			}
			printf("\n");
		}
	}while(next_permutation(kata.begin(), kata.end()));
	return 0;
};