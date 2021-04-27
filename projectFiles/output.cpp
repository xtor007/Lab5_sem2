//
//  output.cpp
//  test
//
//  Created by Берлинский Ярослав Владленович on 27.04.2021.
//

#include "output.hpp"

Output::Output(string path, vector<Point*> points){
    ofstream out;
    out.open(path);
    setlocale(LC_CTYPE, "Russian");
    
    if (out.is_open()) {
        out<<"№;"<<"широта ї;"<<"Longitude;"<<"Name;"<<"Type;"<<"Subtype;"<<"Adress;\n";
        for (int i = 0; i < points.size(); i++) {
            cout<<points[i]->longitude<<points[i]->latitude<<endl<<points[i]->adress<<endl;
            out<<i<<";"<<points[i]->latitude<<
            ";"<<points[i]->longitude<<
            ";"<<points[i]->name<<
            ";"<<points[i]->type<<
            ";"<<points[i]->subtype<<
            ";"<<points[i]->adress<<endl;
        }
        out.close();
    }
    else{
        cout<<"We can't open the file\n"<<endl;
    }
}

/*
 int main()
 {
     std::ofstream out;            // поток для записи
     out.open("D:\\hello.txt"); // окрываем файл для записи
     if (out.is_open())
     {
         out << "Hello World!" << std::endl;
     }
     
     std::cout << "End of program" << std::endl;
     return 0;
 }
 */
