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

int main(){
	string benar[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
	string kata;
	int i,j;
	cin>>kata;
	int pjg = kata.length();
	int found=-1,cnt = 0;
	for(i=0;i<5;i++){
		int panjang = benar[i].length();
		for(j=0;j + panjang<=pjg;j++){
			//printf("j: %d\n",j);
			string temp = kata.substr(j,panjang);
			//cout<<"kata: "<<temp<<endl;
			if(temp==benar[i]){
				cnt++;
			}
		}
	}
	if(cnt==1){printf("YES\n");}
	else{printf("NO\n");}
	return 0;
};