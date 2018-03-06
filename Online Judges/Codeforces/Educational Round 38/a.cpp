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

bool isVowel(char kar){
	return kar=='a' || kar=='e' || kar=='i' || kar=='o' || kar=='u' || kar=='y';
}

int main(){
	int n,i,j;
	string kata;
	scanf("%d",&n);
	cin>>kata;
	for(i=0;i<n-1;i++){
		if(isVowel(kata[i]) && isVowel(kata[i+1])){
			kata.erase(kata.begin()+i+1);
			i--;
			n--;
		}
	}
	cout<<kata<<endl;
	return 0;
};