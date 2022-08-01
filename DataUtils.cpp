#include "DateUtils.h"

std::string DateUtils::DateFormat() {
	now = time(0);
	tm_ptr = localtime(&now);
	std::string year = std::to_string(tm_ptr->tm_year + 1900);
	std::string month = std::to_string(tm_ptr->tm_mon + 1);
	std::string day = std::to_string(tm_ptr->tm_mday);

	std::string hour = std::to_string(tm_ptr->tm_hour);
	std::string min = std::to_string(tm_ptr->tm_min);
	std::string second = std::to_string(tm_ptr->tm_sec);

	std::string formatTime = year + "-" + month + "-" + day + " "
		+ hour + ":" + min + ":" + second;

	return formatTime;
}
