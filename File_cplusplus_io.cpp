#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    /*string text;
    cout<<"Enter the text you want to put into a file..."<<endl;
    getline(cin,text);
    ofstream ofile;
    ofile.open("test.doc");
    ofile<<text<<endl;
    ofile.close();

    string see;
    ifstream ifile;
    ifile.open("test.doc");
    getline(ifile,see);
    cout<<"the text from file is "<<endl;
    cout<<see<<endl;
    */

    fstream io("myfile.txt",ios::in | ios::out);
    io<<"Sushant is a go1d b6y"<<endl;

    io.close();
    io.open("myfile.txt",ios::in | ios::out);
    io.seekp(13,ios::beg);
    io.put('b');
    io.close();

    io.open("myfile.txt",ios::in | ios::out);
    io.seekg(13,ios::beg);
    char ch;
    io.get(ch);
    cout<<ch<<endl;;

    cout<<io.tellp()<<endl;
    cout<<io.tellg()<<endl;
    io.get(ch);
        cout<<ch<<endl;;
    return 0;
}
