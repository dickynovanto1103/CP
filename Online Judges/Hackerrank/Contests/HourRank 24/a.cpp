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
	int n,i;
	string kata;
	scanf("%d",&n);
	cin>>kata;
	string numbers = "0123456789";
	string lower_case = "abcdefghijklmnopqrstuvwxyz";
	string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string special_characters = "!@#$%^&*()-+";

	int totalNumber = 0, totalLowercase = 0, totalUpperCase = 0, totalSpecialCharacter = 0;
	for(i=0;i<n;i++){
		char kar = kata[i];
		if(numbers.find(kar)!=-1){totalNumber++;}
		if(lower_case.find(kar)!=-1){totalLowercase++;}
		if(upper_case.find(kar)!=-1){totalUpperCase++;}
		if(special_characters.find(kar)!=-1){totalSpecialCharacter++;}
	}
	int kebutuhan1 = 6-n, kebutuhan2 = 0;
	if(totalNumber==0){kebutuhan2++;}
	if(totalLowercase==0){kebutuhan2++;}
	if(totalUpperCase==0){kebutuhan2++;}
	if(totalSpecialCharacter==0){kebutuhan2++;}
	if(kebutuhan1<=0){
		printf("%d\n",kebutuhan2);
	}else{
		printf("%d\n",max(kebutuhan1,kebutuhan2));
	}
	return 0;
};