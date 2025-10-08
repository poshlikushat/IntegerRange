//
// Created by Куимов Михаил on 08.10.2025.
//

#ifndef RANGE_H
#define RANGE_H

#ifndef RANGE_H
#define RANGE_H

#include <concepts>
#include <iterator>
#include <cstddef>
#include <type_traits>
#include <iostream>
#include <utility>
#include "Iterator.h"

template<typename C>
concept RandomAccessContainer =
	requires(C c) {
	{ std::begin(c) } -> std::random_access_iterator;
	{ std::end(c) } -> std::same_as<decltype(std::begin(c))>;
	};

template<Steppable T>
class Range {
	T start_, finish_;
	std::ptrdiff_t step_;
public:
	explicit Range(T end) : start_(0), finish_(end), step_(1) {
		if constexpr (std::integral<T>) {
			if (finish_ < start_) std::cerr << "Range error: end must be greater than start\n";
		}
	}

	Range(T start, T end, std::ptrdiff_t step = 1)
		: start_(start), finish_(end), step_(step) {
		if (step_ <= 0) std::cerr << "Range error: step must be greater than 0\n";
		if constexpr (std::random_access_iterator<T>) {
			if (finish_ < start_) std::cerr << "Range error: end iterator before start\n";
		}
	}

	template<RandomAccessContainer C>
	explicit Range(C& c, std::ptrdiff_t step = 1)
		: start_(std::begin(c)), finish_(std::end(c)), step_(step) {
		if (step_ <= 0) std::cerr << "Range error: step must be greater than 0\n";
	}

	Iterator<T> begin() const { return Iterator<T>(start_, finish_, step_); }
	Iterator<T> end()   const { return Iterator<T>(finish_, finish_, step_); }
};

template<RandomAccessContainer C>
Range(C&, std::ptrdiff_t)
	-> Range<decltype(std::begin(std::declval<C&>()))>;

template<RandomAccessContainer C>
Range(const C&, std::ptrdiff_t)
	-> Range<decltype(std::begin(std::declval<const C&>()))>;

#endif


#endif //RANGE_H
