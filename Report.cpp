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
        cout << "序号： " << i << endl;
        book[i].showData();
    }
    char ch;
    cout << "按任意键返回上层菜单" << endl;
    cin.get(ch);
}

void Report::dateList()
{
    int i,j,k,count;
    char time1[11],time2[11];
    count = book[0].getNum();
    TitleInfo temp;
    //冒泡法排序
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-1;j++)
        {
            strcpy(time1,book[i].getDateAdded());//存储进书时间
            strcpy(time2,book[j+1].getDateAdded());//存储进书时间
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
        cout << "序号： " << i << endl;
        cout << "书名： " << book[i].getBookTitle() << endl;
        cout << "进书日期：" << book[i].getDateAdded() << endl;
    }
    char ch;
    cout << "按任意键返回上层菜单" << endl;
    cin.get(ch);
}

void Report::quantityList()
{
    int i,j,count;
    count = book[0].getNum();
    TitleInfo temp;
    //冒泡法排序
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-1;j++)
        {
            if(book[i].getQtyOnHand() > book[j+1].getQtyOnHand())
            {
                //此处用到了重载运算符 =
                temp = book[i];
                book[i] = book[j+1];
                book[j+1] = temp;
            }
        }
    }

    //按库存量从少到多列出库存量报表
    for(i=0;i<count;i++)
    {
        cout << "序号： " << i << endl;
        cout << "书名： " << book[i].getBookTitle() << endl;
        cout << "库存量：" << book[i].getQtyOnHand() << endl;
    }
    char ch;
    cout << "按任意键返回上层菜单" << endl;
    cin.get(ch);
}

void Report::retailList()
{
    int i,count;
    double total = 0.0;
    count = book[0].getNum();
    for(i=0;i<count;i++)
    {
        cout << "序号： " << i << endl;
        cout << "书名： " << book[i].getBookTitle() << endl;
        cout << "零售价: " << book[i].getRetail() << endl;
        total += book[i].getRetail();
    }
    cout << "所有图书零售价总和为： " << total << endl;

    char ch;
    cout << "按任意键返回上层菜单" << endl;
    cin.get(ch);
}

void Report::wholesaleList()
{
    int i,count;
    double total = 0.0;
    count = book[0].getNum();
    for(i=0;i<count;i++)
    {
        cout << "序号： " << i << endl;
        cout << "书名： " << book[i].getBookTitle() << endl;
        cout << "批发价: " << book[i].getWholesale() << endl;
        total += book[i].getWholesale();
    }
    cout << "所有图书批发价总和为： " << total << endl;

    char ch;
    cout << "按任意键返回上层菜单" << endl;
    cin.get(ch);
}

void Report::worthList()
{
    int i,j,count;
    count = book[0].getNum();
    TitleInfo temp;
    //冒泡法排序
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-1;j++)
        {
            if(book[i].getWorth() > book[j+1].getWorth())
            {
                //此处用到了重载运算符 =
                temp = book[i];
                book[i] = book[j+1];
                book[j+1] = temp;
            }
        }
    }

    //按库存量从少到多列出库存量报表
    for(i=0;i<count;i++)
    {
        book[i].calworth();
        cout << "序号： " << i << endl;
        cout << "书名： " << book[i].getBookTitle() << endl;
        cout << "价值额：" << book[i].getWorth() << endl;
    }

    char ch;
    cout << "按任意键返回上层菜单" << endl;
    cin.get(ch);
}

void Report::getData()//从书库文件中读取图书信息存储在一组BookData对象数组中
{
    int count=0;
    fstream bookFile("Book.dat",ios::in | ios::binary);
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

