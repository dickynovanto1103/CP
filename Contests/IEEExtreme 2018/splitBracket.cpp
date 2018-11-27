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

const int maxn = 40;

bool isValid(string& kata){
	stack<char> s;
	int pjg = kata.length();
	for(int i=0;i<pjg;i++){
		char kar = kata[i];
		if(kar == '('){
			s.push(kar);
		}else if(kar == ')'){
			if(s.empty() || s.top() != '('){return false;}
			s.pop();
		}else if(kar == '['){
			s.push(kar);
		}else{
			if(s.empty() || s.top() != '['){return false;}
			s.pop();
		}
	}
	return s.empty();
}

int main(){
	string kata;
	clock_t begin, end;
	begin = clock();
	cin>>kata;
	int i,j;
	int pjg = kata.length();
	if(pjg % 2 == 1){printf("impossible\n");}
	else{

		int a[maxn];
		for(i=0;i<pjg/2;i++){
			a[i] = 1;
		}
		for(i=pjg/2;i<pjg;i++){
			a[i] = 2;
		}
		do{
			string kata1 = "", kata2 = "";
			for(i=0;i<pjg;i++){
				if(a[i] == 1){kata1+=kata[i];}
				else{kata2 += kata[i];}
			}
			if(isValid(kata1) && isValid(kata2)){
				for(i=0;i<pjg;i++){
					if(i){printf(" ");}
					printf("%d",a[i]);
				}
				printf("\n");
				return 0;
			}
			double durasi = (double)(clock() - begin);
			if(durasi/CLOCKS_PER_SEC > 1.95){
				printf("impossible\n");
				return 0;
			}
			
		}while(next_permutation(a,a+pjg));
	}

	return 0;
};