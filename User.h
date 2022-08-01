#ifndef _USER_H_
#define _USER_H_

#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include "Operator.h"
using namespace std;

// User类
class User{
private :

	string* m_name;
	int* m_age;
	string* m_bankCardNum; // 银行卡号
	string* m_psd;
	string* m_accountNum; // 用户账号
	double* m_balance;
	bool checkSameAccount(); // 检测账号是否相同
public:

	User(string name, int age, string bankCardNum, string psd);
	User();
	void createAccount(); // 生成账号
	string getName();
	int getAge();
	string getBankNum();
	string getPsd();
	string getAccount();
	double getBalance();
	void setName(string name);
	void setBankNum(string bankNum);
	void setAge(int age);
	void setBalance(double balance);
	void setPsd(string psd);
	void setAccount(string acc);

	~User();
};

#endif
