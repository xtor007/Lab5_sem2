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

using namespace std;

class Interface{
    string path;
    int exitCode = 0;
    void callError(string error){
        cout<<error<<endl;
        exit(1);
    }
public:
    Interface(){
        RTree Tree;
        cout<<"Enter path to .csv-file: "; getline(cin, path);
        FileReader fileIn(path, Tree, exitCode);
        if (exitCode) callError("We couldn't open the file");
    }
};



#endif /* UserInterface_hpp */
