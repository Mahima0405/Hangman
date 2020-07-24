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
    	cout<<"\t\t\t\t\t+-------------------------------------+"<<endl;
    }

    cout<<"\t\t\t\t\t|";
    
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
    	cout<<"\t\t\t\t\t+-------------------------------------+"<<endl;
    }
}

int printintroduction()
{
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
    
	PrintNewSentence("WELCOME TO THE HANGMAN GAME");

	cout<<endl<<endl;

	PrintNewSentence("1. HOW TO PLAY?");
	PrintNewSentence("2. PLAY THE GAME", false);
	PrintNewSentence("3. EXIT         ", false);

    cout<<endl<<endl;
    cout<<"\t\t\t\t\t ENTER YOUR CHOICE -->  ";

    int choice;
    cin>>choice;
    return choice; 
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

void printinstructions()
{
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	PrintNewSentence("INSTRUCTIONS");
	cout<<"\t1. THE GAME MAYBE PLAYED IN GROUPS OR INDIVIDUALLY.\n";
	cout<<"\t2. THE PLAYER NEEDS TO GUESS THE WORD BY CHOOSING ONE OF THE ALPHABETS FROM THE AVAILABLE LETTERS.\n";
	cout<<"\t3. THE PLAYER CAN MAKE 10 WRONG PREDICTIONS\n";
	cout<<"\t4. THE CHANCE COUNT WILL BE REDUCED ON EVERYWRONG PREDICTION AND A PART OF HANGMAN WILL BE DISPLAYED ON EVERY \n";
	cout<<"\t5. IF THE PLAYER MAKES 10 WRONG PREDICTIONS, THEN THE HANGMAN WILL BE HANGED TO DEATH \n";
	cout<<"\t6. THE PLAYER WINS IF THE WORD IS GUESSED RIGHT BEFORE THE HANGMAN IS HANGED.\n\n\n";
	cout<<"\t\t ALL THE BEST\n\n";
	cout<<"\t\t PRESS ANY NUMBER TO CONTINUE--> ";
	int n; cin>>n;
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

	int choice = printintroduction();

	while(choice == 1)
	{
		printinstructions();
		choice = printintroduction();
	}

	if(choice == 3) return 0;

	
    string guessed;

    int tries = 10;
    bool win= false;

	do{
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
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
    cout<<"\n\n\t\t\t\t\t ENTER YOUR CHOICE --> ";
    cin>>ch;
    if (ch >= 'a' && ch <= 'z')
    {
    	ch = toupper(ch);
    }

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
    cout<<endl<<endl<<endl;
    return 0;
}

     