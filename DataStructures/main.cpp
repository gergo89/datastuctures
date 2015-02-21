//
//  main.cpp
//  DataStructures
//
//  Created by Gergely Kalapos on 19/01/15.
//  Copyright (c) 2015 Gergely Kalapos. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    LinkedList<int> l;
    
    l.insert(l.first(), 11);
    
    l.push_back(3);
    l.push_back(5);
    
    l.insert(l.first(), 1);
    

    
    l.print();
    
    std::cout << "List used in main" <<std::endl;
    
    auto listIterator = l.first();
    std::cout << *listIterator;
    
    std::cout << "Next item:" << std::endl;
    ++listIterator;
    std::cout << *listIterator;
    
    
    
    return 0;
}
