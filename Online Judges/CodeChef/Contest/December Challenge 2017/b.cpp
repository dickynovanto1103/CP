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
	int i,j;
	string kata;
	while(cin>>kata){
		int score1 = 0, score2=0;
		for(i=0;i<10;i++){
			if(i%2==0){
				if(kata[i]=='1'){score1++;}
			}else{
				if(kata[i]=='1'){score2++;}
			}
		}
		if(score1==score2){
			//sudden death
			bool decided = false;
			for(i=10;i<20;i+=2){
				if(score1!=score2){
					decided = true;
					if(score1>score2){
						printf("TEAM-A %d\n",i);
					}else{
						printf("TEAM-B %d\n",i); 
					}
					break;
				}
				if(kata[i]=='1'){score1++;}
				if(kata[i+1]=='1'){score2++;}
			}
			if(!decided){
				if(score1>score2){
					printf("TEAM-A %d\n",i);
				}else if(score1<score2){
					printf("TEAM-B %d\n",i); 
				}else{printf("TIE\n");}	
			}
			
			
		}else{
			//proses ulang untuk nentuin minimum tembakan
			score1 = 0; score2 = 0;
			int cnt1 = 0, cnt2 = 0;
			bool decided = false;
			for(i=0;i<10;i++){
					
				if(i%2==0){
					cnt1++;
					if(kata[i]=='1'){score1++;}
				}else{
					cnt2++;
					if(kata[i]=='1'){score2++;}
				}
				int sisa1 = 5-cnt1, sisa2 = 5-cnt2;
				int bestPossibleScore1, bestPossibleScore2;
				if(score1>score2){
					bestPossibleScore2 = score2+sisa2;
					if(bestPossibleScore2<score1){
						decided = true;
						printf("TEAM-A %d\n",i+1); break;
					}
				}else{
					bestPossibleScore1 = score1+sisa1;
					if(bestPossibleScore1<score2){
						decided = true;
						printf("TEAM-B %d\n",i+1); break;
					}
				}

			}

			if(!decided){
				if(score1>score2){
					printf("TEAM-A %d\n",i);
				}else if(score1<score2){
					printf("TEAM-B %d\n",i); 
				}else{printf("TIE\n");}	
			}
		}
	}
	return 0;
};