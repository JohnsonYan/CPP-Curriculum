/*
    �Ϻ�С��������ϵͳ
    ���ߣ��ƬB 161420219
    ʱ�䣺2015-5-17
    ����C++�γ����
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

    //����ͼ���ȫ����Ϣ
    void SetData();
    //����ͼ���������Ϣ����
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

