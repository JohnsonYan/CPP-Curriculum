#include"BookData.h"
#include<iostream>
using namespace std;
#include<string.h>

BookData::BookData()//构造函数
{
    memset(isbn,'\0',sizeof(isbn));
    memset(bookTitle,'\0',sizeof(bookTitle));
    memset(author,'\0',sizeof(author));
    memset(publisher,'\0',sizeof(publisher));
    memset(dateAdded,'\0',sizeof(dateAdded));
    qtyOnHand = 0;
    wholesale = 0.0f;
    retail = 0.0f;
}

BookData::BookData(BookData &obj)
{
    strcpy(isbn,obj.isbn);
    strcpy(bookTitle,obj.bookTitle);
    strcpy(author,obj.author);
    strcpy(publisher,obj.publisher);
    strcpy(dateAdded,obj.dateAdded);
    qtyOnHand = obj.qtyOnHand;
    wholesale = obj.wholesale;
    retail = obj.retail;
}



void BookData::setIsbn()//设置图书IBSN
{
    cout << "请输入图书的IBSN：" <<endl;
    cin.getline(isbn,14);
}

void BookData::setBookTitle()//设置书名
{
    cout << "请输入图书的名称：" <<endl;
    cin.getline(bookTitle,51);
}

void BookData::setAuthor()//设置图书作者
{
    cout << "请输入图书的作者：" <<endl;
    cin.getline(author,31);
}

void BookData::setPublisher()//设置图书出版社
{
    cout << "请输入图书的出版社：" <<endl;
    cin.getline(publisher,31);
}

void BookData::setDateAdded()//设置进书日期
{
    cout << "请输入图书的进书日期：" <<endl;
    cin.getline(dateAdded,11);
}

void BookData::setQtyOnHand()//设置图书库存量
{
    cout << "请输入图书的库存量：" <<endl;
    cin >> qtyOnHand;cin.ignore();
}

void BookData::setQtyOnHand(int n)
{
    qtyOnHand = n;
}

void BookData::setWholesale()//设置图书批发价
{
    cout << "请输入图书的批发价：" <<endl;
    cin >> wholesale;cin.ignore();
}

void BookData::setRetail()//设置图书零售价
{
    cout << "请输入图书的零售价：" <<endl;
    cin >> retail;cin.ignore();
}

void BookData::SetData()//设置图书全部信息的函数
{
    setIsbn();
    setBookTitle();
    setAuthor();
    setPublisher();
    setDateAdded();
    setQtyOnHand();
    setWholesale();
    setRetail();
}

