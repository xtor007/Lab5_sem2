//
//  main.cpp
//  lab5
//
//  Created by Anatoliy Khramchenko on 24.04.2021.
//

#include <iostream>
#include "RTree.hpp"
#include "Reading.hpp"
#include "UserInterface.hpp"
using namespace std;

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

int main(int argc, const char * argv[]) {
    Point dot = get("51,67881;33,91008;shop;;АТБ;Терещенків вулиця,28;");
    cout<<dot.adress<<endl;
    Interface aga;
    return 0;
}
