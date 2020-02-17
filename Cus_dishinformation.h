//������Ϣ�ܱ�
//���ļ���������д��2019/9/1

#pragma once
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <afxdisp.h>

#define Cus_F_LOGIN "./Cus_login.ini"
#define _F_DISINFO "./cus_dishinformation.txt"
#define _F_STOCK "./stock.txt"

using namespace std;

struct msgoforder
{
	//����ID|�����|�̼���|������x���ݣ�|�۸�|�µ�ʱ��|����ʱ��|�ջ�ʱ��

	int idoforder;			//����id
	string nameofshop;	//�����̼���
	string nameofcustomer;//���������
	string nameofalldish;//������ȫ������
	int priceoforder;		//�����۸�
	string purchasetime;//�µ�ʱ��
	string delievertime;//����ʱ��
	string receivingtime;//�ջ�ʱ��
	int locationofcus;//�ջ���ַ
};

struct msgofstock
{
	int idofstock;			//��Ʒid
	string nameofstock;	//��Ʒ��
	int priceofstock;		//��Ʒ�۸�
	int numofonestock;		//��Ʒ����
};

class CCus_dishinformation
{

public:


	//��ȡ��¼��Ϣ
	void ReadLogin(CString& name, CString& pwd);

	//�޸�����
	void WritePwd(char* name, char* pwd);

	//��ȡ��������
	void ReadOrderDocline();

	//����������д���ļ�
	void WriteOrderDocline();

	//����ID|�����|�̼���|������x���ݣ�|�۸�|�µ�ʱ��|����ʱ��|�ջ�ʱ��
	//����¶���

	void AddOrderline(string nameofshop,	//�����̼���
		string nameofcustomer,//���������
		string nameofalldish,//������ȫ������
		int price,		//�����۸�
		string purchasetime,//�µ�ʱ��
		string delievertime,//����ʱ��
		string receivingtime,//�ջ�ʱ��
		int locationofcus//�ջ��ص�
	);

		//��ȡ��Ʒ����
	void ReadstockDocline();

	//��Ʒд���ļ�
	void WritestockDocline();

	//�������Ʒ
	void Addstockline(CString name, int num, int price);

	list<msgofstock> lsstock;	//�洢��Ʒ����
	int numofallstock;			//������¼��Ʒ����


	list<msgoforder> lsorder;	//�洢��Ʒ����
	int numoforder;			//������¼��Ʒ����

	int flagofcusloction;//�洢���λ��
};

#pragma once