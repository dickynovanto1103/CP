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

string kata;

bool isSama(int idx){
	int n = kata.length();
	int indeks = 0;
	for(int i=idx;i<n;i++){
		if(kata[i] != kata[indeks]){return false;}
		indeks++;
	}
	return true;
}

int main(){
	int n,k,i,j;
	
	scanf("%d %d",&n,&k);
	cin>>kata;
	char karPertama = kata[0];
	int idx = 0;
	int cur = 1;
	for(i=1;i<n;i++){
		if(kata[i] == karPertama){
			if(isSama(i)){
				idx = i;
				break;
			}
		}
	}
	int selisih = n - idx;
	int idxStart = selisih;
	int sisa = n - idxStart;
	string tambahan;
	if(idx == 0){
		tambahan = kata;	
	}else{
		tambahan = kata.substr(idxStart, sisa);	
	}
	
	string temp = kata;
	
	// cout<<"tambahan: "<<tambahan<<endl;

	kata = temp;
	while(cur < k){
		kata += tambahan;
		cur++;
	}
	cout<<kata<<endl;

	return 0;
};