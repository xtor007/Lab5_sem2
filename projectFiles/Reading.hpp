//
//  Reading.hpp
//  test
//
//  Created by Берлинский Ярослав Владленович on 24.04.2021.
//

#ifndef Reading_hpp
#define Reading_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "RTree.hpp"

using namespace std;

class FileReader{
    string path;
    Point readLine(string rawInfo);
public:
    FileReader(string path, RTree *Tree, int &exitCode);
};


#endif /* Reading_hpp */
