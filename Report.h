/*
    南航小型书店管理系统
    作者：闫珺 161420219
    时间：2015-5-17
    用于C++课程设计
*/
#ifndef REPROT_H
#define REPORT_H
#include"BookData.h"
class Report
{
private:
    TitleInfo book[1000];
public:
    void bookList();//书库列表
    void wholesaleList();//批发价列表
    void retailList();//零售价列表
    void quantityList();//按书的数量列表
    void worthList();//按书的价值额列表
    void dateList();//按进书日期列表
    void getData();//打开书库文件并将文件中的图书信息读取到内存中
};
#endif // REPROT_H
