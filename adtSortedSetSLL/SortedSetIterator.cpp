#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m){

	//node* currentElem = new node;
	currentElem = this->multime.head;
}


void SortedSetIterator::first() {
	//complexity theta(1)
	currentElem = this->multime.head;
}


void SortedSetIterator::next() {
	//complexity theta(1)

	if (!valid()) {
		throw exception();
	}
	else {
		currentElem = currentElem->next;
	}
}


TElem SortedSetIterator::getCurrent(){
	//complexity theta(1)

	if (valid() == false) {
		throw exception();
	}
	else {
		return currentElem->info;
	}
	return NULL_TELEM;
}

bool SortedSetIterator::valid() const {
	//complexity theta(1)

	if (currentElem != nullptr && this->multime.head != nullptr) {
		return true;
	}
	return false;
}

