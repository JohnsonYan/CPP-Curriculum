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

    char ch;
    cout << "按任意键继续" << endl;
    cin.get(ch);
}

void Management::addBook()
{
    int add = 0;
    add = book[0].getNum();//获取图书数量
    book[add].SetData();//设置新图书信息，另外，add是图书数量，而book[add]恰好为新的图书存储的下标
    book[add].setNum(add + 1);//将图书数量加一
    cout << "书籍添加成功" << endl;

    char ch;
    cout << "按任意键继续" << endl;
    cin.get(ch);
}

void Management::editBook()
{
    int edit;
    InputRange input('A','J',"输入错误，请输入A-J");
    //让用户输入书名进行寻找，之后通过输入图书序号对图书进行修改
    findBook();
    cout << "您好，请输入您想修改的书籍的序号：" << endl;
    cin >> edit;cin.ignore();
    book[edit].showData();
    cout << "请输入A-J对本书信息进行修改：" << endl;
    cout << "A.修改全部信息" << endl;
    cout << "B.修改ISBN" << endl;
    cout << "C.修改书名" << endl;
    cout << "D.修改作者" << endl;
    cout << "E.修改出版社" << endl;
    cout << "F.修改进书时间" << endl;
    cout << "G.修改库存" << endl;
    cout << "H.修改批发价" << endl;
    cout << "I.修改零售价" << endl;
    cout << "J.取消修改" << endl;
    switch(input.getInput())
    {
        case 'A':
            book[edit].SetData();
            cout << "修改成功！" << endl;
            break;
        case 'B':
            book[edit].setIsbn();
            cout << "修改成功！" << endl;
            break;
        case 'C':
            book[edit].setBookTitle();
            cout << "修改成功！" << endl;
            break;
        case 'D':
            book[edit].setAuthor();
            cout << "修改成功！" << endl;
            break;
        case 'E':
            book[edit].setPublisher();
            cout << "修改成功！" << endl;
            break;
        case 'F':
            book[edit].setDateAdded();
            cout << "修改成功！" << endl;
            break;
        case 'G':
            book[edit].setQtyOnHand();
            cout << "修改成功！" << endl;
            break;
        case 'H':
            book[edit].setWholesale();
            cout << "修改成功！" << endl;
            break;
        case 'I':
            book[edit].setRetail();
            cout << "修改成功！" << endl;
            break;
        case 'J':
            cout << "已取消该操作" << endl;
    }

    char ch;
    cout << "按任意键继续" << endl;
    cin.get(ch);
}

void Management::deleteBook()
{
    int i,count = 0,del = 0;
    count = book[0].getNum();
    InputRange input1('A','B',"输入错误，请输入A-B");
    InputRange input2('A','B',"输入错误，请输入A-B");
    cout << "A.查找书籍名称" << endl;
    cout << "B.列出书库列表" << endl;
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
            cout << "序号： " << i << endl;
            book[i].showData();
        }
    }

    cout << "请输入您想删除的书籍的序号" << endl;
    cin >> del;cin.ignore();
    book[del].showData();
    cout << "确认删除，请按 A " << endl;
    cout << "取消删除，请按 B " << endl;
    switch(input1.getInput())
    {
        case 'A':
            if(del == count)//如果要删除的书是最后一本，将书的数量减小一本，就实现了删除操作
            {
                book[del].setNum(count - 1);
            }
            if(del != count)//否则，就将要删除书籍后面的全部向前移动一位，也就是说覆盖了要删除的书籍
            {
                for(i=del;i<count;i++)
                {
                    book[i] = book[i+1];
                }
                book[del].setNum(count - 1);
            }
            cout << "删除成功" << endl;
            break;
        case 'B':
            cout << "已取消该操作" << endl;
    }

    char ch;
    cout << "按任意键继续" << endl;
    cin.get(ch);
}

void Management::getData()//从书库文件中读取图书信息存储在一组BookData对象数组中
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

void Management::putData()//将BookData对象数组中的图书信息重新写入书库文件
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

