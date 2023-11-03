#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class Number{
    int Num1,Num2,Num3,File;
    char Name[30];
public:
    Number(){
        Num1=Num2=Num3=0; File=0;
        strcpy(Name,"No-Name");
    }
    int Counter(int);
    void ShowData();
    void GetData();
    void GetName(char*);
    void Enter();
    void Read();
    int SearchNumber(int);
    int Search(char*);
    void DeleteNumber(int);
    void Delete(char*);
    void Update(char* );
};
