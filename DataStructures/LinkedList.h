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
    int _size;
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
		Iterator& operator--();
        Iterator operator--(int);

		T& operator*();
	};

    LinkedList();

	//Inserts an item to the position
	Iterator insert(Iterator iterator, const T& value);
	Iterator push_back(const T& value);
    Iterator push_front(const T& value);
    
    Iterator remove(Iterator iterator, const T& value);
    Iterator delete_back(const T& value);
    Iterator delete_front(const T& value);
    
    Iterator first() const;
    Iterator last() const;
    Iterator end() const;
    
    int size() const;
    
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
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator--(){
    if(!current){
        throw "Invalid operator";
    }
    
    current = current->before;
    return *this;
}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator--(int){
    
    if(!current){
        throw "Invalid operator";
    }
    
    auto _current = current;
    _current = _current->before;
    return _current;
}

template <class T>
T& LinkedList<T>::Iterator::operator*(){
    return current->value;
}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::push_back(const T& value) {
    return insert(Iterator(), value);
}

//Inserts an item after the item pointed by the iterator
//If the iterator doesnt point to any item then it is inserted as the last item
template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::insert(Iterator iterator, const T& value){
	
	std::shared_ptr<Node> newItem;
    
	if (iterator.current == nullptr){
		newItem = std::make_shared<Node>(nullptr, nullptr, value);
    }else{
        newItem = std::make_shared<Node>(iterator.current, iterator.current->after, value);
    }
    
    if(!head){ //if the list is empty
        head = newItem;
        tail = newItem;
    }
    else if(newItem->after == nullptr){ //if we insert it as the last item
        tail->after = newItem;
        tail = newItem;
    }
    else{ //if it is somewhere in the middle
        newItem->before->after = newItem->after->before = newItem;
    }
    
    _size++;
    return Iterator(newItem);
}

template<class T>
LinkedList<T>::LinkedList(): tail(nullptr), head(nullptr), _size(0){

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

template <class T>
int LinkedList<T>::size() const{
    return _size;
}

#endif
