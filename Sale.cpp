#include"Sale.h"
#include"InputRange.h"
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<iostream>
using namespace std;

Sale::Sale()
{
    buycount = 0;
    total = 0;
    getData();
}

void Sale::addBook()
{
    bool st = false;
    //�洢�û���Ҫ���ҵ��鼮��Ϣ
    string tgbook;
    cout << "������������ҵ��鼮" << endl;
    getline(cin,tgbook);

    //������в��ң�ģ����ѯ����ֻҪ����ͬ�Ĳ��֣��ͽ��Ȿ����ʾ����
    int i,j,count = book[0].getNum();//count ���ڴ洢ͼ������

    int lentg = tgbook.length(),len = 0;// lentg,len�ֱ�洢Ŀ����ܺ͵�ǰ�鼮�����Ƶĳ���
    string title;
    for(i=0;i<count;i++)
    {
        int flag = 0;
        //�洢��ǰ�鼮����
        title = book[i].getBookTitle();
        //�洢��ǰ�鼮�����Ƶĳ���
        len = title.length();
        for(j=0;j<len;j++)
        {
            if(title[j] == tgbook[flag])
                flag++;
        }
        if(lentg == flag)
        {
            cout << "��ţ� " << i << endl;
            book[i].showData();
            st = true;
        }
    }
    if(st == true)
        cout << "�������" << endl;
    if(st == false)
        cout << "�Բ���û�в鵽�й��鼮" << endl;

    int tobuy = 0,num = 0,qty = 0;
    cout << "��������Ҫ������鼮�����" << endl;
    cin >> tobuy;cin.ignore();
    cout << "��������Ҫ������鼮������" << endl;
    cin >> num;cin.ignore();
    while( num > book[tobuy].getQtyOnHand())//�����ҹ�����������ڿ����
    {
        cout << "Sorry�������治��,���������빺������" << endl;
        cin >> num;
        cin.ignore();
    }
    qty = book[tobuy].getQtyOnHand() - num;//����ͼ��ʣ������
    buy[buycount] = book[tobuy];
    buy[buycount].setQtyOnHand( num );//����������ó�Ҫ�����������
    book[tobuy].setQtyOnHand( qty );
    buycount++;
}

void Sale::getBuy()
{
    int i;
    char ch;
    cout << "ǰ̨���ۣ�" << endl;
    cout << "���Ĺ��ﳵ����" << endl;
    cout << "ISBN\t\t" << "����\t\t" << "����\t\t" << "����\t\t" << "�ܼ�\t\t" << endl;
    for(i=0;i<buycount;i++)
    {
        cout << buy[i].getIsbn() << "\t" << buy[i].getBookTitle() <<"\t" << buy[i].getQtyOnHand() << "\t\tRMB" << buy[i].getRetail();
        cout << "\t\tRMB" << (buy[i].getRetail()*buy[i].getQtyOnHand()) <<"\t\t" << endl;
    }
    cout << "��������������۲˵�" << endl;
    cin.get(ch);
}

void Sale::getCash()
{
    char ch;
    int i,num = 0;
    double price = 0.0;
    for(i=0;i<buycount;i++)
    {
        num = buy[i].getQtyOnHand();
        price = buy[i].getRetail();
        total += (num*price);
    }
    cout << "���ã����������鼮�ܼ�Ϊ��RMB " << total << endl;
    cout << "PS�������ɸ���밴 1" << endl;
    cin.get(ch);
    cin.ignore();
    if(ch == '1')
        cout << "��ϲ������ɹ�" <<endl;
    cout << "��������������۲˵�" << endl;
    cin.get(ch);
}

void Sale::getData()//������ļ��ж�ȡͼ����Ϣ�洢��һ��BookData����������
{
    int count=0;
    fstream bookFile;
    bookFile.open("Book.dat",ios::in | ios::binary);
    if(bookFile.fail())
    {
        cout << "������ļ�""Book.dat""����" << endl;
        exit(0);
    }

    while(!bookFile.eof())//��������
    {
        bookFile.read((char *)&book[count],sizeof(book[count]));
        if(bookFile.fail())
            break;
        book[count].setNum(count + 1);//��ͼ����Ŀ���浽BookData���������еľ�̬���������֮��鿴�鼮����
        count++;
    }
    bookFile.close();//�ر�����ļ�
}

void Sale::putData()//��BookData���������е�ͼ����Ϣ����д������ļ�
{
    int count=0,i;
    count = book[0].getNum();//��ȡͼ������
    fstream bookFile;
    bookFile.open("Book.dat",ios::out | ios::binary);//��д�ķ�ʽ������ļ�
    if(bookFile.fail())
    {
        cout << "������ļ�""Book.dat""����" << endl;
        exit(0);
    }

    for(i=0;i<count;i++)//д������
    {
        bookFile.write((char *)&book[i],sizeof(book[i]));
        if(bookFile.fail())//�����ã���ɾ��
            break;
    }

    bookFile.close();
}
