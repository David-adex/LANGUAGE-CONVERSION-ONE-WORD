#include <iostream>

#include<fstream>

#include <iomanip>

#include <cstdlib>

#include<string>

#include<filesystem>


using namespace std;
//Declaration of function names
void menu();
void engToyoruba();
void yorubaToeng();
//functions to help remove any space from the string to be read
string& leftTrim(string& str, string& chars)
{
	str.erase(0, str.find_first_not_of(chars));
	return str;
}

string& rightTrim(string& str, string& chars)
{
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

string& trimString(string& str, string& chars)
{
	return leftTrim(rightTrim(str, chars), chars);
}
//declaration of variables
string general;
string trim = " ";
string word = "";
int num;

int main()
{
	//Startup
	menu();
	return 0;
}
void menu() {
	//displays menu
	cout << setw(50) << "\n\nWELCOME TO THE ONE WORD CONVERSION LANGUAGE GAME" << endl;
	cout << "\n\nSELECT A LANGUAGE BELOW" << endl;
	cout << "1) YORUBA" << endl;
	cout << "\n2) ENGLISH" << endl;
	cout << "\n3) EXIT\n" << endl;
	//takes the integer inputted 
	cin >> num;

	//carries out the task of each integer inputted
	if (num == 1) {
		cin.ignore();
		//recieves a word from the user and stores it
		cout << "PLEASE INPUT YOUR WORD: ";
		getline(cin, general);
		//calls functions
		trimString(general, trim);
		cout <<"\n"<< general << endl;
		engToyoruba();
		menu();
	}
	else if (num == 2) {
		cin.ignore();
		//recieves a word from the user and stores it
		cout << "PLEASE INPUT YOUR WORD: ";
		getline(cin,general);
		//calls functions
		trimString(general, trim);
		cout << "\n" << general << endl;
		yorubaToeng();
		menu();
	}
	else if (num == 3) {
		//exits the program
		system("exit");
	}
	else {
		//redirects the user to the main menu
		cout << setw(30) << "WRONG NUMBER PLEASE, YOU WILL BE DIRECTED TO THE MENU PAGE NOW" << endl;
		menu();
	}
	return;
}


void engToyoruba() {
	//open and reads file
	string filename("eng.txt");

	ifstream english(filename);

	string line;
	unsigned int curLine = 0;
	//reads the file line by line
	while (getline(english, line)) 
	{
		curLine++;
		//searches for the inputted word in the file and prints out the word line number
		if (line.find(general, 0) != string::npos) {
			cout << "found: " << general<< " line: " << curLine << endl;
			english.close();
			cout << "\n\n converting....." << endl;
			string anotherfile("yoruba.txt");
			//reads the file
			ifstream yor(anotherfile);

			string converted;
			//takes curLine as the line number and prints out the word on that line
			for (int lineno = 1; getline(yor, converted) && lineno < 2999; lineno++) {
				if (lineno == curLine) {
					cout << "CONVERTED FORMAT: " << converted;
					cin.get();
					yor.close();

				}
			}

		}
	}
	
	return;
}


	


void yorubaToeng() {
	//open and reads file
	string filename("yoruba.txt");

	ifstream yor(filename);

	string line;
	unsigned int curLine = 0;
	//reads the file line by line
	while (getline(yor, line))
	{
		curLine++;
		//searches for the inputted word in the file and prints out the word line number
		if (line.find(general, 0) != string::npos) {
			cout << "found: " << general << " line: " << curLine << endl;
			yor.close();
			cout << "\n\n converting....." << endl;
			string anotherfile("eng.txt");
			//reads the file
			ifstream english(anotherfile);

			string converted;
			//takes curLine as the line number and prints out the word on that line
			for (int lineno = 1; getline(english, converted) && lineno < 2999; lineno++) {
				if (lineno == curLine) {
					cout << "CONVERTED FORMAT: " << converted;
					cin.get();
					english.close();
				}
			}

		}
	}

	return;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	string eng[length], yoruba[length], save;
	int now;
	system("cls");
	if (yor >> general) {
		for (now = 0; now <= length; now++)
		{
			getline(yor, save);
			yoruba[now] = save;
			getline(english, save);
			eng[now] = save;
			cout << "CONVERTED FORMAT: " << eng[now] << endl;
		}
	}
	return eng[now];*/




