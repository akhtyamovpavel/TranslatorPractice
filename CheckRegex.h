#ifndef CHECK_REGEX_H
#define CHECK_REGEX_H

#include <string> 
#include <stack>
#include "IntWithInfinity.h"
#include <algorithm>
#include <iostream>


class CheckRegex {
	std::string regex_;
	std::stack<IntWithInfinity> mostLengthPrefix_;
	std::stack<IntWithInfinity> mostLengthSuffix_;
	std::stack<bool> mayFull_;
	std::stack<IntWithInfinity> maxFullLength_;
	IntWithInfinity maximalLength;

	void throwRegexException() {
		throw std::logic_error("Wrong input string: expected in reverse Polish notation");
	}

	void throwIllegalArgumentException() {
		throw std::logic_error("Broken data in reverse Polish notation");
	}

	void popElements() {
		mostLengthPrefix_.pop();
		mostLengthSuffix_.pop();
		mayFull_.pop();
		maxFullLength_.pop();
	}

	void checkForStackTrace() {
		if (mostLengthPrefix_.empty() || mostLengthSuffix_.empty() ||
			mayFull_.empty() || maxFullLength_.empty()) {
			throwIllegalArgumentException();
		}
	}


public:
	CheckRegex(const std::string& s) {
		regex_ = s;
		maximalLength = IntWithInfinity(0);
	}

	bool checkRegexForLetterWord(char c, int number) {
		for (auto symbol: regex_) {
			if (symbol >= 'a' && symbol <= 'c') {
				if (symbol == c) {
					mostLengthSuffix_.push(IntWithInfinity(1));
					mostLengthPrefix_.push(IntWithInfinity(1));
					mayFull_.push(true);
					maxFullLength_.push(IntWithInfinity(1));
					maximalLength = std::max<IntWithInfinity>(maximalLength, IntWithInfinity(1));
				} else {
					mostLengthPrefix_.push(IntWithInfinity(0));
					mostLengthSuffix_.push(IntWithInfinity(0));
					mayFull_.push(false);
					maxFullLength_.push(IntWithInfinity(0));
				}
			} else if (symbol == '.') {
				checkForStackTrace();
				IntWithInfinity longestPrefix2 = mostLengthPrefix_.top();
				IntWithInfinity longestSuffix2 = mostLengthSuffix_.top();
				bool mayFull2 = mayFull_.top();
				IntWithInfinity maxFull2 = maxFullLength_.top();
				popElements();
				checkForStackTrace();
				IntWithInfinity longestPrefix1 = mostLengthPrefix_.top();
				IntWithInfinity longestSuffix1 = mostLengthSuffix_.top();
				IntWithInfinity maxFull1 = maxFullLength_.top();
				bool mayFull1 = mayFull_.top();
				popElements();
				if (mayFull1 && mayFull2) {
					mayFull_.push(true);
					maxFullLength_.push(maxFull1 + maxFull2);
				} else {
					mayFull_.push(false);
					maxFullLength_.push(IntWithInfinity(0));
				}
				maximalLength = std::max<IntWithInfinity>(maximalLength, longestSuffix1 + longestPrefix2);

				IntWithInfinity longestSuffix;
				IntWithInfinity longestPrefix;
				if (mayFull1) {
					longestPrefix = maxFull1 + longestPrefix2;
				}
				if (mayFull2) {
					longestSuffix = maxFull2 + longestSuffix1;
				}
				longestPrefix = std::max<IntWithInfinity>(longestPrefix, longestPrefix1);
				longestSuffix = std::max<IntWithInfinity>(longestSuffix, longestSuffix2);
				mostLengthPrefix_.push(longestPrefix);
				mostLengthSuffix_.push(longestSuffix);
			} else if (symbol == '+') {
				checkForStackTrace();
				IntWithInfinity longestPrefix2 = mostLengthPrefix_.top();
				IntWithInfinity longestSuffix2 = mostLengthSuffix_.top();
				bool mayFull2 = mayFull_.top();
				IntWithInfinity maxFull2 = maxFullLength_.top();
				popElements();
				checkForStackTrace();
				IntWithInfinity longestPrefix1 = mostLengthPrefix_.top();
				IntWithInfinity longestSuffix1 = mostLengthSuffix_.top();
				bool mayFull1 = mayFull_.top();
				IntWithInfinity maxFull1 = maxFullLength_.top();
				popElements();
				if (mayFull1 || mayFull2) {
					mayFull_.push(true);
					maxFullLength_.push(std::max<IntWithInfinity>(maxFull1, maxFull2));
				} else {
					mayFull_.push(false);
					maxFullLength_.push(IntWithInfinity(0));
				}
				mostLengthPrefix_.push(std::max<IntWithInfinity>(longestPrefix1, longestPrefix2));
				mostLengthSuffix_.push(std::max<IntWithInfinity>(longestSuffix1, longestSuffix2));
			} else if (symbol == '*') {
				checkForStackTrace();
				IntWithInfinity longestPrefix = mostLengthPrefix_.top();
				IntWithInfinity longestSuffix = mostLengthSuffix_.top();
				bool mayFull = mayFull_.top();
				IntWithInfinity maxFull = maxFullLength_.top();
				popElements();
				if (mayFull) {
					mayFull_.push(true);
					if (maxFull > IntWithInfinity(0)) {
						maxFullLength_.push(IntWithInfinity(IntWithInfinity::INF));
						mostLengthPrefix_.push(IntWithInfinity(IntWithInfinity::INF));
						mostLengthSuffix_.push(IntWithInfinity(IntWithInfinity::INF));
						maximalLength = IntWithInfinity(IntWithInfinity::INF);
					} else {
						maxFullLength_.push(IntWithInfinity(0));
						mostLengthPrefix_.push(IntWithInfinity(0));
						mostLengthSuffix_.push(IntWithInfinity(0));
					}
				} else {
					mayFull_.push(true);
					maximalLength = std::max(maximalLength, longestSuffix + longestPrefix);
					maxFullLength_.push(IntWithInfinity(0));
					mostLengthPrefix_.push(longestPrefix);
					mostLengthSuffix_.push(longestSuffix);
				}
			} else if (symbol == '1') {
				mostLengthSuffix_.push(IntWithInfinity(0));
				mostLengthPrefix_.push(IntWithInfinity(0));
				mayFull_.push(true);
				maxFullLength_.push(IntWithInfinity(0));
			} else {
				throwRegexException();
			}
		}
		if (!mostLengthPrefix_.empty() || !mostLengthSuffix_.empty() ||
			!mayFull_.empty() || !maxFullLength_.empty()) {
			throwIllegalArgumentException();
		}
		if (maximalLength >= IntWithInfinity(number)) {
			return true;
		}
		return false;
	}
};

#endif // CHECK_REGEX_H
