#pragma once

#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <afxdisp.h>

#define SHOP_LOGIN "./login.ini"

using namespace std;



class CInfoFile
{
public:
	CInfoFile();
	~CInfoFile();

	//��ȡ��¼��Ϣ
	void ReadLogin(CString &name, CString &pwd);

	//�޸�����
	void WritePwd(char* name, char* pwd);


};

