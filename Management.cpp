#include"Management.h"
#include"InputRange.h"
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<iostream>
using namespace std;


void Management::findBook()
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

    char ch;
    cout << "�����������" << endl;
    cin.get(ch);
}

void Management::addBook()
{
    int add = 0;
    add = book[0].getNum();//��ȡͼ������
    book[add].SetData();//������ͼ����Ϣ�����⣬add��ͼ����������book[add]ǡ��Ϊ�µ�ͼ��洢���±�
    book[add].setNum(add + 1);//��ͼ��������һ
    cout << "�鼮��ӳɹ�" << endl;

    char ch;
    cout << "�����������" << endl;
    cin.get(ch);
}

void Management::editBook()
{
    int edit;
    InputRange input('A','J',"�������������A-J");
    //���û�������������Ѱ�ң�֮��ͨ������ͼ����Ŷ�ͼ������޸�
    findBook();
    cout << "���ã������������޸ĵ��鼮����ţ�" << endl;
    cin >> edit;cin.ignore();
    book[edit].showData();
    cout << "������A-J�Ա�����Ϣ�����޸ģ�" << endl;
    cout << "A.�޸�ȫ����Ϣ" << endl;
    cout << "B.�޸�ISBN" << endl;
    cout << "C.�޸�����" << endl;
    cout << "D.�޸�����" << endl;
    cout << "E.�޸ĳ�����" << endl;
    cout << "F.�޸Ľ���ʱ��" << endl;
    cout << "G.�޸Ŀ��" << endl;
    cout << "H.�޸�������" << endl;
    cout << "I.�޸����ۼ�" << endl;
    cout << "J.ȡ���޸�" << endl;
    switch(input.getInput())
    {
        case 'A':
            book[edit].SetData();
            cout << "�޸ĳɹ���" << endl;
            break;
        case 'B':
            book[edit].setIsbn();
            cout << "�޸ĳɹ���" << endl;
            break;
        case 'C':
            book[edit].setBookTitle();
            cout << "�޸ĳɹ���" << endl;
            break;
        case 'D':
            book[edit].setAuthor();
            cout << "�޸ĳɹ���" << endl;
            break;
        case 'E':
            book[edit].setPublisher();
            cout << "�޸ĳɹ���" << endl;
            break;
        case 'F':
            book[edit].setDateAdded();
            cout << "�޸ĳɹ���" << endl;
            break;
        case 'G':
            book[edit].setQtyOnHand();
            cout << "�޸ĳɹ���" << endl;
            break;
        case 'H':
            book[edit].setWholesale();
            cout << "�޸ĳɹ���" << endl;
            break;
        case 'I':
            book[edit].setRetail();
            cout << "�޸ĳɹ���" << endl;
            break;
        case 'J':
            cout << "��ȡ���ò���" << endl;
    }

    char ch;
    cout << "�����������" << endl;
    cin.get(ch);
}

void Management::deleteBook()
{
    int i,count = 0,del = 0;
    count = book[0].getNum();
    InputRange input1('A','B',"�������������A-B");
    InputRange input2('A','B',"�������������A-B");
    cout << "A.�����鼮����" << endl;
    cout << "B.�г�����б�" << endl;
    switch(input2.getInput())
    {
    case 'A':
        findBook();
        break;
    case 'B':
        int i,count;
        count = book[0].getNum();
        for(i=0;i<count;i++)
        {
            cout << "��ţ� " << i << endl;
            book[i].showData();
        }
    }

    cout << "����������ɾ�����鼮�����" << endl;
    cin >> del;cin.ignore();
    book[del].showData();
    cout << "ȷ��ɾ�����밴 A " << endl;
    cout << "ȡ��ɾ�����밴 B " << endl;
    switch(input1.getInput())
    {
        case 'A':
            if(del == count)//���Ҫɾ�����������һ���������������Сһ������ʵ����ɾ������
            {
                book[del].setNum(count - 1);
            }
            if(del != count)//���򣬾ͽ�Ҫɾ���鼮�����ȫ����ǰ�ƶ�һλ��Ҳ����˵������Ҫɾ�����鼮
            {
                for(i=del;i<count;i++)
                {
                    book[i] = book[i+1];
                }
                book[del].setNum(count - 1);
            }
            cout << "ɾ���ɹ�" << endl;
            break;
        case 'B':
            cout << "��ȡ���ò���" << endl;
    }

    char ch;
    cout << "�����������" << endl;
    cin.get(ch);
}

void Management::getData()//������ļ��ж�ȡͼ����Ϣ�洢��һ��BookData����������
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

void Management::putData()//��BookData���������е�ͼ����Ϣ����д������ļ�
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

