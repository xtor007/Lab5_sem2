//
//  UserInterface.hpp
//  test
//
//  Created by Берлинский Ярослав Владленович on 24.04.2021.
//

#ifndef UserInterface_hpp
#define UserInterface_hpp

#include <stdio.h>
#include <iostream>
#include "Reading.hpp"
#include "RTree.hpp"
#include "output.hpp"

using namespace std;

class Interface{
    string path;
    int exitCode = 0;
    void callError(string error);
public:
    Interface();
};



#endif /* UserInterface_hpp */
