#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <time.h>
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
	else{
		PrintNewSentence("", false, false);
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

string leftletters(string guessed, char from, char to)
{
	string s;
	for(char i=from; i<=to; i++)
	{
		if(guessed.find(i) == string::npos)
		{
            s += i;
            s += " ";
		}
		else{
			s += "  ";
		}
	}
	return s;
}

bool PrintandWin(string word, string guessed)
{
	bool won= true;
	string s;
	for(int i=0; i<word.length(); i++)
	{
		if(guessed.find(word[i]) == string::npos)
		{
			won= false;
			s += "_ ";
		}
		else{
			s += word[i];
			s += " ";
		}
	}

	PrintNewSentence(s, false, true);
	return won;

}

bool CharAddedIsRightOrNot(string word, char ch)
{
	if(word.find(ch) == string::npos)
		return false;
	return true;
}

string selectword(string path)
{
	ifstream infile(path);
    
    string word;
    vector<string> v;

	if(infile.is_open())
	{
       while(getline(infile, word))
       	{
       		v.push_back(word);
       	}

       int i= rand() % v.size();
       word= v[i];

       infile.close();
	}
	else 
		{
			cout<<"FILE NOT FOUND"<<endl;
		}
	
	return word;
}

int main()
{
	srand(time(0));

	string WordToBeGuessed = selectword("hangman game.txt");
	
    string guessed;

    int tries = 10;
    bool win= false;

	do{
    system("cls");
    PrintNewSentence("HANGMAN");

    drawhangman(10 - tries);

    PrintNewSentence("AVAILABLE LETTERS", false, true);

    string s= leftletters(guessed, 'A', 'M');
    PrintNewSentence(s, false, false);
    s= leftletters(guessed, 'N', 'Z');
    PrintNewSentence(s, false, true);

    PrintNewSentence("Guess the Word", false, true);

    win = PrintandWin(WordToBeGuessed, guessed);

    if(tries == 0) break;

    if(win)
    	break;

    char ch;
    cout<<">";
    cin>>ch;
    if(guessed.find(ch) == string::npos)
    	{
    		guessed = guessed + ch;

            if(!CharAddedIsRightOrNot(WordToBeGuessed, ch))
            tries--;
        }

    
    }while(tries >= 0);

    if(!win){
    	PrintNewSentence("YOU LOST!", false);
    	PrintNewSentence("THE WORD IS : " + WordToBeGuessed, false);
    }
    else PrintNewSentence("YOU WON!", false);
    return 0;

}

     