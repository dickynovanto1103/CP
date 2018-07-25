#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	string word;
	int rotation, counter;

	cin>>word;
	cin>>rotation;
	for(int i = 0; i < word.length(); i++) 
	{
		counter = 0;
		while(counter < rotation) 
		{
			word[i]++;
			if(word[i] > 'z')
			{
				word[i] = 'a';
			}
			counter++;
		}
	}

	cout<<word<<endl;
	return 0;
}