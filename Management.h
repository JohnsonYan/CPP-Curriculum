/*
    �Ϻ�С��������ϵͳ
    ���ߣ��ƬB 161420219
    ʱ�䣺2015-5-17
    ����C++�γ����
*/
#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include"BookData.h"

class Management
{
public:
    BookData book[1000];
    void findBook();//Ѱ��ĳ��ͼ����Ϣ
    void addBook();//����ͼ��
    void editBook();//�޸�ͼ����Ϣ
    void deleteBook();//ɾ��ͼ��
    void getData();//������ļ������ļ��е�ͼ����Ϣ��ȡ���ڴ���
    void putData();//��ϵͳ����ǰ����ͼ����Ϣд������ļ���
};
#endif // MANAGEMENT_H
