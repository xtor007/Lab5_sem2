//
//  UserInterface.cpp
//  test
//
//  Created by Берлинский Ярослав Владленович on 24.04.2021.
//

#include "UserInterface.hpp"

Interface::Interface(){
    RTree tree;  // firstly, initialize the tree
    cout<< "Enter path to .csv-file: "; getline(cin, path);
    FileReader fileIn(path, &tree, &exitCode);  // then, read the file
    if (exitCode) callError("We couldn't open the file");  // if path was wrong -> exit
    float latitude, longitude, radius;
    cout << "Enter your coordinates and radius(km) of the desired sector:" << endl;
    cin >> latitude >> longitude >> radius;
    Point myPoint(latitude,longitude,"","","","");  // creating the general point
    vector<Point*> resoult = tree.findNear(myPoint, radius);  // finding close points among others
    for (int i=0; i<resoult.size(); i++) {
        cout << i << ") " << resoult[i]->forPrint(myPoint.x, myPoint.y) << endl;  // outputing matching cases
        cout<<endl;
    }
}

void Interface::callError(string error){
    cout<<error<<endl;
    exit(1);
}
