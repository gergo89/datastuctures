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
public:
	class Iterator{
		friend class LinkedList;
	private:
		std::shared_ptr<Node> current;		
	public:
		Iterator() : current(nullptr){}
		Iterator(std::shared_ptr<Node> current_) : current(current_){}

	/*	Iterator& operator++();
		Iterator& operator--();

		T& operator*();*/
	};

    LinkedList();

	//Inserts an item to the position
	void insert(Iterator iterator, const T& value);
	void push_back(const T& value);
};


//Implementation
template <class T>
void LinkedList<T>::push_back(const T& value) {
	 insert(Iterator(), value);
}

//Inserts an item after the item pointed by the iterator
//If the iterator doesnt point to any item then it is inserted as the last item
template <class T>
void LinkedList<T>::insert(Iterator iterator, const T& value){
	
	std::shared_ptr<Node> newItem;

	if (iterator.current == nullptr){
		newItem = std::make_shared<Node>(nullptr, tail, value);
	}	

	if (!head->after){ //if this is the first item we inserted
		head->after = newItem;
        newItem->before = head;
        
        tail->before = newItem;
	}
   
    
    
    newItem->after = tail;
}

template<class T>
LinkedList<T>::LinkedList(){
    tail = std::make_shared<Node>(nullptr, nullptr, 0);
    head = std::make_shared<Node>(nullptr, nullptr, 0);
    
}

#endif
