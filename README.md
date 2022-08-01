# -
本人大学生，为了进步自己做些小东西练练手
这个是银行信息管理系统，由于是自己练手的项目，所以里面的所有操作都是模拟

// 银行用户操作信息管理系统

/*
	需要实现的功能
	1.查询账户余额
	2.存钱 -> 记录所有的存放时间
	3.取钱 -> 记录取钱记录
	4.转账
	5.注册用户
	6.登陆功能 -> 使用系统前应先登陆
	7.退出应用

	tips: 该项目应该记录好所有交易的时间还有保护好后台的用户信息

*/

/*
	类设计
	class View 视图类 视图都放该类中
	class Control 管理类 管理整个应用程序
	class User 用户类 用户的信息属性
	class Func 功能类 管理功能
	class DateUtil 日期处理
*/

/*
	字段设计
	class User
Member:
	string* m_name -> 姓名 
	int* m_age -> 年龄
	string* m_bankCardNum -> 银行卡号
	string* m_psd 密码
	string* m_accountNum 账号
	string* m_balance 账户余额
*/
