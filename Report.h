/*
    �Ϻ�С��������ϵͳ
    ���ߣ��ƬB 161420219
    ʱ�䣺2015-5-17
    ����C++�γ����
*/
#ifndef REPROT_H
#define REPORT_H
#include"BookData.h"
class Report
{
private:
    TitleInfo book[1000];
public:
    void bookList();//����б�
    void wholesaleList();//�������б�
    void retailList();//���ۼ��б�
    void quantityList();//����������б�
    void worthList();//����ļ�ֵ���б�
    void dateList();//�����������б�
    void getData();//������ļ������ļ��е�ͼ����Ϣ��ȡ���ڴ���
};
#endif // REPROT_H
