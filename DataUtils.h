#ifndef _DATEUTILS_H_
#define _DATEUTILS_H_
#pragma warning(disable:4996)
#include <ctime>
#include <iostream>
#include <string>
// 用来获取时间
class DateUtils {
private:
	struct tm* tm_ptr;
	time_t now;
public:
	std::string DateFormat();
};
#endif
