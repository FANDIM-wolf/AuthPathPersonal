// UQL.cpp Main block of program UQL translator
//

#include <iostream>
#include <string>

using namespace std;

//we hold positions of symbols
char SYMBOLS_POSITION[40] = {};

string create = "CREATE TABLE";

// Ready string for uql command
string query_uql; 


int main()
{
	
	string query = "CREATE TABLE !table $name_string , $password_string;";
	//check_command(query);
	string command;
	int point_char = query.find("!");
	SYMBOLS_POSITION[0] = point_char;
	//check for CREATE TABLE
	for (int i = 0; i <= point_char; i++) {
		command[i] = query[i];	
	}
	if (command.find(create)){
		cout << command << endl;
	}
	else {
		cout << command;
	}
	
	
	return 0;
}

