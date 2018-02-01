#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main() {
	int n, cnt, pjg, i, cntToGuess, cntWrong;
	map<char, int> mapper;
	map<char,int> mapper2;
	map<char, int>::iterator it;
	string kata, guess;
	while(scanf("%d",&n),(n!=-1)){
		cnt = 0;
		printf("Round %d\n",n);
		cin>>kata>>guess;
		pjg = kata.length();
		for(i=0;i<pjg;i++){
			it=mapper.find(kata[i]);
			if(it==mapper.end()){mapper[kata[i]]=cnt++;}
		}
		cntToGuess = cnt;
		pjg = guess.length();
		cntWrong=0;
		cnt=0;
		bool found = true;
		for(i=0;i<pjg;i++) {
			it = mapper.find(guess[i]);
			if(it!=mapper.end()){//ketemu
				it = mapper2.find(guess[i]);
				if(it==mapper2.end()){mapper2[guess[i]] = cnt++;}

			}else{cntWrong++;}
			if(cntToGuess == cnt){break;}
			if(cntWrong==7){found = false; mapper.clear(); break;}

		}
		if(found){
			if(cnt < cntToGuess){printf("You chickened out.\n");}
			else{printf("You win.\n");}
		}else{
			printf("You lose.\n");
		}
		mapper2.clear(); mapper.clear();
	}
	return 0;
}