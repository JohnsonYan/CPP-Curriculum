/*
    南航小型书店管理系统
    作者：闫珺 161420219
    时间：2015-5-17
    用于C++课程设计
*/
#ifndef SALE_H
#define SALE_H
#include"BookData.h"
class Sale : public BookData
{
private:
    int buycount;
    double total;
    BookData book[1000],buy[100];
public:
    Sale();
    void addBook();
    void getBuy();
    void getCash();
    void getData();//打开书库文件并将文件中的图书信息读取到内存中
    void putData();//在系统结束前，将图书信息写入书库文件中
};
#endif // SALE_H
