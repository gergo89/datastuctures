//
//  LinkedList.h
//  DataStructures
//
//  Created by Gergely Kalapos on 20/01/15.
//  Copyright (c) 2015 Gergely Kalapos. All rights reserved.
//

#ifndef DataStructures_LinkedList_h
#define DataStructures_LinkedList_h

#include <memory>

template <class T>
class LinkedList{

private:
	struct Node{	
	public:
		T value;
		std::shared_ptr<Node> before;
		std::shared_ptr<Node> after;
		Node(const std::shared_ptr<Node>& before_, const std::shared_ptr<Node> after_, const T& value_) : before(before_), after(after_), value(value_){}
	};

	std::shared_ptr<Node> head;
	std::shared_ptr<Node> tail;
    int size;
public:
	class Iterator{
		friend class LinkedList;
	private:
		std::shared_ptr<Node> current;		
	public:
		Iterator() : current(nullptr){}
		Iterator(std::shared_ptr<Node> current_) : current(current_){}
 
        bool operator!=(const Iterator& it) const;
        bool operator==(const Iterator& it) const;
        
		Iterator& operator++();
        Iterator operator++(int);
/*		Iterator& operator--();

		T& operator*();*/
	};

    LinkedList();

	//Inserts an item to the position
	void insert(Iterator iterator, const T& value);
	void push_back(const T& value);
    
    Iterator first() const;
    Iterator last() const;
    Iterator end() const;
    
    void print() const;
};


//Implementation

template <class T>
bool  LinkedList<T>::Iterator::operator!=(const Iterator& it) const{
    return it.current != current;
}

template <class T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++(){
    
    if(!current){
        throw "Invalid operator";
    }
    
    current = current->after;
    return *this;
}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++(int){
    
    if(!current){
        throw "Invalod operator";
    }
    
    auto _current = current;
    _current = _current->after;
    
    return _current;
}


template <class T>
void LinkedList<T>::push_back(const T& value) {
    
    auto newNode = std::make_shared<Node>(tail, nullptr, value);
    
    if(size == 0){
        head = newNode;
    } else{
        tail->after = newNode;
    }
    
    tail = newNode;
    size++;
}

//Inserts an item after the item pointed by the iterator
//If the iterator doesnt point to any item then it is inserted as the last item
template <class T>
void LinkedList<T>::insert(Iterator iterator, const T& value){
	
	std::shared_ptr<Node> newItem;

	if (iterator.current == nullptr){
		newItem = std::make_shared<Node>(nullptr, tail, value);
	}	

	if (!head){ //if this is the first item we inserted
        head = std::make_shared<Node>(nullptr, newItem, 0);
        head->after = newItem;
        newItem->before = head;
        
        //tail->before = newItem;
	}
   
    
    
    newItem->after = tail;
}

template<class T>
LinkedList<T>::LinkedList(): tail(nullptr), head(nullptr), size(0){

}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::first() const{
    return Iterator(head);
}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::last() const{
    return Iterator(tail->before);
}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::end() const{
    return Iterator(tail->after);
}

template <class T>
void LinkedList<T>::print() const{
    
    for (Iterator act = first(); act != end(); ++act) {
        std::cout << act.current->value << std::endl;
    }
}

#endif
