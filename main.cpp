#include <iostream>
#include <random>
#include <string>
#include <vector>

int main()
{
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

	std::random_device rd;
	std::mt19937 mtgen(rd());
	std::uniform_int_distribution<int> upperRandom(0, (sizeof(uppercaseLetters)/sizeof(uppercaseLetters[0]) - 1));
	std::uniform_int_distribution<int> lowerRandom(0, (sizeof(lowercaseLetters)/sizeof(lowercaseLetters[0]) - 1));
	std::uniform_int_distribution<int> specialRandom(0, (sizeof(specialChars)/sizeof(specialChars[0]) - 1));
	std::uniform_int_distribution<int> numberRandom(0, 9);

	std::cout << "How many characters would you like your password to be?" << std::endl;
	std::cin >> passwordLength;

	std::cout << "Do you want uppercase letters? (yes/no)" << std::endl;
	std::cin >> upperChoice;
	while (upperChoice.at(0) != 'y' && upperChoice.at(0) != 'n') {
    	std::cout << "Please enter 'yes' or 'no'!" << std::endl;
    	std::cin >> upperChoice;
	}
	includeUppercase = (upperChoice.at(0) == 'y');

	std::cout << "Do you want lowercase letters? (yes/no)" << std::endl;
	std::cin >> lowerChoice;
	while (lowerChoice.at(0) != 'y' && lowerChoice.at(0) != 'n') {
    	std::cout << "Please enter 'yes' or 'no'!" << std::endl;
    	std::cin >> lowerChoice;
	}
	includeLowercase = (lowerChoice.at(0) == 'y');

	std::cout << "Do you want special characters? (yes/no)" << std::endl;
	std::cin >> specialCharChoice;
	while (specialCharChoice.at(0) != 'y' && specialCharChoice.at(0) != 'n') {
    	std::cout << "Please enter 'yes' or 'no'!" << std::endl;
    	std::cin >> specialCharChoice;
	}
	includeSpecialChars = (specialCharChoice.at(0) == 'y');

	std::cout << "Do you want numbers? (yes/no)" << std::endl;
	std::cin >> numberChoice;
	while (numberChoice.at(0) != 'y' && numberChoice.at(0) != 'n') {
    	std::cout << "Please enter 'yes' or 'no'!" << std::endl;
    	std::cin >> numberChoice;
	}
	includeNumbers = (numberChoice.at(0) == 'y');

	if (!includeUppercase && !includeLowercase && !includeSpecialChars && !includeNumbers) {
    	std::cout << "Please choose at least one option. Try again!" << std::endl;
    	return 1;
	}

	std::cout << "Your password is: " << std::endl;
	while (password.size() < passwordLength) {
    	std::uniform_int_distribution<int> _selector(1,4);
    	int selector = _selector(mtgen);

    	if (selector == 1 && includeUppercase) {
        	int j = upperRandom(mtgen);
        	std::cout << uppercaseLetters[j];
        	password.push_back(uppercaseLetters[j]);
    	} else if (selector == 2 && includeLowercase) {
        	int j = lowerRandom(mtgen);
        	std::cout << lowercaseLetters[j];
        	password.push_back(lowercaseLetters[j]);
    	} else if (selector == 3 && includeSpecialChars) {
        	int j = specialRandom(mtgen);
        	std::cout << specialChars[j];
        	password.push_back(specialChars[j]);
    	} else if (selector == 4 && includeNumbers) {
        	int number = numberRandom(mtgen);
        	std::cout << char(number + '0');
        	password.push_back(char(number + '0'));
    	}
	}

	std::cout << std::endl;
	return 0;
}
