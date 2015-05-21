#include"TitleInfo.h"
#include<string.h>
#include<iostream>
using namespace std;
int TitleInfo::num;
TitleInfo::TitleInfo()//���캯��
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

TitleInfo TitleInfo:: operator = (const TitleInfo &obj)//��������� =
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

void TitleInfo::showData()//����Ļ����ʾһ�����ȫ����Ϣ
{
    cout << "IBSN  �ţ�" << getIsbn() << endl;
    cout << "��    ����" << getBookTitle() << endl;
    cout << "��    �ߣ�" << getAuthor() << endl;
    cout << "�� �� �磺" << getPublisher() << endl;
    cout << "�������ڣ�" << getDateAdded() << endl;
    cout << "�� �� ����" << getQtyOnHand() << endl;
    cout << "�� �� �ۣ�" << getWholesale() << endl;
    cout << "�� �� �ۣ�" << getRetail() << endl;
}
