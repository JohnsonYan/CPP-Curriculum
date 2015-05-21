/*
    南航小型书店管理系统
    作者：闫珺 161420219
    时间：2015-5-17
    用于C++课程设计
*/
#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include"BookData.h"

class Management
{
public:
    BookData book[1000];
    void findBook();//寻找某本图书信息
    void addBook();//增加图书
    void editBook();//修改图书信息
    void deleteBook();//删除图书
    void getData();//打开书库文件并将文件中的图书信息读取到内存中
    void putData();//在系统结束前，将图书信息写入书库文件中
};
#endif // MANAGEMENT_H
