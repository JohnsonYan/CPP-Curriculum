#include"System.h"
#include"InputRange.h"
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<iostream>
using namespace std;

void System::logMenu()
{
    bool s = true;
    while(s)
    {
        system("cls");
        cout <<"+-----------------------------------------------------------------------------+\n" << endl;
        cout <<"|                             �Ϻ�С��������ϵͳ                            |\n" << endl;
        cout <<"|                                  ��½���棺                                 |\n"<< endl;
        cout <<"|                                  A.��½                                     |\n" << endl;
        cout <<"|                                  B.ע��                                     |\n" << endl;
        cout <<"|                                  C.�˳�                                     |\n" << endl;
        cout <<"|                          PS:�밴��Ӧ��Ž��в���                            |\n" << endl;
        cout <<"+-----------------------------------------------------------------------------+\n" << endl;

        InputRange input('A','C',"�������,������A~C");
        switch(input.getInput())
        {
        case 'A':
            if(logIn())
                s = false;
            break;
        case 'B':
            Register();
            break;
        case 'C':
            exit(0);
        }
    }
}

bool System::logIn()//��½
{
    char name[51],password[31];
    getUserData();//���ļ��ж�ȡ���ܹ�����û���������
    int i,count;
    count = user[0].num_user;
    cout << "�û����� ";
    cin.getline(name,51);
    cout << "��  �룺 ";
    cin.getline(password,31);

    for(i=0;i<count;i++)
    {
        if(strcmp(user[i].userName,name)  == 0)
        {
            if(strcmp(user[i].userPassword,password) == 0)
            {
                cout << "��½�ɹ���" << endl;
                return true;
            }
        }
    }
    cout << "Sorry�����û��������ڻ��������" << endl;
    char ch;
    cout << "�����������" << endl;
    cin.get(ch);
    return false;
}

void System::Register()
{
    getUserData();//���ļ��ж�ȡ���ܹ�����û���������

    char name[51],password[31];
    cout << "��ӭʹ���Ϻ�С��������ϵͳ����ע�᣺" << endl;
    cout << "�û���: ";
    cin.getline(name,51);
    cout << "��  �룺";
    cin.getline(password,31);

    int i,count;
    count = user[0].num_user;
    for(i=0;i<count;i++)
    {
        if(strcmp(user[i].userName,name)  == 0)
        {
            cout << "�Բ��𣬴��û����Ѵ���,����������" << endl;
            cout << "�û���: ";
            cin.getline(name,51);
            cout << "��  �룺";
            cin.getline(password,31);
            i = 0;//����û�����ͬ�������´�ͷ���
        }
    }
    cout << "��ϲ��ע��ɹ�" << endl;
    //����ע����û����뵽�û�������
    user[0].num_user = count + 1;
    strcpy(user[count].userName,name);
    strcpy(user[count].userPassword,password);
    char ch;

    putUserData();

    cout << "�����������" << endl;
    cin.get(ch);
}

void System::Encrypt()//�������룬��ÿλ����ƶ���ASCII��
{
    int i,j,n,count;
    count = user[0].num_user;
    for(i=0;i<count;i++)
    {
        n = strlen(user[i].userPassword);
        for(j=0;j<n;j++)
            user[i].userPassword[j] += 3;
    }
}

void System::Deciphering()
{
    int i,j,n,count;
    count = user[0].num_user;
    for(i=0;i<count;i++)
    {
        n = strlen(user[i].userPassword);
        for(j=0;j<n;j++)
            user[i].userPassword[j] -= 3;//�������룬��ÿλ��ǰ�ƶ���ASCII��
    }
}

void System::getUserData()//�ڶ�ȡ���û���Ϣ���û�������ܹ���
{
    int count=0;
    fstream userFile;
    userFile.open("UserData.dat",ios::in | ios::binary);
    if(userFile.fail())
    {
        cout << "���û���Ϣ�ļ�""UserData.dat""����" << endl;
        exit(0);
    }

    while(!userFile.eof())//��������
    {
        userFile.read((char *)&user[count],sizeof(user[count]));
        if(userFile.fail())
            break;
        user[count].num_user = count + 1;//��¼�û�����
        count++;
    }
    userFile.close();//�ر�����ļ�

    Deciphering();//���������
}

void System::putUserData()//���û���Ϣд���ļ�������д��ǰ������м���
{
    Encrypt();//���������

    int count=0,i;
    count = user[0].num_user;//��ȡ�û�����
    fstream userFile;
    userFile.open("UserData.dat",ios::out | ios::binary);//��д�ķ�ʽ������ļ�
    if(userFile.fail())
    {
        cout << "���û���Ϣ�ļ�""UserData.dat""����" << endl;
        exit(0);
    }

    for(i=0;i<count;i++)//д������
    {
        userFile.write((char *)&user[i],sizeof(user[i]));
        if(userFile.fail())
            break;
    }
    userFile.close();
}

void System::mainMenu()//���˵�����
{
    bool sta = true;
    while(sta)
    {
        system("cls");
        cout <<"+-----------------------------------------------------------------------------+\n" << endl;
        cout <<"|                             �Ϻ�С��������ϵͳ                            |\n" << endl;
        cout <<"|                                  ���˵�:                                    |\n"<< endl;
        cout <<"|                               A.ǰ̨����                                    |\n" << endl;
        cout <<"|                               B.������                                    |\n" << endl;
        cout <<"|                               C.�鿴����                                    |\n" << endl;
        cout <<"|                               D.�˳�ϵͳ                                    |\n" << endl;
        cout <<"|                          PS:�밴��Ӧ��Ž��в���                            |\n" << endl;
        cout <<"+-----------------------------------------------------------------------------+\n" << endl;

        InputRange input('A','D',"�������,������A~D");
        switch(input.getInput())
        {
            case 'A':
                saleMenu();//����ǰ̨����ģ��
                break;
            case 'B':
                managementMenu();//����������ģ��
                break;
            case 'C':
                reportMenu();//����鿴����ģ��
                break;
            case 'D':
                sta = false;//�˳�ϵͳ
        }
    }
}

void System::saleMenu()
{
    sale.getData();
    bool status = true;
    while(status)
    {
        system("cls");
        cout <<"+-----------------------------------------------------------------------------+\n" << endl;
        cout <<"|                             �Ϻ�С��������ϵͳ                            |\n" << endl;
        cout <<"|                                  ǰ̨������                                 |\n"<< endl;
        cout <<"|                               A.���ﳵ�������鼮                          |\n" << endl;
        cout <<"|                               B.�鿴���ﳵ                                  |\n" << endl;
        cout <<"|                               C.����                                        |\n" << endl;
        cout <<"|                               D.�������˵�                                  |\n" << endl;
        cout <<"|                          PS:�밴��Ӧ��Ž��в���                            |\n" << endl;
        cout <<"+-----------------------------------------------------------------------------+\n" << endl;

        InputRange input('A','D',"�������������A-D");
        switch(input.getInput())
        {
        case 'A':
            sale.addBook();
            break;
        case 'B':
            sale.getBuy();
            break;
        case 'C':
            sale.getCash();
            break;
        case 'D':
            sale.putData();
            status = false;
        }
    }
}

void System::managementMenu()
{
    manager.getData();
    bool status = true;
    while(status)
    {
        system("cls");
        cout <<"+-----------------------------------------------------------------------------+\n" << endl;
        cout <<"|                             �Ϻ�С��������ϵͳ                            |\n" << endl;
        cout <<"|                                  ������:                                  |\n"<< endl;
        cout <<"|                                A.�����鼮                                   |\n"<< endl;
        cout <<"|                                B.�����鼮                                   |\n"<< endl;
        cout <<"|                                C.�޸��鼮                                   |\n"<< endl;
        cout <<"|                                D.ɾ���鼮                                   |\n"<< endl;
        cout <<"|                                E.�������˵�                                 |\n"<< endl;
        cout <<"|                          PS:�밴��Ӧ��Ž��в���                            |\n"<< endl;
        cout <<"+-----------------------------------------------------------------------------+\n" << endl;

        InputRange input('A','E',"�������,������A~E");
        switch(input.getInput())
        {
            case 'A':
                manager.findBook();
                break;
            case 'B':
                manager.addBook();
                break;
            case 'C':
                manager.editBook();
                break;
            case 'D':
                manager.deleteBook();
                break;
            case 'E':
                manager.putData();
                status = false;
        }
    }
}

void System::reportMenu()
{
    report.getData();
    bool status = true;
    while(status)
    {
        system("cls");
        cout <<"+-----------------------------------------------------------------------------+\n" << endl;
        cout <<"|                             �Ϻ�С��������ϵͳ                            |\n" << endl;
        cout <<"|                                  �鿴����:                                  |\n"<< endl;
        cout <<"|                                A.����б�                                   |\n"<< endl;
        cout <<"|                                B.�������б�                                 |\n"<< endl;
        cout <<"|                                C.���ۼ��б�                                 |\n"<< endl;
        cout <<"|                                D.����������б�                             |\n"<< endl;
        cout <<"|                                E.����ļ�ֵ���б�                           |\n"<< endl;
        cout <<"|                                F.�����������б�                             |\n"<< endl;
        cout <<"|                                G.�������˵�                                 |\n"<< endl;
        cout <<"|                          PS:�밴��Ӧ��Ž��в���                            |\n"<< endl;
        cout <<"+-----------------------------------------------------------------------------+\n" << endl;

        InputRange input('A','G',"�������,������A~G");
        switch(input.getInput())
        {
            case 'A'://����б�
                report.bookList();
                break;
            case 'B'://�������б�
                report.wholesaleList();
                break;
            case 'C'://���ۼ��б�
                report.retailList();
                break;
            case 'D'://����������б�
                report.quantityList();
                break;
            case 'E'://����ļ�ֵ���б�
                report.worthList();
                break;
            case 'F'://�����������б�
                report.dateList();
                break;
            case 'G'://�ص����˵�
                status = false;
        }
    }
}

