#ifndef _FUNC_H_
#define _FUNC_H_
#include <iostream>
#include <map>
#include <windows.h>
#include "Operator.h"
#include "ToolKit.h"
#include "View.h"
#include "IOUtils.h"
#include <vector>
using namespace std;
class Func {
private:
	map<string, int> user_post;
	View* view;
	User* user;
	vector<User*> vec; // 用来储存用户
public:
	Func();
	void initVec(); // 初始化vector容器
	void User_op(int oper); // 用户各种操作 // 登陆，注册
	void exit_op(); // 退出应用
	void User_post(string post); // 用户操作的请求 存钱， 取钱， 转账, 明细
	void printMsg(int x, int y, const char* msg); // 打印信息
	void printMsg(int x, int y, string msg);
	void loginOut(); // 注销登陆
	bool check(string bankCard); // 检测银行卡是否重复注册
	vector<string> spilt(string data, string regex); // 分割字符串
	~Func();
};

#endif
