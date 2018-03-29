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

const int maxn = 1e5 + 5;
bool isVisited[maxn];

int main(){
	memset(isVisited,false,sizeof isVisited);
	string kata;
	cin>>kata;
	int n,i,j;
	n = kata.length();
	int lastIdx = -1;
	for(i=97;i<=122;i++){
		char karakter = i;
		// printf("%c\n",karakter);
		bool found = false;	
		for(j=lastIdx+1;j<n;j++){
			char kar = kata[j];
			if(kar<=i && !isVisited[j]){
				isVisited[j] = true;
				kata[j] = i;
				found = true;
				lastIdx = j;
				break;
			}
		}
		if(!found){printf("-1\n"); return 0;}
		
	}
	cout<<kata<<endl;
	return 0;
};