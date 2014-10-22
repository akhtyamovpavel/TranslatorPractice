#ifndef TEST_REGEX_H
#define TEST_REGEX_H

#include <stdexcept>
#include <string>
#include "CheckRegex.h"

void throwCheckException(const std::string& message) {
	throw std::logic_error("Wrong answer on test " + message);
}

bool runCheck(const std::string& expression, int k, char letter) {
	CheckRegex checker(expression);
	return checker.checkRegexForLetterWord(letter, k);
}

void unitCheck() {
	std::string expression;
	int k;
	char letter;
	{
		expression = "1";
		k = 0;
		letter = 'a';
		if (!runCheck(expression, k, letter)) {
			throwCheckException("Test 1");
		}
	}
	{
		expression = "1*";
		k = 2;
		letter = 'a';
		if (runCheck(expression, k, letter)) {
			throwCheckException("Test 2");
		}
	}
	{
		expression = "a";
		k = 1;
		letter = 'a';
		if (!runCheck(expression, k, letter)) {
			throwCheckException("Test 3");
		}
	}
	{
		expression = "a*";
		k = 100500;
		letter = 'a';
		if (!runCheck(expression, k, letter)) {
			throwCheckException("Test 4");
		}
	}
	{
		expression = "b*";
		k = 1;
		letter = 'a';
		if (runCheck(expression, k, letter)) {
			throwCheckException("Test 5");
		}
	}
	{
		expression = "ab+c.";
		k = 2;
		letter = 'a';
		if (runCheck(expression, k, letter)) {
			throwCheckException("Test 6");
		}
	}
	{
		expression = "ba.b.*";
		k = 2;
		letter = 'b';
		if (!runCheck(expression, k, letter)) {
			throwCheckException("Test 7");
		}
	}
	{
		expression = "aa.b.*";
		k = 4;
		letter = 'a';
		if (runCheck(expression, k, letter)) {
			throwCheckException("Test 8");
		}
	}
	{
		expression = "ca.a.c*";
		k = 4;
		letter = 'c';
		if (!runCheck(expression, k, letter)) {
			throwCheckException("Test 9");
		}
	}
	{
		expression = "ab+";
		k = 1;
		letter = 'b';
		if (!runCheck(expression, k, letter)) {
			throwCheckException("Test 10");
		}
	}
	{
		expression = "abc.+a.a.ab.c+.";
		k = 4;
		letter = 'a';
		if (!runCheck(expression, k, letter)) {
			throwCheckException("Test 11");
		}
	}
	{
		expression = "abc.+a.a.ab.c+.";
		k = 5;
		letter = 'a';
		if (runCheck(expression, k, letter)) {
			throwCheckException("Test 12");
		}
	}
	{
		expression = "abc.+a.1.a.1.ab.c+.";
		k = 4;
		letter = 'a';
		if (!runCheck(expression, k, letter)) {
			throwCheckException("Test 13");
		}
	}
	{
		expression = "abc.+a.1.a.1.ab.c+.1.a";
		k = 5;
		letter = 'a';
		if (runCheck(expression, k, letter)) {
			throwCheckException("Test 14");
		}
	}
	{
		expression = "cab.+b.1.b.1.ba.c+1+.b.b.b.";
		k = 6;
		letter = 'b';
		if (!runCheck(expression, k, letter)) {
			throwCheckException("Test 15");
		}
	}
	{
		expression = "cab.+b.1.b.1.ba.c+1+.b.b.b.";
		k = 7;
		letter = 'b';
		if (runCheck(expression, k, letter)) {
			throwCheckException("Test 16");
		}
	}
	{
		expression = "a*b.c*.b.";
		k = 2;
		letter = 'b';
		if (!runCheck(expression, k, letter)) {
			throwCheckException("Test 17");
		}
	}
	{
		expression = "a*b.c*.b.";
		k = 100500;
		letter = 'b';
		if (runCheck(expression, k, letter)) {
			throwCheckException("Test 18");
		}
	}
	{
		expression = "a*b.c*.b.";
		k = 100500;
		letter = 'c';
		if (!runCheck(expression, k, letter)) {
			throwCheckException("Test 19");
		}
	}
	{
		expression = "a*b.c*.b.";
		k = 100500;
		letter = 'a';
		if (!runCheck(expression, k, letter)) {
			throwCheckException("Test 20");
		}
	}
}

#endif // TEST_REGEX_H
