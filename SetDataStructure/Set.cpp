#ifdef SET_H
#include <iterator>
#include <algorithm>
#include "Set.h"
#include <iostream>

template<typename T>
Set<T>::Set() {

}

template<typename T>
void Set<T>::add(T item) {
	int index = this->getIndex(item);
	if (index >= 0) {
		dataCount[index]++;
	} else {
		data.push_back(item);
		dataCount.push_back(1);
	}
}

template<typename T>
int Set<T>::getCount(T item) {
	int index = 0;
	for (auto &element : data) {
		if (data[index] == item) {
			return dataCount[index];
		}
		index++;
	}
	return 0;
}


template<typename T>
bool Set<T>::contains(T item) {
	//for (size_t i = 0; i < data2.size(); i++) {
	//	if (data2[i] == item) {
	//		return true;
	//	}
	//}
	for (auto &element : data) {
		if (element == item) {
			return true;
		}
	}
	return false;
}


template<typename T>
int Set<T>::getIndex(T item) {
	int index = 0;
	for (auto &element : data) {
		if (data[index] == item) {
			return index;
		}
		index++;
	}
	return -1;
}


template<typename T>
std::vector<T*> Set<T>::getTop() {
	//T* top[3];
	std::vector<T*> top{ nullptr, nullptr, nullptr };

	for (size_t j = 0; j < 3; j++) {
		int maxDataCount = 0;
		int maxDataIndex = -1;
		for (size_t i = 0; i < dataCount.size(); i++) {
			bool topContains = false;
			for (auto &element : top) {
				if (element != nullptr && *element == data[i]) {
					topContains = true;
				}
			}
			if (!topContains && (dataCount[i] > maxDataCount)) {
				maxDataCount = dataCount[i];
				maxDataIndex = i;
			} 
		}

		top[j] = &data[maxDataIndex];

	}

	return top;
}


template<typename T>
std::ostream& operator<<(std::ostream& out, const Set<T>& input) {
	int count = 0;
	for (auto& element : input.data) {
		out << "item " << count << " weighs: " << element.getFavoriteFood().getWeight() <<
			" and is: " << element.getFavoriteFood().getColor() << " It's count is: " << input.dataCount[count] << std::endl;
		count++;
	}
	return out;
}



#endif

