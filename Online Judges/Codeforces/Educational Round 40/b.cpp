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
	int n,i,j;
	string kata;
	scanf("%d",&n);
	cin>>kata;
	string temp = "";
	int idxKetemu;
	int cnt = 0;
	int panjangMaks = 0;
	for(i=0;i<n;i++) {
		string temp = kata.substr(0,i+1);
		// cout<<"temp: "<<temp<<endl;
		idxKetemu = kata.find(temp,temp.length());
		if(idxKetemu != -1) {
			if(idxKetemu==temp.length()) {
				panjangMaks = temp.length();	
			}
		}
	}
	// printf("panjangMaks :%d\n",panjangMaks);
	int pjg = panjangMaks*2;
	int selisih = n-pjg;
	cnt += panjangMaks;
	if(panjangMaks>0){
		cnt++;
	}
	
	if(selisih>0){
		cnt+=selisih;
	}
	printf("%d\n",cnt);
	return 0;
};