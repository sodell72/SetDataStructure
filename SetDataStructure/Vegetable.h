#pragma once
#include <string>

class Vegetable {

private:
	double weight;
	std::string color;
	


public:
	Vegetable();
	Vegetable(double, std::string);

	bool operator==(const Vegetable &other) const;

	double getWeight() const;
	std::string getColor() const;
};