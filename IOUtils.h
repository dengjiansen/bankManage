#ifndef _IOUTILS_H_
#define _IOUTILS_H_
// 该文件为IO操作流
#include <iostream>
#include <fstream>
#include "User.h"
#include "Operator.h"
#include "ToolKit.h"
#include "DateUtils.h"
#include <vector>

class IOUtils {
public:
	// 打印活动日志的文件命名方式为用户名+log.txt
	void static printLog(std::string fileName, int logType, User* user, std::string data[] = {}); // 打印用户的活动日志
	bool static read(std::string fileName, PSS pss); // 读取文件
	void static write(vector<User*>& vec); // 写入文件
	static User* readToUser(std::string acc); // 将读取的文件信息封装为User类的对象
	void static save(User* user); // 保存
	void static printDetails(std::string fileName);
};

#endif
