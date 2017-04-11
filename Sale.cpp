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
    //存储用户想要查找的书籍信息
    string tgbook;
    cout << "请输入您想查找的书籍" << endl;
    getline(cin,tgbook);

    //在书库中查找，模糊查询，即只要有相同的部分，就将这本书显示出来
    int i,j,count = book[0].getNum();//count 用于存储图书数量

    int lentg = tgbook.length(),len = 0;// lentg,len分别存储目标书杰和当前书籍的名称的长度
    string title;
    for(i=0;i<count;i++)
    {
        int flag = 0;
        //存储当前书籍名称
        title = book[i].getBookTitle();
        //存储当前书籍的名称的长度
        len = title.length();
        for(j=0;j<len;j++)
        {
            if(title[j] == tgbook[flag])
                flag++;
        }
        if(lentg == flag)
        {
            cout << "序号： " << i << endl;
            book[i].showData();
            st = true;
        }
    }
    if(st == true)
        cout << "查找完毕" << endl;
    if(st == false)
        cout << "对不起，没有查到有关书籍" << endl;

    int tobuy = 0,num = 0,qty = 0;
    cout << "请输入您要购买的书籍的序号" << endl;
    cin >> tobuy;cin.ignore();
    cout << "请输入您要购买的书籍的数量" << endl;
    cin >> num;cin.ignore();
    while( num > book[tobuy].getQtyOnHand())//如果买家购买的数量大于库存量
    {
        cout << "Sorry，本书库存不足,请重新输入购买数量" << endl;
        cin >> num;
        cin.ignore();
    }
    qty = book[tobuy].getQtyOnHand() - num;//计算图书剩余库存量
    buy[buycount] = book[tobuy];
    buy[buycount].setQtyOnHand( num );//将库存量设置成要购买书的数量
    book[tobuy].setQtyOnHand( qty );
    buycount++;
}

void Sale::getBuy()
{
    int i;
    char ch;
    cout << "前台销售：" << endl;
    cout << "您的购物车如下" << endl;
    cout << "ISBN\t\t" << "书名\t\t" << "数量\t\t" << "单价\t\t" << "总价\t\t" << endl;
    for(i=0;i<buycount;i++)
    {
        cout << buy[i].getIsbn() << "\t" << buy[i].getBookTitle() <<"\t" << buy[i].getQtyOnHand() << "\t\tRMB" << buy[i].getRetail();
        cout << "\t\tRMB" << (buy[i].getRetail()*buy[i].getQtyOnHand()) <<"\t\t" << endl;
    }
    cout << "按任意键返回销售菜单" << endl;
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
    cout << "您好，你所购买书籍总价为：RMB " << total << endl;
    cout << "PS：如果完成付款，请按 1" << endl;
    cin.get(ch);
    cin.ignore();
    if(ch == '1')
        cout << "恭喜，购买成功" <<endl;
    cout << "按任意键返回销售菜单" << endl;
    cin.get(ch);
}

void Sale::getData()//从书库文件中读取图书信息存储在一组BookData对象数组中
{
    int count=0;
    fstream bookFile;
    bookFile.open("Book.dat",ios::in | ios::binary);
    if(bookFile.fail())
    {
        cout << "打开书库文件""Book.dat""出错" << endl;
        exit(0);
    }

    while(!bookFile.eof())//读入数据
    {
        bookFile.read((char *)&book[count],sizeof(book[count]));
        if(bookFile.fail())
            break;
        book[count].setNum(count + 1);//将图书数目保存到BookData对象数组中的静态变量里，方便之后查看书籍数量
        count++;
    }
    bookFile.close();//关闭书库文件
}

void Sale::putData()//将BookData对象数组中的图书信息重新写入书库文件
{
    int count=0,i;
    count = book[0].getNum();//获取图书数量
    fstream bookFile;
    bookFile.open("Book.dat",ios::out | ios::binary);//以写的方式打开书库文件
    if(bookFile.fail())
    {
        cout << "打开书库文件""Book.dat""出错" << endl;
        exit(0);
    }

    for(i=0;i<count;i++)//写入数据
    {
        bookFile.write((char *)&book[i],sizeof(book[i]));
        if(bookFile.fail())//测试用，待删除
            break;
    }

    bookFile.close();
}
