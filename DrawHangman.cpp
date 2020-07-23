#include <iostream>
using namespace std;

void PrintNewSentence(string str, bool printtop= true, bool printbottom= true)
{
    if(printtop)
    {
    	cout<<"+-------------------------------------+"<<endl;
    }

    cout<<"|";
    
    bool front = true;
    for(int i=str.length(); i<37; i++)
    {
    	if(front)
    	{
    		str= " " + str;
    	}
    	else{
    		str += " ";
    	}
    	front= !front;
    }

    cout<<str<<"|"<<endl;
    if(printbottom)
    {
    	cout<<"+-------------------------------------+"<<endl;
    }
}

void drawhangman(int tries)
{
	if(tries >=1)
	{
       PrintNewSentence("|", false, false);
	}
	else{
		PrintNewSentence("", false, false);
	}

	if(tries >=2)
	{
       PrintNewSentence("|", false, false);
	}
	else{
		PrintNewSentence("", false, false);
	}

	if(tries >=3)
	{
       PrintNewSentence("o", false, false);
	}
	else{
		PrintNewSentence("", false, false);
	}

	if(tries >=4)
	{
       PrintNewSentence("|", false, false);
	}

	if(tries ==5)
	{
       PrintNewSentence("|", false, false);
	}

	else if(tries == 6)
	{
       PrintNewSentence("/| ", false, false);
	}

	else if(tries >= 7)
	{
		PrintNewSentence("/|\\", false, false);
	}
	else{
		PrintNewSentence("", false, false);
	}

	if(tries >=8)
	{
       PrintNewSentence("|", false, false);
	}
	else{
		PrintNewSentence("", false, false);
	}

	if(tries ==9)
	{
       PrintNewSentence("/  ", false, false);
	}
	else if(tries >= 10)
	{
		PrintNewSentence("/ \\", false, false);
	}
	else PrintNewSentence("", false, false);

    PrintNewSentence("", false, false);
	PrintNewSentence("+------------------------+", false, false);
	PrintNewSentence("|                        |", false, false);
	PrintNewSentence("|                        |", false, true);

}

int main()
{
    PrintNewSentence("HANGMAN");
    drawhangman(10);
    return 0;
}