/*
    �Ϻ�С��������ϵͳ
    ���ߣ��ƬB 161420219
    ʱ�䣺2015-5-17
    ����C++�γ����
*/
#ifndef SYSTEM_H
#define SYSTEM_H
#include"BookData.h"
#include"Management.h"
#include"Report.h"
#include"Sale.h"
#include"User.h"
class System
{
private:
    Management manager;
    Report report;
    Sale sale;
    User user[30];//�ɴ洢��ʮ���û���User����
    void Encrypt();//Ϊ�������
    void Deciphering();//Ϊ�������
public:
    void logMenu();
    bool logIn();//��½
    void Register();//ע��
    void getUserData();//���ļ��ж�ȡ�û����ͼ��ܹ��������
    void putUserData();//���û����ͼ��ܹ��������д���ļ�

    void mainMenu();//���˵�
    void saleMenu();//����ģ��˵�
    void managementMenu();//������ģ��˵�
    void reportMenu();//����ģ��˵�
};
#endif // SYSTEM_H
