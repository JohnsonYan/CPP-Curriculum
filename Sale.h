/*
    �Ϻ�С��������ϵͳ
    ���ߣ��ƬB 161420219
    ʱ�䣺2015-5-17
    ����C++�γ����
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
    void getData();//������ļ������ļ��е�ͼ����Ϣ��ȡ���ڴ���
    void putData();//��ϵͳ����ǰ����ͼ����Ϣд������ļ���
};
#endif // SALE_H
