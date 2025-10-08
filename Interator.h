//
// Created by Куимов Михаил on 08.10.2025.
//

#ifndef INTERATOR_H
#define INTERATOR_H

#ifndef ITERATOR_H
#define ITERATOR_H

#include <concepts>
#include <iterator>
#include <cstddef>

template<typename T>
concept Steppable = std::integral<T> || std::random_access_iterator<T>;

template<Steppable T>
class Iterator {
	T curr_;
	T fin_;
	std::ptrdiff_t step_;
public:
	explicit Iterator(T curr, T fin, std::ptrdiff_t step = 1)
		: curr_(curr), fin_(fin), step_(step) {}

	Iterator& operator++() {
		if constexpr (std::integral<T>) {
			auto next = static_cast<T>(curr_ + step_);
			curr_ = next < fin_ ? next : fin_;
		} else {
			auto next = curr_ + step_;
			curr_ = next < fin_ ? next : fin_;
		}
		return *this;
	}

	Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

	decltype(auto) operator*() const { return curr_; }

	bool operator==(const Iterator& other) const { return curr_ == other.curr_; }
	bool operator!=(const Iterator& other) const { return !(*this == other); }
};

#endif


#endif //INTERATOR_H
