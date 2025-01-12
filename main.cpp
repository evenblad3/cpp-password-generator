#include <iostream>
#include <ctime>
#include <string>
#include <vector>

int main()
{
	srand(time(0));
	std::vector<char> password;


	std::string upperChoice("");
	bool includeUppercase(true);

	std::string lowerChoice("");
	bool includeLowercase(true);

	std::string specialCharChoice("");
	bool includeSpecialChars(true);

	std::string numberChoice("");
	bool includeNumbers(true);

	int passwordLength(0);

	char uppercaseLetters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	char lowercaseLetters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char specialChars[29] = {'!', '#', '$', '%', '&', '(', ')', '*', '+', ',', '-', '.', '/', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '{', '|', '}', '~'};

	std::cout << "How many characters would you like your password to be?" << std::endl;
	std::cin >> passwordLength;

	std::cout << "Do you want uppercase letters? (yes/no)" << std::endl;
	std::cin >> upperChoice;
	while (upperChoice != "yes" && upperChoice != "no") {
    	std::cout << "Please enter 'yes' or 'no'!" << std::endl;
    	std::cin >> upperChoice;
	}
	includeUppercase = (upperChoice == "yes");

	std::cout << "Do you want lowercase letters? (yes/no)" << std::endl;
	std::cin >> lowerChoice;
	while (lowerChoice != "yes" && lowerChoice != "no") {
    	std::cout << "Please enter 'yes' or 'no'!" << std::endl;
    	std::cin >> lowerChoice;
	}
	includeLowercase = (lowerChoice == "yes");

	std::cout << "Do you want special characters? (yes/no)" << std::endl;
	std::cin >> specialCharChoice;
	while (specialCharChoice != "yes" && specialCharChoice != "no") {
    	std::cout << "Please enter 'yes' or 'no'!" << std::endl;
    	std::cin >> specialCharChoice;
	}
	includeSpecialChars = (specialCharChoice == "yes");

	std::cout << "Do you want numbers? (yes/no)" << std::endl;
	std::cin >> numberChoice;
	while (numberChoice != "yes" && numberChoice != "no") {
    	std::cout << "Please enter 'yes' or 'no'!" << std::endl;
    	std::cin >> numberChoice;
	}
	includeNumbers = (numberChoice == "yes");

	if (!includeUppercase && !includeLowercase && !includeSpecialChars && !includeNumbers) {
    	std::cout << "Please choose at least one option. Try again!" << std::endl;
    	return 1;
	}

	std::cout << "Your password is: " << std::endl;
	while (password.size() < passwordLength) {
    	int selector = rand() % 4 + 1;

    	if (selector == 1 && includeUppercase) {
        	int j = rand() % 26;
        	std::cout << uppercaseLetters[j];
        	password.push_back(uppercaseLetters[j]);
    	} else if (selector == 2 && includeLowercase) {
        	int j = rand() % 26;
        	std::cout << lowercaseLetters[j];
        	password.push_back(lowercaseLetters[j]);
    	} else if (selector == 3 && includeSpecialChars) {
        	int j = rand() % 29;
        	std::cout << specialChars[j];
        	password.push_back(specialChars[j]);
    	} else if (selector == 4 && includeNumbers) {
        	int number = rand() % 10;
        	std::cout << char(number + '0');
        	password.push_back(char(number + '0'));
    	}
	}

	std::cout << std::endl;
	return 0;
}
