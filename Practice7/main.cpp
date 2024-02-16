#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "functions.hpp"

#define TASK2

#ifdef TASK1

int main() {
	std::string s;
	std::cin >> s;
	if (IsPalindrome(s)) std::cout << "Cur string is a palindrome";
	else std::cout << "Cur string is not a palindrome";
	return 0;
}
#endif

#ifdef TASK2

int main() {
	std::string s;
	getline(std::cin, s);
	std::vector<std::string> words;
	int count = 0, start = 0, flag = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') continue;
		else if (s[i] != ' ') {
			if (flag == 1) {
				start = i;
				flag = 0;
			}
			count++;
		}
		if ((s[i] != ' ' && s[i + 1] == ' ') || (i == s.size()-1)) {
			std::string word(s, start, count);
			words.push_back(word);
			flag = 1; count = 0;
		}
	}
	sort(words.begin(), words.end(), comp);
	for (std::string word : words) {
		std::cout << word << " ";
	}
	return 0;
}
#endif
