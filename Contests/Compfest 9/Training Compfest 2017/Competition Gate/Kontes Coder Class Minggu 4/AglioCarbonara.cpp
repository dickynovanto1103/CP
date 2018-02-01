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

bool isVokal(char kar1){
	char kar = tolower(kar1);
	return (kar=='a' || kar=='i' || kar=='u' || kar=='e' || kar=='o');
}

int main() {
	int n,i,j;
	string kata;
	cin>>n;
	getline(cin>>ws,kata);
	i = 0, j = n-1;
	bool found = false;
	while(i<=j && !found){//cek kiri
		
		if(isVokal(kata[i])){found = true;}
		else{i++;}
	}
	//printf("awal i:%d j: %d\n",i,j);
	found = false;
	while(i<=j && !found){//cek kiri
		//printf("j: %d\n",j);
		if(isVokal(kata[j])){found = true;}
		else{j--;}
	}
	//printf("i: %d j: %d\n",i,j);
	for(int idx=i;idx<=j;idx++){printf("%c",kata[idx]);}
	printf("\n");
	return 0;
}