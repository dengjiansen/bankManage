#ifndef _OPERATOR_H_
#define _OPERATOR_H_

// 此文件提供各种需要使用的宏
// 重命名pair
using PSS = std::pair<std::string, std::string>;

#define LOGIN 1   // 登陆
#define	REGISTER 2 // 注册
#define QUIT 3 // 退出
#define RETURN 0 // 返回
#define EXIT(status) exit(status)  // 结束程序

#define FILE_USER_MSG "User.txt" // 保存用户信息
#define FILE_USER_ACCOUNT_AND_PSD "AccountAndPsd.txt" // 保存用户账号和密码

// 用户请求
#define USER_POST_WITHDRAW_MONEY "withdraw_money"
#define USER_POST_SAVE_MONEY "save_money"
#define USER_POST_TRANSFER_ACCOUNT "transfer_account"
#define USER_POST_SHOW_DETAILS "show_details"
#define USER_POST_QUIT_EXE "quit_exe"

// 用户操作
#define SAVE_MONEY 1
#define WITHDRAW_MONEY 2
#define TRANSFER_ACCOUNT 3
#define SHOW_DETAILS 4
#define QUIT_EXE 5

// 打印log相关宏
#define LOG_LOGIN 1
#define LOG_REGISTER 2
#define LOG_QUIT 3
#define LOG_SAVE_MONEY 4
#define LOG_WITHDRAW_MONEY 5
#define LOG_TRANSFER_ACCOUNT 6
#define LOG_SHOW_DETAILS 7

#endif
