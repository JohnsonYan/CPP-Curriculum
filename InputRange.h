/*
    �Ϻ�С��������ϵͳ
    ���ߣ��ƬB 161420219
    ʱ�䣺2015-5-17
    ����C++�γ����
*/
#ifndef INPUTRANGE_H
#define INPUTRANGE_H
/* �������ڼ����Ƿ���������Ч����*/
class InputRange
{
private:
    char *errMsg;//������Ϣ
    char input;//�û�����ֵ
    char lower;//��Ч�ַ��ĵͽ�
    char upper;//��Ч�ַ��ĸ߽�
public:
    InputRange(  char , char ,const char *);//����Ĺ��캯��
    ~InputRange();//��������
    char getInput();
};
#endif // INPUTRANGE_H
