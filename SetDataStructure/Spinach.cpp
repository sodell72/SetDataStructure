#include "Spinach.h"
#include <iostream>

Spinach::Spinach() : Vegetable() {

}

Spinach::Spinach(double weight, std::string color) : Vegetable(weight, color) {

}

void Spinach::tellEveryBodyWhatYouWishYouWere() {
	std::cout << "A cucumber!";
}
