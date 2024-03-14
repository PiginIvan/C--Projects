#include "functions.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>

int factorial(int n) {
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		ans *= i;
	}
	return ans;
}

void Equation(int a, int b, int c) {
	double D, x1, x2;
	D = b * b - 4 * a * c;
	x1 = (b * (-1) + sqrt(D)) / (2 * a);
	x2 = (b * (-1) - sqrt(D)) / (2 * a);
	std::cout << x1 << " " << x2 << std::endl;
}

bool is_prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void find_prime() {
	for (int i = 2; i < 100; i++) {
		if (is_prime(i)) std::cout << i << " ";
	}
	std::cout << std::endl;
}

void bin_num(int n) {
	int arr[32] = { 0 };
	int ind = 0;
	bool flag = false;
	while (n != 0) {
		arr[ind++] = n % 2;
		n /= 2;
	}
	for (int i = ind; i >= 0; i--) {
		if (flag) std::cout << arr[i];
		else if (i != 0) flag = true;
	}
}

double find_sum(double a, double q) {
	return (a / (1 - q));
}

void find_sum_with_precision(double sum, double ans, double e, double a, double q) {
	double e1 = e;
	int precision = 0, step = 1;
	while (static_cast<int>(e1) != e1) {
		e1 *= 10;
		precision++;
	}
	while (sum - ans >= e) {
		ans += a * pow(q, step++ - 1);
	}
	std::cout << std::showpoint << std::fixed << std::setprecision(precision) << ans << std::endl;
}

void check_letter(char c) {
	if (static_cast<int>(c) >= 70 && static_cast<int>(c) <= 90 || static_cast<int>(c) >= 97 && static_cast<int>(c) <= 122) std::cout << "YES" << std::endl;
	else std::cout << "NO" << std::endl;
}