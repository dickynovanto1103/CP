#include <bits/stdc++.h>
using namespace std;

class Exception{
	string kata;
	public:
		Exception(string _kata){
			kata = _kata;
		}
		void print(){
			cout<<kata<<endl;
		}
};

class StringToInteger{
	private:
		int bil;
		string kata;
	public:
		StringToInteger(string _kata){
			kata = _kata;
		}
		void convert(){
			int cur = 0;
			for(int i=0;i<kata.length();i++){
				int a = kata[i]-'0';
				
				if(a<0 || a>9){
					throw(Exception("Bad String"));
				}else{
					cur*=10; cur+=a;
				}
			}
			bil = cur;
		}
		int getBil(){return bil;}
};


int main(){
	string s;
	cin>>s;
	try{
		StringToInteger converter(s);
		converter.convert();
		cout<<converter.getBil()<<endl;
	}catch(Exception e){
		e.print();
	}
	return 0;
}