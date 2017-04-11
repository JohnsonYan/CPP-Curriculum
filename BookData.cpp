#include"BookData.h"
#include<iostream>
using namespace std;
#include<string.h>

BookData::BookData()//���캯��
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



void BookData::setIsbn()//����ͼ��IBSN
{
    cout << "������ͼ���IBSN��" <<endl;
    cin.getline(isbn,14);
}

void BookData::setBookTitle()//��������
{
    cout << "������ͼ������ƣ�" <<endl;
    cin.getline(bookTitle,51);
}

void BookData::setAuthor()//����ͼ������
{
    cout << "������ͼ������ߣ�" <<endl;
    cin.getline(author,31);
}

void BookData::setPublisher()//����ͼ�������
{
    cout << "������ͼ��ĳ����磺" <<endl;
    cin.getline(publisher,31);
}

void BookData::setDateAdded()//���ý�������
{
    cout << "������ͼ��Ľ������ڣ�" <<endl;
    cin.getline(dateAdded,11);
}

void BookData::setQtyOnHand()//����ͼ������
{
    cout << "������ͼ��Ŀ������" <<endl;
    cin >> qtyOnHand;cin.ignore();
}

void BookData::setQtyOnHand(int n)
{
    qtyOnHand = n;
}

void BookData::setWholesale()//����ͼ��������
{
    cout << "������ͼ��������ۣ�" <<endl;
    cin >> wholesale;cin.ignore();
}

void BookData::setRetail()//����ͼ�����ۼ�
{
    cout << "������ͼ������ۼۣ�" <<endl;
    cin >> retail;cin.ignore();
}

void BookData::SetData()//����ͼ��ȫ����Ϣ�ĺ���
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

