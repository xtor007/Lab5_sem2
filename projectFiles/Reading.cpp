//
//  Reading.cpp
//  test
//
//  Created by Берлинский Ярослав Владленович on 24.04.2021.
//

#include "Reading.hpp"

FileReader::FileReader(string path, RTree *tree, int *exitCode){
    this->path = path;
    ifstream file;
    file.open(path);
    vector<Point> data;
    if (file.is_open()) {
        //int counter = 0;
        while (!file.eof()) {
            string tempStr = "";
            getline(file, tempStr);
            //cout<<counter<<": "<<tempStr<<endl;
            Point place = readLine(tempStr);
            data.push_back(place);
            //counter++;
        }
    }
    else{
        *exitCode = 1;  // for case if input is wrong
    }
    if (!*exitCode) for (int i=0; i<=data.size(); i++) tree->addPoint(&data[i]); // if all is OK -> we add point to the tree structure
}

Point FileReader::readLine(string rawInfo){
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
                rawInfo[i] = '.';  // "floats" in the file were written with ',' but compiler sees only '.'
            }
            temp += rawInfo[i];
        } else{
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
