#include <bits/stdc++.h>

using namespace std;

int main(){
	string kata;
	int selisih,i;
	
	getline(cin,kata);
	while(!cin.eof()){
		for(i=0;i<kata.length();i++){
			char karakter = kata[i];
			if(karakter=='W'){kata[i]='Q';}
			else if(karakter=='S'){kata[i]='A';}
			else if(karakter=='X'){kata[i]='Z';}
			else if(karakter=='E'){kata[i]='W';}
			else if(karakter=='D'){kata[i]='S';}
			else if(karakter=='C'){kata[i]='X';}
			else if(karakter=='R'){kata[i]='E';}
			else if(karakter=='F'){kata[i]='D';}
			else if(karakter=='V'){kata[i]='C';}
			else if(karakter=='T'){kata[i]='R';}
			else if(karakter=='G'){kata[i]='F';}
			else if(karakter=='B'){kata[i]='V';}
			else if(karakter=='Y'){kata[i]='T';}
			else if(karakter=='H'){kata[i]='G';}
			else if(karakter=='N'){kata[i]='B';}
			else if(karakter=='U'){kata[i]='Y';}
			else if(karakter=='J'){kata[i]='H';}
			else if(karakter=='M'){kata[i]='N';}
			else if(karakter=='I'){kata[i]='U';}
			else if(karakter=='K'){kata[i]='J';}
			else if(karakter==','){kata[i]='M';}
			else if(karakter=='O'){kata[i]='I';}
			else if(karakter=='L'){kata[i]='K';}
			else if(karakter=='.'){kata[i]=',';}
			else if(karakter=='P'){kata[i]='O';}
			else if(karakter==';'){kata[i]='L';}
			else if(karakter=='/'){kata[i]='.';}
			else if(karakter=='['){kata[i]='P';}
			else if(karakter=='\''){kata[i]=';';}
			else if(karakter==']'){kata[i]='[';}
			else if(karakter=='\\'){kata[i]=']';}
			else if(karakter=='1'){kata[i]='`';}
			else if(karakter=='2'){kata[i]='1';}
			else if(karakter=='3'){kata[i]='2';}
			else if(karakter=='4'){kata[i]='3';}
			else if(karakter=='5'){kata[i]='4';}
			else if(karakter=='6'){kata[i]='5';}
			else if(karakter=='7'){kata[i]='6';}
			else if(karakter=='8'){kata[i]='7';}
			else if(karakter=='9'){kata[i]='8';}
			else if(karakter=='0'){kata[i]='9';}
			else if(karakter=='-'){kata[i]='0';}
			else if(karakter=='='){kata[i]='-';}
			
			
			/*switch (karakter){
				case 'W': kata[i] = 'Q';1
				case 'S': kata[i] = 'A';2
				case 'X': kata[i] = 'Z';3
				case 'E': kata[i] = 'W';4
				case 'D': kata[i] = 'S';5
				case 'C': kata[i] = 'X';6
				case 'R': kata[i] = 'E';7
				case 'F': kata[i] = 'D';8
				case 'V': kata[i] = 'C';9
				case 'T': kata[i] = 'R';0
				case 'G': kata[i] = 'F';1
				case 'B': kata[i] = 'V';2
				case 'Y': kata[i] = 'T';3
				case 'H': kata[i] = 'G';4
				case 'N': kata[i] = 'B';5
				case 'U': kata[i] = 'Y';6
				case 'J': kata[i] = 'H';7
				case 'M': kata[i] = 'N';8
				case 'I': kata[i] = 'U';9
				case 'K': kata[i] = 'J';0
				case ',': kata[i] = 'M';1
				case 'O': kata[i] = 'I';2
				case 'L': kata[i] = 'K';3
				case '.': kata[i] = ',';4
				case 'P': kata[i] = 'O';5
				case ';': kata[i] = 'L';6
				case '/': kata[i] = '.';7
				case '[': kata[i] = 'P';8
				//case '': kata[i] = 'Q';9
				case ']': kata[i] = '[';0
				//case '\\': kata[i] = ']';1
			}*/
		}
		cout<<kata<<endl;
		getline(cin,kata);
	}
	return 0;
}