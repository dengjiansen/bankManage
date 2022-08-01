#include "User.h"

User::User(string name, int age, string bankCardNum, string psd) {
	string* username = new string(name);
	int* userage = new int(age);
	string* userBankCardNum = new string(bankCardNum);
	string* userpsd = new string(psd);

	this->m_name = username;
	this->m_age = userage;
	this->m_bankCardNum = userBankCardNum;
	this->m_psd = userpsd;

	this->m_balance = new double(0);
	this->m_accountNum = nullptr;
}

User::User() : 
	m_accountNum(nullptr), m_age(nullptr), m_balance(nullptr) , 
	m_bankCardNum(nullptr), m_name(nullptr), m_psd(nullptr){}

bool User::checkSameAccount() {
	ifstream ifs;
	ifs.open(FILE_USER_ACCOUNT_AND_PSD, ios::in);
	string acc, psd;
	if (ifs.is_open()) {
		while (ifs >> acc && ifs >> psd) {
			if (acc == this->getAccount())
				return false;
		}
	}
	return true;
}

// 生成账号
void User::createAccount() {
	string acc;
	srand((unsigned)time(NULL));

	while (true) {
		// 生成十位数字的账号
		for (int i = 0; i < 10; ++i) {
			int accNum = rand() % 10;
			string str = to_string(accNum);
			acc += str;
		}
		string* p_str = new string(acc);
		this->m_accountNum = p_str;
		if (this->checkSameAccount()) {
			p_str = nullptr;
			return;
		}
		else {
			p_str = nullptr;
			delete m_accountNum; // 需要手动删除
		}
	}
}

string User::getName() {
	return *(this->m_name);
}

int User::getAge() {
	return *(this->m_age);
}

string User::getBankNum() {
	return *(this->m_bankCardNum);
}

string User::getPsd() {
	return *(this->m_psd);
}

string User::getAccount() {
	return *(this->m_accountNum);
}

double User::getBalance() {
	return *(this->m_balance);
}

void User::setPsd(string psd) {
	string* p_str = new string(psd);
	if (this->m_psd != nullptr)
		delete this->m_psd;
	this->m_psd = p_str;
	p_str = nullptr;
}

void User::setBalance(double balance) {
	this->m_balance = new double(balance);
}

void User::setAge(int age) {
	this->m_age = new int(age);
}

void User::setName(string name) {
	this->m_name = new string(name);
}

void User::setBankNum(string bankNum) {
	this->m_bankCardNum = new string(bankNum);
}

void User::setAccount(string acc) {
	this->m_accountNum = new string(acc);
}

User::~User() {
	if (this->m_name != nullptr) delete this->m_name;
	if (this->m_age != nullptr) delete this->m_age;
	if (this->m_accountNum != nullptr) delete this->m_accountNum;
	if (this->m_bankCardNum != nullptr) delete this->m_bankCardNum;
	if (this->m_balance != nullptr) delete this->m_balance;
	if (this->m_psd != nullptr) delete this->m_psd;
}
