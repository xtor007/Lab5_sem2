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

using namespace std;

class FileReader{
    string path;
public:
    FileReader(string path, int &exitCode){
        this->path = path;
        ifstream file;
        file.open(path);
        if (file.is_open()) {
            int counter = 0;
            while (!file.eof()) {
                string tempStr = "";
                getline(file, tempStr);
                cout<<counter<<": "<<tempStr<<endl;
                counter++;
            }
        }
        else{
            exitCode = 1;
        }
    }
};


#endif /* Reading_hpp */
