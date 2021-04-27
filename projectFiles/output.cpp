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
    if (out.is_open()) {
        out<<endl;
        for (int i = 0; i < points.size(); i++) {
            out<<i<<")|"<<setw(10)<<points[i]->latitude<<setw(10)<<
            "|"<<setw(10)<<points[i]->longitude<<setw(10)<<
            "|"<<setw(10)<<points[i]->type<<setw(10)<<
            "|"<<setw(10)<<points[i]->subtype<<setw(10)<<
            "|"<<setw(10)<<points[i]->adress<<endl;
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
