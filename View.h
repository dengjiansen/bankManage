#ifndef _VIEW_H_
#define _VIEW_H_
#include "ToolKit.h"
#include <iostream>
#include <conio.h>
using namespace std;
class View {
private:
	int loginSelect; // 登陆界面的选择
	int operSelect; // 操作界面的选择
public:
	View();
	void loginMenu();
	void operatorMenu();
	int getLoginSelect();
	int getOperSelect();
};

#endif
