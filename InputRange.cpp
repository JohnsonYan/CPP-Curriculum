#include"InputRange.h"
#include<string.h>
#include<ctype.h>
#include<iostream>
using namespace std;
InputRange::InputRange( char low, char high, const char *str)//���캯��
{
    lower = toupper(low);
    upper = toupper(high);
    errMsg = new char [strlen(str)+1];
    strcpy(errMsg,str);
}
InputRange::~InputRange()//��������
{
    delete []errMsg;
}
char InputRange::getInput()
{
    cin.get(input);
    cin.ignore();
    input = toupper(input);

    while(input < lower || input > upper)
    {
        cout << errMsg;
        cin.get(input);
        cin.ignore();
        input = toupper(input);
    }
    return input;
}
