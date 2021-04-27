//
//  output.hpp
//  test
//
//  Created by Берлинский Ярослав Владленович on 27.04.2021.
//

#ifndef output_hpp
#define output_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Point.hpp"

using namespace std;

class Output{
public:
    Output(string path, vector<Point*>);
};

#endif /* output_hpp */
