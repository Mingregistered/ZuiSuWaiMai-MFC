#include "pch.h"
#include <cstringt.h>
#include <iostream>
#include "InfoFile.h"
#include "stdafx.h"
#include <fstream>
using namespace std;
CInfoFile::CInfoFile()
{
}


CInfoFile::~CInfoFile()
{
}

//��ȡ��¼��Ϣ
void CInfoFile::ReadLogin( CString &name, CString &pwd )
{
	ifstream ifs;	//�����ļ��������
	ifs.open(SHOP_LOGIN);

	char buf[1024] ={0};

	ifs.getline(buf, sizeof(buf));	//��ȡһ������
	name = CString(buf);	//��char* ת��ΪCString

	ifs.getline(buf, sizeof(buf));	//��ȡһ������
	pwd = CString(buf);	//��char* ת��ΪCString

	ifs.close();	//�ر��ļ�
}

//�޸�����
void CInfoFile::WritePwd( char* name, char* pwd )
{
	ofstream ofs;	//�����ļ��������
	ofs.open(SHOP_LOGIN); //���ļ�
	
	ofs<< name <<endl;	//nameд���ļ�
	ofs<< pwd <<endl;	//pwdд���ļ�
	
	ofs.close();	//�ر��ļ�
}


