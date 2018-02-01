#include <cstdio>
#include <stack>

using namespace std;

int main(){
	int n;
	stack <int> s;
	while(scanf("%d",&n)!=EOF){
		//printf("n: %d\n",n);
		while(n>0){
			s.push(n%2);
			n/=2;
		}
		while(!s.empty()){printf("%d",s.top()); s.pop();}

		printf("#\n");
	}
	return 0;
}