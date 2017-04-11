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
        cout <<"|                             南航小型书店管理系统                            |\n" << endl;
        cout <<"|                                  登陆界面：                                 |\n"<< endl;
        cout <<"|                                  A.登陆                                     |\n" << endl;
        cout <<"|                                  B.注册                                     |\n" << endl;
        cout <<"|                                  C.退出                                     |\n" << endl;
        cout <<"|                          PS:请按相应序号进行操作                            |\n" << endl;
        cout <<"+-----------------------------------------------------------------------------+\n" << endl;

        InputRange input('A','C',"输入错误,请输入A~C");
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

bool System::logIn()//登陆
{
    char name[51],password[31];
    getUserData();//从文件中读取加密过后的用户名和密码
    int i,count;
    count = user[0].num_user;
    cout << "用户名： ";
    cin.getline(name,51);
    cout << "密  码： ";
    cin.getline(password,31);

    for(i=0;i<count;i++)
    {
        if(strcmp(user[i].userName,name)  == 0)
        {
            if(strcmp(user[i].userPassword,password) == 0)
            {
                cout << "登陆成功！" << endl;
                return true;
            }
        }
    }
    cout << "Sorry，此用户名不存在或密码错误" << endl;
    char ch;
    cout << "按任意键继续" << endl;
    cin.get(ch);
    return false;
}

void System::Register()
{
    getUserData();//从文件中读取加密过后的用户名和密码

    char name[51],password[31];
    cout << "欢迎使用南航小型书店管理系统，请注册：" << endl;
    cout << "用户名: ";
    cin.getline(name,51);
    cout << "密  码：";
    cin.getline(password,31);

    int i,count;
    count = user[0].num_user;
    for(i=0;i<count;i++)
    {
        if(strcmp(user[i].userName,name)  == 0)
        {
            cout << "对不起，此用户名已存在,请重新输入" << endl;
            cout << "用户名: ";
            cin.getline(name,51);
            cout << "密  码：";
            cin.getline(password,31);
            i = 0;//如果用户名相同，将从新从头检查
        }
    }
    cout << "恭喜，注册成功" << endl;
    //将新注册的用户加入到用户数据中
    user[0].num_user = count + 1;
    strcpy(user[count].userName,name);
    strcpy(user[count].userPassword,password);
    char ch;

    putUserData();

    cout << "按任意键继续" << endl;
    cin.get(ch);
}

void System::Encrypt()//加密密码，将每位向后移动三ASCII码
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
            user[i].userPassword[j] -= 3;//解密密码，将每位向前移动三ASCII码
    }
}

void System::getUserData()//在读取完用户信息后将用户密码解密过来
{
    int count=0;
    fstream userFile;
    userFile.open("UserData.dat",ios::in | ios::binary);
    if(userFile.fail())
    {
        cout << "打开用户信息文件""UserData.dat""出错" << endl;
        exit(0);
    }

    while(!userFile.eof())//读入数据
    {
        userFile.read((char *)&user[count],sizeof(user[count]));
        if(userFile.fail())
            break;
        user[count].num_user = count + 1;//记录用户数量
        count++;
    }
    userFile.close();//关闭书库文件

    Deciphering();//对密码解密
}

void System::putUserData()//将用户信息写入文件，并在写入前对其进行加密
{
    Encrypt();//对密码加密

    int count=0,i;
    count = user[0].num_user;//获取用户数量
    fstream userFile;
    userFile.open("UserData.dat",ios::out | ios::binary);//以写的方式打开书库文件
    if(userFile.fail())
    {
        cout << "打开用户信息文件""UserData.dat""出错" << endl;
        exit(0);
    }

    for(i=0;i<count;i++)//写入数据
    {
        userFile.write((char *)&user[i],sizeof(user[i]));
        if(userFile.fail())
            break;
    }
    userFile.close();
}

void System::mainMenu()//主菜单函数
{
    bool sta = true;
    while(sta)
    {
        system("cls");
        cout <<"+-----------------------------------------------------------------------------+\n" << endl;
        cout <<"|                             南航小型书店管理系统                            |\n" << endl;
        cout <<"|                                  主菜单:                                    |\n"<< endl;
        cout <<"|                               A.前台收银                                    |\n" << endl;
        cout <<"|                               B.书库管理                                    |\n" << endl;
        cout <<"|                               C.查看报表                                    |\n" << endl;
        cout <<"|                               D.退出系统                                    |\n" << endl;
        cout <<"|                          PS:请按相应序号进行操作                            |\n" << endl;
        cout <<"+-----------------------------------------------------------------------------+\n" << endl;

        InputRange input('A','D',"输入错误,请输入A~D");
        switch(input.getInput())
        {
            case 'A':
                saleMenu();//进入前台收银模块
                break;
            case 'B':
                managementMenu();//进入书库管理模块
                break;
            case 'C':
                reportMenu();//进入查看报表模块
                break;
            case 'D':
                sta = false;//退出系统
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
        cout <<"|                             南航小型书店管理系统                            |\n" << endl;
        cout <<"|                                  前台收银：                                 |\n"<< endl;
        cout <<"|                               A.向购物车中增加书籍                          |\n" << endl;
        cout <<"|                               B.查看购物车                                  |\n" << endl;
        cout <<"|                               C.结算                                        |\n" << endl;
        cout <<"|                               D.返回主菜单                                  |\n" << endl;
        cout <<"|                          PS:请按相应序号进行操作                            |\n" << endl;
        cout <<"+-----------------------------------------------------------------------------+\n" << endl;

        InputRange input('A','D',"输入错误，请输入A-D");
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
        cout <<"|                             南航小型书店管理系统                            |\n" << endl;
        cout <<"|                                  书库管理:                                  |\n"<< endl;
        cout <<"|                                A.查找书籍                                   |\n"<< endl;
        cout <<"|                                B.增加书籍                                   |\n"<< endl;
        cout <<"|                                C.修改书籍                                   |\n"<< endl;
        cout <<"|                                D.删除书籍                                   |\n"<< endl;
        cout <<"|                                E.返回主菜单                                 |\n"<< endl;
        cout <<"|                          PS:请按相应序号进行操作                            |\n"<< endl;
        cout <<"+-----------------------------------------------------------------------------+\n" << endl;

        InputRange input('A','E',"输入错误,请输入A~E");
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
        cout <<"|                             南航小型书店管理系统                            |\n" << endl;
        cout <<"|                                  查看报表:                                  |\n"<< endl;
        cout <<"|                                A.书库列表                                   |\n"<< endl;
        cout <<"|                                B.批发价列表                                 |\n"<< endl;
        cout <<"|                                C.零售价列表                                 |\n"<< endl;
        cout <<"|                                D.按书的数量列表                             |\n"<< endl;
        cout <<"|                                E.按书的价值额列表                           |\n"<< endl;
        cout <<"|                                F.按进书日期列表                             |\n"<< endl;
        cout <<"|                                G.返回主菜单                                 |\n"<< endl;
        cout <<"|                          PS:请按相应序号进行操作                            |\n"<< endl;
        cout <<"+-----------------------------------------------------------------------------+\n" << endl;

        InputRange input('A','G',"输入错误,请输入A~G");
        switch(input.getInput())
        {
            case 'A'://书库列表
                report.bookList();
                break;
            case 'B'://批发价列表
                report.wholesaleList();
                break;
            case 'C'://零售价列表
                report.retailList();
                break;
            case 'D'://按书的数量列表
                report.quantityList();
                break;
            case 'E'://按书的价值额列表
                report.worthList();
                break;
            case 'F'://按进书日期列表
                report.dateList();
                break;
            case 'G'://回到主菜单
                status = false;
        }
    }
}

