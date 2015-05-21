/*
    南航小型书店管理系统
    作者：闫珺 161420219
    时间：2015-5-17
    用于C++课程设计
*/
#ifndef USER_H
#define USER_H
class User
{
public:
    User();//构造函数
    static int num_user;
    char userName[51];//用户名
    char userPassword[31];//密码
};
#endif // USER_H
