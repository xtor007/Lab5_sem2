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
    Point get(string rawInfo){
        string temp = "";
        string latitude = "";
        string longitude = "";
        string type = "";
        string subtype = "";
        string name = "";
        string adress = "";
        int counter = 0;
        for (int i = 0; i < rawInfo.size(); i++) {
            if (rawInfo[i] != ';') {
                if (rawInfo[i] == ',' && (counter == 0 || counter == 1)) {
                    rawInfo[i] = '.';
                }
                temp += rawInfo[i];
            }
            else{
                counter++;
                switch (counter) {
                    case 1:
                        latitude = temp;
                        break;
                    case 2:
                        longitude = temp;
                        break;
                    case 3:
                        type = temp;
                        break;
                    case 4:
                        subtype = temp;
                        break;
                    case 5:
                        name = temp;
                        break;
                    case 6:
                        adress = temp;
                        break;
                    default:
                        break;
                }
                temp = "";
            }
        }
        Point Destination(stod(latitude), stod(longitude), type, subtype, name, adress);
        return Destination;
    }
public:
    FileReader(string path, RTree &Tree, int &exitCode){
        this->path = path;
        ifstream file;
        file.open(path);
        if (file.is_open()) {
            int counter = 0;
            while (!file.eof()) {
                string tempStr = "";
                getline(file, tempStr);
                cout<<counter<<": "<<tempStr<<endl;
                Point place = get(tempStr);
                Tree.addPoint(&place);
                counter++;
            }
        }
        else{
            exitCode = 1;
        }
    }
};


#endif /* Reading_hpp */
