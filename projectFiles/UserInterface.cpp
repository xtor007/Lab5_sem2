//
//  UserInterface.cpp
//  test
//
//  Created by Берлинский Ярослав Владленович on 24.04.2021.
//

#include "UserInterface.hpp"

Interface::Interface(){
    RTree Tree;
    cout<<"Enter path to .csv-file: "; getline(cin, path);
    FileReader fileIn(path, Tree, exitCode);
    if (exitCode) callError("We couldn't open the file");
}

void Interface::callError(string error){
    cout<<error<<endl;
    exit(1);
}
