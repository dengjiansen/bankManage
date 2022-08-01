#ifndef _CONTROL_H_
#define _CONTROL_H_
#include "View.h"
#include "Func.h"
#include "Operator.h"
// 控制类， 控制应用程序进程
class Control {
private:
	View* view;
	Func* func;
public:
	Control();
	void start(); // 开始
	~Control();
};

#endif
