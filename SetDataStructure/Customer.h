#ifndef CUSTOMER_H
#define CUSTOMER_H

template <typename T>
class Customer {

private:
	T favoriteFood;

public:

	Customer(T);
	T getFavoriteFood() const;

	bool operator==(const Customer &other) const;

};

#include "Customer.cpp"
#endif