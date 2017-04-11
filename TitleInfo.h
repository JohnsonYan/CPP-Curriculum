/*
    �Ϻ�С��������ϵͳ
    ���ߣ��ƬB 161420219
    ʱ�䣺2015-5-17
    ����C++�γ����
*/
#ifndef TITLEINFO_H
#define TITLEINFP_H
class TitleInfo
{
protected:
    static int num;//�þ�̬����ΪTitleInfo�๲�У����ڼ�¼TitileInfo�������鼮��Ŀ
    char isbn[14];//ISBN��
    char bookTitle[51];//����
    char author[31];//����
    char publisher[31];//������
    char dateAdded[11];//����ʱ��
    int qtyOnHand;//���
    double wholesale;//������
    double retail;//���ۼ�
    double worth;//�������ܶҲ�����鼮��ֵ��
public:
    TitleInfo();
    TitleInfo(TitleInfo &);

    //���ظ�ֵ�����
    TitleInfo operator = (const TitleInfo &obj);
    void setNum(int x) {num = x;}//���þ�̬����num��ֵ
    int getNum() {return num;}//���ؾ�̬����num��ֵ
    //��ȡͼ����Ϣ
    char* getIsbn() {return isbn;}
    char* getBookTitle() {return bookTitle;}
    char* getAuthor() {return author;}
    char* getPublisher() {return publisher;}
    char* getDateAdded() {return dateAdded;}
    int getQtyOnHand() {return qtyOnHand;}
    double getWholesale() {return wholesale;}
    double getRetail() {return retail;}
    double getWorth() {return worth;}
    //����ͼ���ֵ��
    void calworth(){worth = wholesale * qtyOnHand ;}
    //��ʾͼ����Ϣ
    void showData();
};
#endif // TITLEINFO_H

