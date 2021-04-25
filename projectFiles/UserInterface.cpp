//
//  UserInterface.cpp
//  test
//
//  Created by Берлинский Ярослав Владленович on 24.04.2021.
//

#include "UserInterface.hpp"

Interface::Interface(){
    RTree tree;
    cout<< "Enter path to .csv-file: "; getline(cin, path);
    FileReader fileIn(path, tree, exitCode);
    if (exitCode) callError("We couldn't open the file");
    float latitude, longitude, radius;
    cout << "Enter your coordinates and radius of the desired sector:" << endl;
    cin >> latitude >> longitude >> radius;
    Point myPoint(latitude,longitude,"","","","");
    vector<Point*> resoult = tree.findNear(myPoint, radius);
    for (int i=0; i<resoult.size(); i++) {
        cout << resoult[i]->forPrint() << endl;
    }
}

void Interface::callError(string error){
    cout<<error<<endl;
    exit(1);
}
