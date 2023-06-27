#include <iostream>
#include <fstream> 
#include <string>

//using namespace std;

// Init fucntions
bool fileCheck(std::string name);
void fileCreate(std::string name);
void dialogWindow(void);
void registerName(void);
void inputDialog(std::string username, std::string password);
void login(void);

int main() 
{
	// check if file exists
	if (fileCheck("Registry") == true)
	{
		std::cout << "Registry exists \n\n";
	}
	// else create file
	else 
	{ 
		fileCreate("Registry");
		std::cout << "Registry created \n\n";
	}

	dialogWindow();
}

// function: to verify if file exists
bool fileCheck (std::string name)
{
	std::ifstream ifile;
	ifile.open(name + ".csv");
	if (ifile) 
	{ 
		ifile.close();
		return true; 
	}
	else { return false;}
}
// function: to create a file
void fileCreate(std::string name)
{
	std::ofstream MyFile("Registry.csv");
	MyFile.close();
}
// function: input dialog
void dialogWindow(void)
{
	int inputValue;

	// open for input
	std::cout << " \t Enter the following for their respective commands:  ";
	std::cout << "\n \t 1: Register  ";
	std::cout << "\n \t 2: Login  ";
	std::cout << "\n \n \t \t \t";
	std::cin >> inputValue;

	if (inputValue == 1)
	{
		registerName();
	}

	else if (inputValue == 2)
	{
		login();
	}

	else
	{
		std::cout << "\n\n\t !!INVALID VALUE!!";
		return;
	}
}
// function: input username and password
// I noticed that registerName and login start with the same code 
void inputDialog(std::string username, std::string password)
{

}
// function: register
void registerName(void)
{
	// Create and open a text file
	std::ofstream MyFile;
	std::string userName, passWord;

	// Input username
	std::cout << "\n Enter user name: \n\t\t";
	std::cin >> userName;
	
	// ios::app means that it will use the 'app' function of the ios library
	MyFile.open("Registry.csv", std::ios::app);

	// check if a userName already exists
	std::ifstream targetFile("Registry.csv");
	std::string emptyString;
	while (std::getline(targetFile, emptyString))
	{
		if (emptyString.find(userName + ",") != std::string::npos)
		{
			std::cout << "\n\n" << userName << " is already in use!" << "\n\n";
			return;
		}

		else { continue; }
	};

	// Input password
	std::cout << "\n Enter pass word: \n\t\t";
	std::cin >> passWord;

	// Write to the file
	MyFile << userName << "," << passWord << "\n";
	
	// Close the file
	MyFile.close();
}
// function: login
void login(void)
{
	// Create and open a text file
	std::ifstream MyFile;
	std::string userName, passWord;

	// Input credentials
	std::cout << "\n Enter user name: \n\t\t";
	std::cin >> userName;
	std::cout << "\n Enter pass word: \n\t\t";
	std::cin >> passWord;

	// ios::app means that it will use the 'app' function of the ios library
	MyFile.open("Registry.csv", std::ios::app);

	// check if a userName already exists
	std::ifstream targetFile("Registry.csv");
	std::string line;

	while (getline(targetFile, line))
	{
		if (line.find(userName + "," + passWord) != std::string::npos)
		{
			std::cout << "\n\n" << "OK!" << "\n\n";
			return;
		}

		else 
		{ 
			std::cout << "\n\n" << "ERROR" << "\n\n";
			continue; 
		}
	};

}