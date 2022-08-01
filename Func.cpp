#include "Func.h"

Func::Func() {
	this->view = new View();
	this->user = nullptr;
	// 将数据插入键值对
	this->user_post.insert(make_pair(USER_POST_WITHDRAW_MONEY, WITHDRAW_MONEY));
	this->user_post.insert(make_pair(USER_POST_SAVE_MONEY, SAVE_MONEY));
	this->user_post.insert(make_pair(USER_POST_TRANSFER_ACCOUNT, TRANSFER_ACCOUNT));
	this->user_post.insert(make_pair(USER_POST_SHOW_DETAILS, SHOW_DETAILS));
	this->user_post.insert(make_pair(USER_POST_QUIT_EXE, QUIT_EXE));
}

void Func::printMsg(int x, int y, const char* msg) {
	SetColor(3);
	SetCursorPosition(x, y);
	std::cout << msg;
}

void Func::printMsg(int x, int y, string msg) {
	SetCursorPosition(x, y);
	std::cout << msg;
}

void Func::exit_op() {
	SetColor(3);
	printMsg(15, 8, "欢迎您的下次使用!");
	cout << endl;
	EXIT(0);
}

void Func::loginOut() {
	SetColor(3);
	printMsg(15, 10, "注销登陆");
	cout << endl;
	system("pause");
	system("cls");
}

void Func::initVec() {
	ifstream ifs;
	vector<string> temp_vec;
	string data;
	ifs.open(FILE_USER_MSG, ios::in);
	if (ifs.is_open()) {
		while (getline(ifs, data)) {
			temp_vec = spilt(data, " ");
			User* temp_user = new User();
			temp_user->setName(temp_vec[0]);
			temp_user->setAge(std::atoi(temp_vec[1].c_str()));
			temp_user->setBankNum(temp_vec[2]);
			temp_user->setBalance(std::atof(temp_vec[3].c_str()));
			vec.push_back(temp_user);
		}
	}
	ifs.close();

	int num = 0;
	ifs.open(FILE_USER_ACCOUNT_AND_PSD, ios::in);
	if (ifs.is_open()) {
		while (getline(ifs, data)) {
			temp_vec = spilt(data, " ");
			this->vec[num]->setAccount(temp_vec[0]);
			this->vec[num]->setPsd(temp_vec[1]);
			num++;
		}
	}
	ifs.close();
}

// 登陆界面相关操作
void Func::User_op(int oper) {

	string account, psd;
	string file;
	string tail = "Log.txt";
	PSS pss;
	switch (oper) {
	case LOGIN: // 登陆操作
		// 将光标显示出来
		HideCursor(false);
		printMsg(20, 8, "请输入账号:");
		std::cin >> account;
		printMsg(20, 9, "请输入密码:");
		std::cin >> psd;
		pss.first = account;
		pss.second = psd;
		// 检测用户密码
		if (IOUtils::read(FILE_USER_ACCOUNT_AND_PSD, pss)) {
			// 向系统发送登陆信息， 打印登陆日志
			// IOUtils::printLog(fileName, logType);
			// 先创建User对象
			this->user = IOUtils::readToUser(account);
			file = account + tail;
			// 打印日志
			//IOUtils::printLog(file, LOG_LOGIN, user);
			IOUtils::printLog(file, LOG_LOGIN, user);
			
			printMsg(20, 10, "身份认证成功");
			printMsg(20, 11, "登陆成功，正在跳转界面...");
			HideCursor(true);
			Sleep(1500);
			system("cls");

			while (true) {

				view->operatorMenu();
				// 获取操作
				int oper = view->getOperSelect();
				switch (oper) {
				case SAVE_MONEY:
					User_post(USER_POST_SAVE_MONEY);
					break;
				case WITHDRAW_MONEY:
					User_post(USER_POST_WITHDRAW_MONEY);
					break;
				case TRANSFER_ACCOUNT:
					User_post(USER_POST_TRANSFER_ACCOUNT);
					break;
				case SHOW_DETAILS:
					User_post(USER_POST_SHOW_DETAILS);
					break;
				}
				if (oper == QUIT_EXE) {
					loginOut();
					break;
				}
			}
			
		}
		else {
			printMsg(20, 10, "身份认证失败!");
			HideCursor(true);
			Sleep(1000);
			system("cls");
			return;
		}
		break;
	case REGISTER:
		HideCursor(false);
		string name, age, bankCard, psd;
		printMsg(20, 8, "请输入真实姓名:");
		cin >> name;
		printMsg(20, 9, "请输入您的年龄:");
		cin >> age;
		int realAge = atoi(age.c_str());
		printMsg(20, 10, "请输入银行卡号:");
		cin >> bankCard;
		printMsg(20, 11, "请设置您的密码:");
		cin >> psd;

		// 此处检查该银行卡是否已经注册过
		if (check(bankCard)) {
			printMsg(20, 12, "该银行已注册!注册失败");
			system("pause");
			system("cls");
			SetCursorPosition(20, 13);
			HideCursor(true);
		}
		else {
			User user(name, realAge, bankCard, psd); // 创建User对象

			printMsg(20, 12, "正在生成您的账号...");
			Sleep(1500);
			user.createAccount(); // 生成账号
			string acc = user.getAccount();
			printMsg(20, 13, "生成成功! 您的账号为:" + acc);

			// 打印注册日志
			file = acc + tail;
			IOUtils::printLog(file, LOG_REGISTER, &user);

			// 保存数据
			IOUtils::save(&user);
			HideCursor(true); // 隐藏光标
			SetCursorPosition(20, 14);
			system("pause");
			system("cls");
		}
		break;
	}
}

// 根据用户的请求完成对应的操作
void Func::User_post(string post_key) {
	string money, userAcc, bankNum;
	unsigned int post = this->user_post[post_key];
	double mon, currentMoney;
	bool isFind = false;
	string msg[2];
	switch (post) {
	case WITHDRAW_MONEY:
		// 取钱操作
		HideCursor(false);
		printMsg(20, 10, "请输入金额:");
		cin >> money;
		mon = atof(money.c_str());
		currentMoney = this->user->getBalance();
		if (currentMoney >= mon) {
			printMsg(20, 11, "操作成功!");
			this->user->setBalance(currentMoney - mon);
			system("pause");
			system("cls");
		}
		else{
			printMsg(20, 11, "余额不足!");
			HideCursor(true);
			system("pause");
			system("cls");
		}
		userAcc = this->user->getAccount();
		for (auto temp_user : vec) {
			if (userAcc == temp_user->getAccount()) {
				temp_user->setBalance(this->user->getBalance());
				break;
			}
		}
		msg[0] = money;
		// 打印日志
		IOUtils::printLog(userAcc + "Log.txt", LOG_WITHDRAW_MONEY, this->user, msg);
		// 重新写入文件
		IOUtils::write(vec);
		HideCursor(true);
		break;
	case SAVE_MONEY:
		// 存钱操作
		HideCursor(false);
		printMsg(20, 10, "请输入金额:");
		cin >> money;
		mon = atof(money.c_str());
		currentMoney = this->user->getBalance() + mon;
		userAcc = this->user->getAccount();
		this->user->setBalance(currentMoney);
		for (auto temp_user : vec) {
			if (temp_user->getAccount() == userAcc) {
				temp_user->setBalance(this->user->getBalance());
				break;
			}
		}
		printMsg(20, 11, "操作成功:");
		msg[0] = money;
		// 打印日志
		IOUtils::printLog(userAcc + "Log.txt", LOG_SAVE_MONEY, this->user, msg);

		IOUtils::write(vec);
		HideCursor(true);
		SetCursorPosition(20, 12);
		system("pause");
		system("cls");
		break;

	case TRANSFER_ACCOUNT:
		HideCursor(false);
		userAcc = this->user->getAccount();
		printMsg(20, 10, "请输入目标银行卡号:");
		cin >> bankNum;
		for (auto temp_user : vec) {

			if (temp_user->getBankNum() == bankNum && bankNum != this->user->getBankNum()) {

				isFind = true;
				printMsg(20, 11, "请输入金额:");
				cin >> money;
				mon = atof(money.c_str());
				currentMoney = this->user->getBalance();

				msg[0] = money;
				msg[1] = temp_user->getName();

				if (currentMoney >= mon) {

					currentMoney = temp_user->getBalance();
					temp_user->setBalance(currentMoney + mon);
					currentMoney = this->user->getBalance();
					this->user->setBalance(currentMoney - mon);

					printMsg(20, 12, "操作成功");
					IOUtils::printLog(userAcc + "Log.txt", LOG_TRANSFER_ACCOUNT, this->user, msg);
					system("pause");
					system("cls");
				}
				else {
					printMsg(20, 12, "余额不足!");
					HideCursor(true);
					system("pause");
					system("cls");
				}
				
				break;
			}
		}

		for (auto temp_user : vec) {
			if (temp_user->getAccount() == userAcc) {
				temp_user->setBalance(this->user->getBalance());
			}
		}

		if (!isFind) {
			printMsg(20, 11, "请检查银行卡号,银行卡号不正确!");
			HideCursor(true);
			system("pause");
			system("cls");
		}
		HideCursor(true);
		IOUtils::write(vec);
		break;
	case SHOW_DETAILS:
		userAcc = this->user->getAccount();
		IOUtils::printDetails(userAcc + "Log.txt");
		system("pause");
		system("cls");
		break;
	case QUIT_EXE:
		userAcc = this->user->getAccount();
		IOUtils::printLog(userAcc + "Log.txt", LOG_QUIT, this->user);
		this->loginOut();
		break;
	}
}

bool Func::check(string bankCard) {
	std::ifstream ifs;
	ifs.open(FILE_USER_MSG, ios::in);
	string data;
	vector<string> vec;
	if (ifs.is_open()) {
		while (getline(ifs, data)) {
			vec = spilt(data, " ");
			if (bankCard == vec.at(2))
				return true;
		}
	}
	return false;
}

vector<string> Func::spilt(string data, string regex) {
	vector<string> vec;
	data = data + regex;
	int pos = data.find(regex);

	while (pos != -1) {
		string tempStr = data.substr(0, pos);
		vec.push_back(tempStr);
		data = data.substr(pos + 1, data.size());
		pos = data.find(regex);
	}

	return vec;
}

Func::~Func() {
	if (this->view != nullptr) {
		delete this->view;
	}
	if (this->user != nullptr) {
		delete this->user;
	}
}
