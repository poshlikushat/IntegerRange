//
// Created by Куимов Михаил on 08.10.2025.
//
#include <vector>
#include <array>
#include <iostream>
#include "./Range.h"

int main() {
	for (auto x : Range<int>(0, 10, 3)) std::cout << x << ' ';

	std::cout << '\n';
	std::vector<int> v{0,1,2,3,4,5,6};
	for (auto it : Range(v, 2)) std::cout << *it << ' ';

	std::cout << '\n';
	int a[] = {10,20,30,40,50,60};
	for (auto it : Range(std::begin(a), std::end(a), 2)) std::cout << *it << ' ';

	std::cout << '\n';
	std::array<int,7> ar{0,1,2,3,4,5,6};
	for (auto it : Range(ar, 3)) std::cout << *it << ' ';
}
