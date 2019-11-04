#include <iostream>
#include <cstring>

using namespace std;	// For simplicity

int main(){
	string str = "";
	cout << "Please enter a string:\n";
	getline(cin, str);	// Takes whole line as string

	for (unsigned int i=0; i<str.size(); i++){	// Loop through string
		if (str[i] =='\"'){
			str.replace(i, 1, "");	// Replaces " with nothing
			i++;
			while (str[i] != '\"' && i != str.length()){	// Searches for an end quote
				i++;
			}
			str.replace(i, 1, "");
		}
		else if (str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '-' || str[i] == '\'')	// Handles punctuation outside of "
				str[i] = ' ';
	}

	cout << str;
	cout << "\n";
}