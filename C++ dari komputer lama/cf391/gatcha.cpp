#include <bits/stdc++.h>

using namespace std;

int main(){
	char kata[100010];
	bool visited[100010];
	int i,cntB=0,cntb=0,cnta=0,cntu=0,cntl=0,cnts=0,cntr=0;
	int cnt[9];
	memset(visited,true,sizeof visited);
	scanf("%s",kata);
	/*sort(kata+0,kata+strlen(kata));
	printf("%s\n",kata);*/
	for(i=0;i<strlen(kata);i++){
		if(kata[i]=='B'){cnt[0]++;}
		else if(kata[i]=='b'){cnt[1]++;}
		else if(kata[i]=='a'){cnt[2]++;}
		else if(kata[i]=='u'){cnt[3]++;}
		else if(kata[i]=='l'){cnt[4]++;}
		else if(kata[i]=='s'){cnt[5]++;}
		else if(kata[i]=='r'){cnt[6]++;}
	}
	cnt[2]/=2;
	cnt[3]/=2;
	int minim=cnt[0];
	for(i=1;i<7;i++){
		if(minim > cnt[i]){minim=cnt[i];}
	}
	printf("%d\n",minim);
	return 0;
}