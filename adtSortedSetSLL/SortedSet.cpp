#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) {

	this->relation = r;
	this->head = new node; //nullptr
}


bool SortedSet::add(TComp elem) {
	//complexity O(n)

	node* current = this->head, newNode;

	//if the list is empty
	if (isEmpty() == true) {
		this->head->info = elem;
		this->head->next = nullptr;
		return true;
	}

	//if the element already exists
	if (search(elem) == true) {
		return false;
	}

	while (current != nullptr) {
		if (relation(elem, current->info) == true) {	
			newNode.info = elem;
			newNode.next = current;
			return true;
		}
		if (relation(current->info, elem) == true) {	
			newNode.info = elem;
			newNode.next = current->next;
			current->next = &newNode;
			return true;
		}
		current = current->next;
	}
	return false;
}


bool SortedSet::remove(TComp elem) {
	//complexity O(n)

	node* current = this->head, *previous = nullptr;

	//if the set is empty, we cannot delete anything
	if (isEmpty() == true) {
		return false;
	}

	while (current != nullptr && current->info != elem) {	//we search the element
		previous = current;
		current = current->next;
	}

	if (current != nullptr && previous == nullptr) {	//if the searched element is in the head 
		this->head = this->head->next;
		return true;
	}
	else {
		if (current != nullptr) {	//if the searched element is not in the head 
			previous->next = current->next;
			current->next = nullptr;
			return true;
		}
	}
	//if the element doesn't exist, we cannot delete it
	return false;
}


bool SortedSet::search(TComp elem) const {
	//complexity O(n)

	node* current = this->head;

	while (current != nullptr) {
		if (current->info == elem) {
			return true;
		}
		current = current->next;
	}
	return false;
}


int SortedSet::size() const {
	//complexity theta(n)

	int count = 0;
	node* current = this->head;

	while (current != nullptr) {
		count++;
		current = current->next;
	}
	return count;
}



bool SortedSet::isEmpty() const {
	//complexity theta(1)

	node* current = this->head;

	if (current == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
	//complexity theta(n)

	node* ptr;

	for (ptr = head; head; ptr = head){
		this->head = this->head->next;
		delete ptr;
	}
}

node SortedSet::set_intervall(TComp a, TComp b) {
	//complexity theta(n)

	node* current = this->head;		
	node result;		

	result.next = nullptr;
	while (current != nullptr) {

		if (current->info >= a && current->info <= b) {
			result.next = current;
		}

		current = current->next;
	}

	return result;
}

