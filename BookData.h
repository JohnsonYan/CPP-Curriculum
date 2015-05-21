/*
    南航小型书店管理系统
    作者：闫珺 161420219
    时间：2015-5-17
    用于C++课程设计
*/
#ifndef BOOKDATA_H
#define BOOKDATA_H
#include"TitleInfo.h"
#include<iostream>
#include<string>
using namespace std;
class BookData : public TitleInfo
{
public:
    BookData();
    BookData(BookData &);

    //设置图书的全部信息
    void SetData();
    //设置图书的任意信息函数
    void setIsbn();
    void setBookTitle();
    void setAuthor();
    void setPublisher();
    void setDateAdded();
    void setQtyOnHand();
    void setWholesale();
    void setRetail();

    void setQtyOnHand(int n);
};
#endif // BOOKDATA_H

