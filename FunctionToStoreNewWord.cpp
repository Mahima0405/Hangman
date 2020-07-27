void setters()
{
	system("cls");
	PrintNewSentence("Enter the password : ");
	cout<<"\t\t\t-->";
	string pswd;
	cin >> pswd;
	if(pswd == "123456")
	{
		system("cls");
		PrintNewSentence("HOW MANY NEW WORDS YOU WANT TO STORE?");
		cout<<"\t\t\t-->";
		int num; cin>>num;

		ofstream out_file;
		out_file.open("hangman game.txt", ios::app);

		while(num --)
		{
		system("cls");
		PrintNewSentence("ENTER THE NEW WORD ", true, true);
		cout<<"\t\t\t-->";
		string word;
		cin>>word;

		transform(word.begin(), word.end(), word.begin(), ::toupper);

		out_file<<"\n"<<word;	   
		 }
        
        out_file.close();
	}
}