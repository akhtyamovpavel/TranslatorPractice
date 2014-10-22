#include <iostream>
#include <string>
#include <stdexcept>
#include "IntWithInfinity.h"
#include "CheckRegex.h"
#include "TestRegex.h"
const int IntWithInfinity::INF = -1;
int main() {
	
	try {
		unitCheck();
		std::string regularExpression;
		std::cin >> regularExpression;
		char letter;
		std::cin >> letter;
		int wordLength;
		std::cin >> wordLength;
		if (runCheck(regularExpression, wordLength, letter)) {
			std::cout << "YES" << std::endl;
		} else {
			std::cout << "NO" << std::endl;
		}
		
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}