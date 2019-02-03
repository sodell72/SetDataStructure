#include "Vegetable.h"
#include <algorithm>


Vegetable::Vegetable() {

}

Vegetable::Vegetable(double weight, std::string color) {
	transform(color.begin(), color.end(), color.begin(), ::tolower);
	this->color = color;
	if (weight < 0) {
		weight = 0;
	}
	this->weight = weight;
}


bool Vegetable::operator==(const Vegetable &other) const {
	if ((this->getWeight() == other.getWeight()) && (this->getColor() == other.getColor())) {
		return true;
	}
	return false;

}

double Vegetable::getWeight() const {
	return this->weight;
}

std::string Vegetable::getColor() const {
	return this->color;
}
