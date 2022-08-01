#include "IOUtils.h"

bool IOUtils::read(std::string fileName, PSS pss) {
	std::ifstream ifs;
	ifs.open(fileName, ios::in);
	std::string account, psd;
	if (ifs.is_open()) {
		while (ifs >> account && ifs >> psd) {
			if (account == pss.first && psd == pss.second) {
				ifs.close();
				return true;
			}
		}
		ifs.close();
		return false;
	}
	return false;
}

// 保存至文件
void IOUtils::save(User* user) {
	std::ofstream ofs;
	ofs.open(FILE_USER_MSG, ios::out | ios::app);
	std::string name;
	std::string age;
	std::string bankCard;
	std::string balance;

	name = user->getName();
	age = std::to_string(user->getAge());
	bankCard = user->getBankNum();
	balance = std::to_string(user->getBalance());

	// 将这些数据写入
	ofs << name << " "
		<< age << " " 
		<< bankCard << " "
		<< balance << endl;

	ofs.close();

	ofs.open(FILE_USER_ACCOUNT_AND_PSD, ios::out | ios::app);
	std::string account;
	std::string psd;

	account = user->getAccount();
	psd = user->getPsd();

	ofs << account << " "
		<< psd << endl;

	ofs.close();
}

User* IOUtils::readToUser(std::string acc) {
	int row = 1;
	std::ifstream ifs;
	ifs.open(FILE_USER_ACCOUNT_AND_PSD, ios::in);
	std::string account, psd;
	while (ifs >> account && ifs >> psd) {
		if (account == acc)
			break;
		row++;
	}
	ifs.close();

	ifs.open(FILE_USER_MSG, ios::in);
	std::string name, age, bankCard, balance;
	for (int index = 1; index <= row; index++) {
		// 遍历到该用户
		ifs >> name;
		ifs >> age;
		ifs >> bankCard;
		ifs >> balance;
	}
	int realAge = std::atoi(age.c_str());

	User* user = new User(name, realAge, bankCard, psd);
	user->setBalance(std::atof(balance.c_str()));
	user->setAccount(account);
	ifs.close();
	return user;
}

void IOUtils::printDetails(std::string fileName) {
	std::ifstream ifs;
	ifs.open(fileName, ios::in);
	string msg;
	int row = 10;
	while (getline(ifs, msg)) {
		SetColor(3);
		SetCursorPosition(15, row);
		std::cout << msg << endl;
		row++;
	}

}

void IOUtils::printLog(std::string fileName, int logType, User* user, std::string data[]) {
	// 打印日志
	/*
		#define LOG_LOGIN 1
		#define LOG_REGISTER 2;
		#define LOG_QUIT 3
		#define LOG_SAVE_MONEY 4
		#define LOG_WITHDRAW_MONEY 5
		#define LOG_TRANSFER_ACCOUNT 6
		#define LOG_SHOW_DETAILS 7
	*/
	DateUtils date;
	std::ofstream ofs;
	ofs.open(fileName, ios::out | ios::app);
	switch (logType) {
	case LOG_LOGIN:
		ofs << "用户:" << user->getName() << " "
			<< "账号:" << user->getAccount() 
			<< "在" + date.DateFormat() 
			<< "登陆" << endl;
		break;
	case LOG_REGISTER:
		ofs << "用户:" << user->getName() << " "
			<< "账号:" << user->getAccount()
			<< "在" + date.DateFormat()
			<< "注册" << endl;
		break;
	case LOG_SAVE_MONEY:
		ofs << "用户:" << user->getName() << " "
			<< "账号:" << user->getAccount()
			<< "在" + date.DateFormat()
			<< "存入" << data[0] << "元" << endl;
		break;
	case LOG_SHOW_DETAILS:
		ofs << "用户:" << user->getName() << " "
			<< "账号:" << user->getAccount()
			<< "在" + date.DateFormat()
			<< "查看记录" << endl;
		break;
	case LOG_WITHDRAW_MONEY:
		ofs << "用户:" << user->getName() << " "
			<< "账号:" << user->getAccount()
			<< "在" + date.DateFormat()
			<< "取出" << data[0] << "元" << endl;
		break;
	case LOG_TRANSFER_ACCOUNT:
		ofs << "用户:" << user->getName() << " "
			<< "账号:" << user->getAccount()
			<< "在" + date.DateFormat()
			<< "向用户" << data[1] 
			<< "进行转账," << "转账金额:" << data[0] << "元" << endl;
		break;
	case LOG_QUIT:
		ofs << "用户:" << user->getName() << " "
			<< "账号:" << user->getAccount()
			<< "在" + date.DateFormat()
			<< "退出登陆" << endl;
		break;
	}
	ofs.close();
}

void IOUtils::write(vector<User*>& vec) {
	std::ofstream ofs;
	ofs.open(FILE_USER_MSG, ios::trunc | ios::out);
	for (auto user : vec) {
		ofs << user->getName() << " "
			<< user->getAge() << " "
			<< user->getBankNum() << " "
			<< user->getBalance() << endl;
	}
	ofs.close();

	ofs.open(FILE_USER_ACCOUNT_AND_PSD, ios::trunc | ios::out);
	for (auto user : vec) {
		ofs << user->getAccount() << " "
			<< user->getPsd() << endl;
 	}
	ofs.close();
}
