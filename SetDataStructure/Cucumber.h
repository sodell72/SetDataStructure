#pragma once
#include "Vegetable.h"

class Cucumber : public Vegetable {


public:
	Cucumber();
	Cucumber(double, std::string);
	void tellEveryBodyHowManyCucumbersIsTooManyCucumbers();
};