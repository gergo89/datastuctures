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
    
    l.push_back(3);
    l.push_back(5);
    
    l.print();
    
    return 0;
}
