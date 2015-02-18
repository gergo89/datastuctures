//
//  LinkedList.h
//  DataStructures
//
//  Created by Gergely Kalapos on 20/01/15.
//  Copyright (c) 2015 Gergely Kalapos. All rights reserved.
//

#ifndef DataStructures_LinkedList_h
#define DataStructures_LinkedList_h


template <class T>
class LinkedList{

private:
    struct Node{
    private:
        T value;
        
        std::shared_ptr<T> before;
        std::shared_ptr<T> after;
        
    public:
        Node(const std::shared_ptr<T>& before_,const std::shared_ptr<T> after_, const T& value_): before(before_), after(after_), value(value_){}
    };
    
    std::shared_ptr<T> head;
    
public:
    class Iterator{
        friend class LinkedList;
        
    private:
        std::shared_ptr<Node> current;
        
        
    public:
        Iterator(): current(nullptr){
            
        }
        
    };
    
    LinkedList(){
        
    }
    
    //Inserts an item to the position
    Iterator insert(Iterator iterator, const T& value){
       
        if(iterator.current == nullptr){
            std::make_shared<Node>( nullptr, nullptr , value);
        }
       
        return Iterator();
    }
    
    Iterator push_back(const T& value){
        return insert(Iterator(), value);
    }
};


#endif
