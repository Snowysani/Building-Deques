//
//  node.h
//  Gallegos_Michael_PA2
//
//  Created by Michael Gallegos on 10/8/18.
//  Copyright © 2018 Michael Gallegos. All rights reserved.
//

#ifndef node_h
#define node_h
#include <iostream>
using namespace std;

template<class Type>
struct node{
    node *previous;
    Type data;
    node *next;
};

#endif /* node_h */
