/*
    南航小型书店管理系统
    作者：闫珺 161420219
    时间：2015-5-17
    用于C++课程设计
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
    User user[30];//可存储三十个用户的User对象
    void Encrypt();//为密码加密
    void Deciphering();//为密码解密
public:
    void logMenu();
    bool logIn();//登陆
    void Register();//注册
    void getUserData();//从文件中读取用户名和加密过后的密码
    void putUserData();//将用户名和加密过后的密码写入文件

    void mainMenu();//主菜单
    void saleMenu();//收银模块菜单
    void managementMenu();//书库管理模块菜单
    void reportMenu();//报表模块菜单
};
#endif // SYSTEM_H
