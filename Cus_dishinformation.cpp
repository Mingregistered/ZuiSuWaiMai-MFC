//���ļ���������д��2019.9.9

#include "pch.h"
#include <cstringt.h>
#include <iostream>
#include "Cus_dishinformation.h"
#include "stdafx.h"
#include <fstream>
using namespace std;


// int id;			    //����id
// string nameofshop;	//�����̼���
// string nameofcustomer;//���������
// string nameofalldish;//������ȫ������
// int price;		    //�����۸�
// string purchasetime; //�µ�ʱ��
// string delievertime; //����ʱ��
// string receivingtime;//�ջ�ʱ��


//��ȡ��¼��Ϣ
void CCus_dishinformation::ReadLogin(CString& name, CString& pwd)
{

	ifstream ifs;	//�����ļ��������
	ifs.open(Cus_F_LOGIN);
	
	char buf[1024] = { 0 };
	
	ifs.getline(buf, sizeof(buf));	//��ȡһ������
	
	name = CString(buf);	//��char* ת��ΪCString

	ifs.getline(buf, sizeof(buf));	//��ȡһ������
	
	pwd = CString(buf);	//��char* ת��ΪCString
	ifs.close();	//�ر��ļ�
}

//�޸�����
void CCus_dishinformation::WritePwd(char* name, char* pwd)
{
	ofstream ofs;	//�����ļ��������
	ofs.open(Cus_F_LOGIN); //���ļ�

	ofs << name << endl;	//nameд���ļ�
	ofs << pwd << endl;	//pwdд���ļ�

	ofs.close();	//�ر��ļ�
}

//��ȡ��������Ϣ 
void CCus_dishinformation::ReadOrderDocline()
{
	ifstream ifs(_F_DISINFO);	//���뷽ʽ���ļ�

	char buf[1024] = { 0 };

	numoforder = 0;	//��ʼ����������Ϊ0
	
	lsorder.clear();

	//ȡ����ͷ
	ifs.getline(buf, sizeof(buf));

	while (!ifs.eof())	//û���ļ���β
	{
		msgoforder tmporder;

		ifs.getline(buf, sizeof(buf));	//��ȡһ��
		numoforder++;	//����������һ

		//AfxMessageBox(CString(buf));
		char* sst = strtok(buf, "|");	//��"|"�ָ�
		if (sst != NULL)
		{
			tmporder.idoforder = atoi(sst);	//����id
		}
		else
		{
			break;
		}

// string nameofshop;	//�����̼���
// string nameofcustomer;//���������

		sst = strtok(NULL, "|");
		tmporder.nameofshop = sst;	//�̼���

		sst = strtok(NULL, "|");
		tmporder.nameofcustomer = sst;	//�����

		sst = strtok(NULL, "|");
		tmporder.nameofalldish = sst;	//������ȫ������

		sst = strtok(NULL, "|");
		tmporder.priceoforder = atoi(sst);	     //�����۸�


// string purchasetime;//�µ�ʱ��
// string delievertime;//����ʱ��
// string receivingtime;//�ջ�ʱ��
		
		sst = strtok(NULL, "|");
		tmporder.purchasetime = sst;	//�µ�ʱ��

		sst = strtok(NULL, "|");
		tmporder.delievertime = sst;	//����ʱ��

		sst = strtok(NULL, "|");
		tmporder.receivingtime = sst;  //�ջ�ʱ��

		sst = strtok(NULL, "|");
		tmporder.locationofcus = atoi(sst);	     //�����۸�

		lsorder.push_back(tmporder);	//��������ĺ���
	
	}

	ifs.close();	//�ر��ļ�
}

//����д���ļ�

void CCus_dishinformation::WriteOrderDocline()
{

	ofstream ofs(_F_DISINFO);	//�����ʽ���ļ�
	//����ID|�����|�̼���|������x���ݣ�|�۸�|�µ�ʱ��|����ʱ��|�ջ�ʱ��
	
	string bt = "����ID|�����|�̼���|����(x����)|�۸�|�µ�ʱ��|����ʱ��|�ջ�ʱ��|���λ��";

	if (lsorder.size() > 0)	//�������������ݲ�ִ��
	{
		ofs << bt << endl;	//д���ͷ

		//ͨ��������ȡ���������ݣ�д���ļ�����"|"�ָ��β�ӻ���
		for (list<msgoforder>::iterator it = lsorder.begin(); it != lsorder.end(); it++)
		{


// string nameofalldish;//������ȫ������
// int price;		//�����۸�
// string purchasetime;//�µ�ʱ��
// string delievertime;//����ʱ��
// string receivingtime;//�ջ�ʱ��

			ofs << it->idoforder << "|";

			ofs << it->nameofcustomer << "|";

			ofs << it->nameofshop << "|";
			
			ofs << it->nameofalldish << "|";

			ofs << it->priceoforder << "|";
			
			ofs << it->purchasetime << "|";

			ofs << it->delievertime << "|";

			ofs << it->receivingtime  << "|";

			ofs << it->locationofcus << endl;
		}
	}
	ofs.close();
}

//����¶���


void CCus_dishinformation::AddOrderline(string nameofshop,	//�����̼���
	string nameofcustomer,//���������
	string nameofalldish,//������ȫ������
	int price,		//�����۸�
	string purchasetime,//�µ�ʱ��
	string delievertime,//����ʱ��
	string receivingtime,
	int locationofcus)
{
	msgoforder tmpoforder;

	if (lsorder.size() > 0)
	{
		//�۸���Ч���Ѿ�����

		if ( price > 0 && (!purchasetime.empty()))
		{

			tmpoforder.idoforder = lsorder.size() + 1;	//id�Զ���1
	
			tmpoforder.nameofshop = nameofshop;

			tmpoforder.nameofcustomer = nameofcustomer;

			tmpoforder.nameofalldish = nameofalldish;

			tmpoforder.priceoforder = price;		//�۸�

			tmpoforder.purchasetime = purchasetime;


			if (!delievertime.empty()&&delievertime!=("��δ����"))
			{
				tmpoforder.delievertime = delievertime;
			}

			else
			{
				tmpoforder.delievertime = "��δ����";
			}


			if (!receivingtime.empty() && receivingtime != ("��δ�ջ�"))
			{
				tmpoforder.receivingtime = receivingtime;
			}
			else
			{
				tmpoforder.receivingtime = "��δ�ջ�";
			}

			if (locationofcus<0)
			{
				locationofcus = 20;//Ĭ�ϴ�20��ʼ
			}

			tmpoforder.locationofcus = locationofcus;

			lsorder.push_back(tmpoforder);			//��������ĺ���
		}
	}
}

void CCus_dishinformation::ReadstockDocline()
{
	ifstream ifs(_F_STOCK);	//���뷽ʽ���ļ�

	char buf[1024] = { 0 };
	numofallstock = 0;	//��ʼ����Ʒ����Ϊ0
	lsstock.clear();
	//ȡ����ͷ

	ifs.getline(buf, sizeof(buf));

	while (!ifs.eof())	//û���ļ���β
	{
		msgofstock stocktmp;

		ifs.getline(buf, sizeof(buf));	//��ȡһ��
		numofallstock++;	//��Ʒ������һ

		//AfxMessageBox(CString(buf));
		char* sst = strtok(buf, "|");	//��"|"�ָ�
		if (sst != NULL)
		{
			stocktmp.idofstock = atoi(sst);	//��Ʒid
		}
		else
		{
			break;
		}

		sst = strtok(NULL, "|");
		stocktmp.nameofstock = sst;	//��Ʒ����

		sst = strtok(NULL, "|");
		stocktmp.priceofstock = atoi(sst);	//��Ʒ�۸�

		sst = strtok(NULL, "|");
		stocktmp.numofonestock = atoi(sst);	//��Ʒ��Ŀ

		lsstock.push_back(stocktmp);	//��������ĺ���
	}
	ifs.close();	//�ر��ļ�
}

void CCus_dishinformation::WritestockDocline()
{
	ofstream ofs(_F_STOCK);	//�����ʽ���ļ�
	string bt = "��ƷID|��Ʒ��|����|���";

	if (lsstock.size() > 0)	//��Ʒ���������ݲ�ִ��
	{
		ofs << bt << endl;	//д���ͷ

		//ͨ��������ȡ���������ݣ�д���ļ�����"|"�ָ��β�ӻ���
		for (list<msgofstock>::iterator it = lsstock.begin(); it != lsstock.end(); it++)
		{
			ofs << it->idofstock << "|";
			ofs << it->nameofstock << "|";
			ofs << it->priceofstock << "|";
			ofs << it->numofonestock << endl;
		}
	}
	ofs.close();
}

void CCus_dishinformation::Addstockline(CString name, int num, int price)
{
	msgofstock tmpofstock;

	if (lsstock.size() > 0)
	{
		//��Ʒ���ƣ���棬�۸���Ч
		if (!name.IsEmpty() && num > 0 && price > 0)
		{
			tmpofstock.idofstock = lsstock.size() + 1;	//id�Զ���1
			CStringA str;
			str = name;					//CString תCStringA
			tmpofstock.nameofstock = str.GetBuffer();//CString תΪchar *, ��Ʒ����
			tmpofstock.numofonestock = num;			//���
			tmpofstock.priceofstock = price;		//�۸�

			lsstock.push_back(tmpofstock);			//��������ĺ���
		}
	}
}


