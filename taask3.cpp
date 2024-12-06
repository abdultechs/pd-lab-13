#include<iostream>
#include<fstream>
using namespace std;
void output(int age, string name)
{
    //output file 
    if(age%2==0)
    {
        fstream file2;
        file2.open("D:\\PF\\PD13\\output\\output.txt", ios::out);
        file2 <<"###############" << endl;
        file2 << age << " HB " << name <<"! " << age << endl;
        file2 <<"###############" << endl;
        file2.close();
    }
    else
    {
        fstream file3;
        file3.open("output.txt", ios::out);
        file3 <<"***************" << endl;
        file3 << age << " HB " << name <<"! " << age << endl;
        file3 <<"***************" << endl;
        file3.close();
    }
}
main()
{
    string name;
    int age;

    cout << "name: ";
    cin >> name;
    cout << "age: ";
    cin >> age;
    
     //writing data
    fstream file;
    file.open("names.txt", ios::out);
    file << name;
    file <<",";
    file << age;
    file.close();
    //reading data now
    string line;
    fstream file1;
    file1.open("names.txt", ios::in);
    getline(file1, line);
    file1.close();
    
    output(age,name);
}