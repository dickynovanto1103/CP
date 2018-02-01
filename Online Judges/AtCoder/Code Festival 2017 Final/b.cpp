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
	string kata;
	int i,j;
	cin>>kata;
	int pjg = kata.length();
	if(pjg==1){printf("YES\n"); return 0;}

	set<char> s;
	set<char>::iterator it;
	int counter[256];
	memset(counter,0,sizeof counter);
	for(i=0;i<pjg;i++){
		s.insert(kata[i]);
		counter[kata[i]]++;
	}
	int ukuran = (int)s.size();
	if(pjg==2){
		if(ukuran==1){
			printf("NO\n");	
		}else{
			printf("YES\n");
		}
		return 0;
	}
	if(pjg>=3 && ukuran<=2){printf("NO\n"); return 0;}
	int batas;
	if(pjg%ukuran==0){batas = pjg/ukuran;}
	else{batas = pjg/ukuran + 1;}

	bool valid = true;
	for(it=s.begin();it!=s.end();it++){
		char kar = *it;
		if(counter[kar]>batas){valid = false; break;}
	}
	if(valid){printf("YES\n");}
	else{printf("NO\n");}
	return 0;
};