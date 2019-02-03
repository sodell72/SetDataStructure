#include "Cucumber.h"
#include <iostream>

Cucumber::Cucumber() : Vegetable() {
}

Cucumber::Cucumber(double weight, std::string color) : Vegetable(weight, color) {

}

void Cucumber::tellEveryBodyHowManyCucumbersIsTooManyCucumbers() {
	std::cout << "You can never have too many cucumbers!";
}
