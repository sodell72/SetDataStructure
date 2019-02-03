//#include "Customer.h"

#ifdef CUSTOMER_H

// see vegetable class for invariants capture
template<typename T>
Customer<T>::Customer(T favoriteFood) {
	this->favoriteFood = favoriteFood;
}

template<typename T>
T Customer<T>::getFavoriteFood() const{
	return this->favoriteFood;
}

template<typename T>
bool Customer<T>::operator==(const Customer &other) const{
	return (this->getFavoriteFood() == other.getFavoriteFood());
}


#endif