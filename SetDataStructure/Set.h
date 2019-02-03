#ifndef SET_H
#define SET_H

#include <map>
#include <vector>
#include <string>

template<typename T>
class Set {

	template<typename U>
	friend std::ostream& operator<<(std::ostream&, const Set<U>&);

private:

	std::vector<T> data;
	std::vector<int> dataCount;

	int getIndex(T);
	

public:

	Set();
	bool contains(T);

	// big o is O(n).  this function calls getIndex which is O(n) because it 
	// loops through the elements in data once
	void add(T);


	int getCount(T);

	// big o is O(n).  It loops through the top vector several times so it is really O (k * nk).  so nk^2.
	// This is determined to be okay because k has a set size limit to 3. so at most it is 9n which is just n.
	std::vector<T*> getTop();




};



#include "Set.cpp"
#endif

