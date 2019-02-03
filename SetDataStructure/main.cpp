#include <iostream>
#include "Vegetable.h"
#include "Cucumber.h"
#include "Spinach.h"
#include "Customer.h"
#include "Set.h"

using namespace std;

// Instructions on how to execute:  double click executable
// Screen capture included in zip file

int main(int argc, char* argv[]) {

	// tests superclass creation
	Vegetable myVegetable(20.5, "puRple");
	// tests variance capture
	cout << "tests to letter case variance capture: " << myVegetable.getColor() << endl;
	// tests child class creation
	Cucumber myCucumber(15, "green");
	Spinach mySpinach(0.88, "darkGreen");
	cout << endl;

	// tests ability to handle all objects
	Customer<Vegetable> vegetableCustomer(myVegetable);
	cout << "This vegetableCustomer's favorite food is the color: " << vegetableCustomer.getFavoriteFood().getColor() 
		<< " and it weighs: " << vegetableCustomer.getFavoriteFood().getWeight() << endl;
	Customer<Cucumber> cucumberCustomer(myCucumber);
	Customer<Spinach> spinachCustomer(mySpinach);
	//// tests capability to handle polymorphism
	Customer<Vegetable> veggieCucumberCustomer(myCucumber);
	Customer<std::string> tofuCustomer("tofu");
	// tests capability to handle primitive
	Customer<int> intCustomer(2);
	cout << endl;

	// test overwritten ==
	Vegetable equalVegetable(15, "green");
	Vegetable equalVegetable2(15, "green");
	cout << "equal vegetables return 1: " << (equalVegetable == equalVegetable2) << endl;
	Customer<Vegetable> equalCustomer(equalVegetable);
	Customer<Vegetable> equalCustomer2(equalVegetable2);
	bool areEqualCustomers = (equalCustomer == equalCustomer2);  // revisit const application here
	cout << "equal customers return 1: " << areEqualCustomers << endl;
	cout << endl;

	Set<Customer<Vegetable>> mySet;
	Vegetable pumpkin(600.62, "orange");
	Customer<Vegetable> pumpkinCustomer(pumpkin);
	// contains returns 0 if nothing in set
	cout << "empty set returns 0 for contains: " << mySet.contains(equalCustomer) << endl;
	mySet.add(pumpkinCustomer);
	mySet.add(equalCustomer);
	cout << "set with equalCustomer returns 1 for contains: " << mySet.contains(equalCustomer) << endl;
	cout << "equalCustomer was added 1 time: " << mySet.getCount(equalCustomer) << endl;
	Customer<Vegetable> veggieSpinachCustomer(mySpinach);
	cout << "veggieSpinachCustomer was added 0 times: " << mySet.getCount(veggieSpinachCustomer) << endl;
	mySet.add(veggieSpinachCustomer);
	mySet.add(equalCustomer);
	mySet.add(equalCustomer);
	mySet.add(equalCustomer2);
	cout << "equalCustomer (including 2) was added 4 times: " << mySet.getCount(equalCustomer) << endl;
	cout << "veggieSpinachCustomer was added 1 times: " << mySet.getCount(veggieSpinachCustomer) << endl;
	Vegetable eggplant(3.3, "purple");
	Customer<Vegetable> eggplantCustomer(eggplant);
	// adding more customers to get up/above to 10 attempted adds
	mySet.add(eggplantCustomer);
	mySet.add(eggplantCustomer);
	mySet.add(eggplantCustomer);
	mySet.add(eggplantCustomer);
	mySet.add(eggplantCustomer);
	mySet.add(eggplantCustomer);
	mySet.add(eggplantCustomer);
	mySet.add(eggplantCustomer);
	mySet.add(veggieSpinachCustomer);
	mySet.add(equalCustomer);
	mySet.add(equalCustomer2);
	mySet.add(equalCustomer2);
	mySet.add(equalCustomer2);
	mySet.add(equalCustomer2);
	mySet.add(equalCustomer2);
	mySet.add(equalCustomer2);
	cout << "equalCustomer (including 2) was added 11 times: " << mySet.getCount(equalCustomer) << endl;
	cout << "veggieSpinachCustomer was added 2 times: " << mySet.getCount(veggieSpinachCustomer) << endl;
	cout << "eggplantCustomer (including 2) was added 8 times: " << mySet.getCount(eggplantCustomer) << endl;
	cout << "veggieCucumberCustomer was added 1 times: " << mySet.getCount(pumpkinCustomer) << endl;
	cout << endl;

	// displays top 3 keys and their properties
	std::vector<Customer<Vegetable>*> top = mySet.getTop();
	cout << "the top 3 in order should have (weight = 15, color = green), (weight = 3.3, color = purple), " <<
		"(weight = 0.88, color = darkgreen): " << endl;
	cout << "(weight = " << top[0]->getFavoriteFood().getWeight() << ", color = " << top[0]->getFavoriteFood().getColor() << "), " << endl <<
		"(weight = " << top[1]->getFavoriteFood().getWeight() << ", color = " << top[1]->getFavoriteFood().getColor() << "), " << endl <<
		"(weight = " << top[2]->getFavoriteFood().getWeight() << ", color = " << top[2]->getFavoriteFood().getColor() << ")" << endl;
	cout << endl;

	cout << mySet << endl;


	cin.get();
}