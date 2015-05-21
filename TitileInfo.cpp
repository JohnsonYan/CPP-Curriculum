#include"TitleInfo.h"
#include<string.h>
#include<iostream>
using namespace std;
int TitleInfo::num;
TitleInfo::TitleInfo()//构造函数
{
    memset(isbn,'\0',sizeof(isbn));
    memset(bookTitle,'\0',sizeof(bookTitle));
    memset(author,'\0',sizeof(author));
    memset(publisher,'\0',sizeof(publisher));
    memset(dateAdded,'\0',sizeof(dateAdded));
    qtyOnHand = 0;
    wholesale = 0.0f;
    retail = 0.0f;
    worth = 0.0f;
    calworth();
}

TitleInfo::TitleInfo(TitleInfo &obj)
{
    strcpy(isbn,obj.isbn);
    strcpy(bookTitle,obj.bookTitle);
    strcpy(author,obj.author);
    strcpy(publisher,obj.publisher);
    strcpy(dateAdded,obj.dateAdded);
    qtyOnHand = obj.qtyOnHand;
    wholesale = obj.wholesale;
    retail = obj.retail;
    worth = obj.worth;
}

TitleInfo TitleInfo:: operator = (const TitleInfo &obj)//重载运算符 =
{
    strcpy(isbn,obj.isbn);
    strcpy(bookTitle,obj.bookTitle);
    strcpy(author,obj.author);
    strcpy(publisher,obj.publisher);
    strcpy(dateAdded,obj.dateAdded);
    qtyOnHand = obj.qtyOnHand;
    wholesale = obj.wholesale;
    retail = obj.retail;
    worth = obj.worth;

    return *this;
}

void TitleInfo::showData()//在屏幕上显示一本书的全部信息
{
    cout << "IBSN  号：" << getIsbn() << endl;
    cout << "书    名：" << getBookTitle() << endl;
    cout << "作    者：" << getAuthor() << endl;
    cout << "出 版 社：" << getPublisher() << endl;
    cout << "进书日期：" << getDateAdded() << endl;
    cout << "库 存 量：" << getQtyOnHand() << endl;
    cout << "批 发 价：" << getWholesale() << endl;
    cout << "零 售 价：" << getRetail() << endl;
}
