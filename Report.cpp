#include"Report.h"
#include"InputRange.h"
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<iostream>
using namespace std;
void Report::bookList()
{
    int i,count;
    count = book[0].getNum();
    for(i=0;i<count;i++)
    {
        cout << "��ţ� " << i << endl;
        book[i].showData();
    }
    char ch;
    cout << "������������ϲ�˵�" << endl;
    cin.get(ch);
}

void Report::dateList()
{
    int i,j,k,count;
    char time1[11],time2[11];
    count = book[0].getNum();
    TitleInfo temp;
    //ð�ݷ�����
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-1;j++)
        {
            strcpy(time1,book[i].getDateAdded());//�洢����ʱ��
            strcpy(time2,book[j+1].getDateAdded());//�洢����ʱ��
            for(k=0;k<11;k++)
            {
                if(time1[k] > time2[k])
                {
                    temp = book[i];
                    book[i] = book[j+1];
                    book[j+1] = temp;
                    break;
                }
            }
        }
    }

    for(i=0;i<count;i++)
    {
        cout << "��ţ� " << i << endl;
        cout << "������ " << book[i].getBookTitle() << endl;
        cout << "�������ڣ�" << book[i].getDateAdded() << endl;
    }
    char ch;
    cout << "������������ϲ�˵�" << endl;
    cin.get(ch);
}

void Report::quantityList()
{
    int i,j,count;
    count = book[0].getNum();
    TitleInfo temp;
    //ð�ݷ�����
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-1;j++)
        {
            if(book[i].getQtyOnHand() > book[j+1].getQtyOnHand())
            {
                //�˴��õ������������ =
                temp = book[i];
                book[i] = book[j+1];
                book[j+1] = temp;
            }
        }
    }

    //����������ٵ����г����������
    for(i=0;i<count;i++)
    {
        cout << "��ţ� " << i << endl;
        cout << "������ " << book[i].getBookTitle() << endl;
        cout << "�������" << book[i].getQtyOnHand() << endl;
    }
    char ch;
    cout << "������������ϲ�˵�" << endl;
    cin.get(ch);
}

void Report::retailList()
{
    int i,count;
    double total = 0.0;
    count = book[0].getNum();
    for(i=0;i<count;i++)
    {
        cout << "��ţ� " << i << endl;
        cout << "������ " << book[i].getBookTitle() << endl;
        cout << "���ۼ�: " << book[i].getRetail() << endl;
        total += book[i].getRetail();
    }
    cout << "����ͼ�����ۼ��ܺ�Ϊ�� " << total << endl;

    char ch;
    cout << "������������ϲ�˵�" << endl;
    cin.get(ch);
}

void Report::wholesaleList()
{
    int i,count;
    double total = 0.0;
    count = book[0].getNum();
    for(i=0;i<count;i++)
    {
        cout << "��ţ� " << i << endl;
        cout << "������ " << book[i].getBookTitle() << endl;
        cout << "������: " << book[i].getWholesale() << endl;
        total += book[i].getWholesale();
    }
    cout << "����ͼ���������ܺ�Ϊ�� " << total << endl;

    char ch;
    cout << "������������ϲ�˵�" << endl;
    cin.get(ch);
}

void Report::worthList()
{
    int i,j,count;
    count = book[0].getNum();
    TitleInfo temp;
    //ð�ݷ�����
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-1;j++)
        {
            if(book[i].getWorth() > book[j+1].getWorth())
            {
                //�˴��õ������������ =
                temp = book[i];
                book[i] = book[j+1];
                book[j+1] = temp;
            }
        }
    }

    //����������ٵ����г����������
    for(i=0;i<count;i++)
    {
        book[i].calworth();
        cout << "��ţ� " << i << endl;
        cout << "������ " << book[i].getBookTitle() << endl;
        cout << "��ֵ�" << book[i].getWorth() << endl;
    }

    char ch;
    cout << "������������ϲ�˵�" << endl;
    cin.get(ch);
}

void Report::getData()//������ļ��ж�ȡͼ����Ϣ�洢��һ��BookData����������
{
    int count=0;
    fstream bookFile("Book.dat",ios::in | ios::binary);
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

