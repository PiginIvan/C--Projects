#include <iostream>
#include <iomanip>
#include "functions.hpp"

#define TASK1

#ifdef TASK1

int main() {
	int n;
	std::cin >> n;
	std::cout << factorial(n) << std::endl;
	return 0;
}

#endif

#ifdef TASK2

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	Equation(a, b, c);
	return 0;
}

#endif

#ifdef TASK3

int main() {
	find_prime();
	return 0;
}

#endif

#ifdef TASK4

int main() {
	int n = 0;
	std::cin >> n;
	bin_num(n);
	return 0;
}

#endif

#ifdef TASK5

int main() {
	double a = 0, q = 0, e = 0;
	std::cin >> a >> q >> e;
	double sum = find_sum(a, q), ans = 0;
	find_sum_with_precision(sum, ans, e, a, q);
	return 0;
}

#endif

#ifdef TASK6

int main() {
	char c;
	std::cin >> c;
	check_letter(c);
	return 0;
}

#endif