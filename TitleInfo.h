/*
    南航小型书店管理系统
    作者：闫珺 161420219
    时间：2015-5-17
    用于C++课程设计
*/
#ifndef TITLEINFO_H
#define TITLEINFP_H
class TitleInfo
{
protected:
    static int num;//该静态变量为TitleInfo类共有，用于记录TitileInfo数组中书籍数目
    char isbn[14];//ISBN号
    char bookTitle[51];//书名
    char author[31];//作者
    char publisher[31];//出版社
    char dateAdded[11];//进书时间
    int qtyOnHand;//库存
    double wholesale;//批发价
    double retail;//零售价
    double worth;//批发价总额，也就是书籍价值额
public:
    TitleInfo();
    TitleInfo(TitleInfo &);

    //重载赋值运算符
    TitleInfo operator = (const TitleInfo &obj);
    void setNum(int x) {num = x;}//设置静态变量num的值
    int getNum() {return num;}//返回静态变量num的值
    //获取图书信息
    char* getIsbn() {return isbn;}
    char* getBookTitle() {return bookTitle;}
    char* getAuthor() {return author;}
    char* getPublisher() {return publisher;}
    char* getDateAdded() {return dateAdded;}
    int getQtyOnHand() {return qtyOnHand;}
    double getWholesale() {return wholesale;}
    double getRetail() {return retail;}
    double getWorth() {return worth;}
    //计算图书价值额
    void calworth(){worth = wholesale * qtyOnHand ;}
    //显示图书信息
    void showData();
};
#endif // TITLEINFO_H

