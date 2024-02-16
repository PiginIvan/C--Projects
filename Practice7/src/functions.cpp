#include "functions.hpp"

bool IsPalindrome(std::string s) {
	std::string::iterator left = s.begin();
	std::string::iterator right = s.end() - 1;
	while (left < right) {
		if (*left != *right) return false;
		left++; right--;
	}
	return true;
}

bool comp(std::string a, std::string b) {
	return (a.size() < b.size());
}