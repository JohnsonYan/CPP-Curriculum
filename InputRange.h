/*
    南航小型书店管理系统
    作者：闫珺 161420219
    时间：2015-5-17
    用于C++课程设计
*/
#ifndef INPUTRANGE_H
#define INPUTRANGE_H
/* 此类用于检验是否输入了有效对象*/
class InputRange
{
private:
    char *errMsg;//出错信息
    char input;//用户输入值
    char lower;//有效字符的低界
    char upper;//有效字符的高界
public:
    InputRange(  char , char ,const char *);//该类的构造函数
    ~InputRange();//析构函数
    char getInput();
};
#endif // INPUTRANGE_H
