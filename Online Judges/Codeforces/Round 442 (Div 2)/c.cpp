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

void print(vi a){
	int i;
	for(i=0;i<a.size();i++){
		if(i){printf(" ");}
		printf("%d",a[i]);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	vi genap, ganjil;
	for(int i=1;i<=n;i++){
		if(i%2==0){genap.pb(i);}
		else{ganjil.pb(i);}
	}
	int i;
	printf("%d\n",2*genap.size() + ganjil.size());
	if(genap.size()==0){
		print(ganjil); printf("\n");
	}else{
		print(genap); printf(" ");
		print(ganjil); printf(" ");
		print(genap); printf("\n");	
	}
	
	//printf(" %d\n",2);
	return 0;
};