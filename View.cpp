#include "View.h"
View::View() {
	loginSelect = 1;
	operSelect = 1;
	HideCursor(true); // 隐藏光标，用户体验更好
}

int View::getLoginSelect() {
	return this->loginSelect;
}

int View::getOperSelect() {
	return this->operSelect;
}

void View::loginMenu() {

	SetColor(3);
	SetCursorPosition(15, 0);
	cout << "********欢迎使用银行信息管理系统*********";
	SetCursorPosition(20, 1);
	cout << "*******************";
	SetCursorPosition(20, 2);
	SetBackColor();
	cout << "*     1.登陆      *";
	SetCursorPosition(20, 3);
	SetColor(3);
	cout << "*     2.注册      *";
	SetCursorPosition(20, 4);
	SetColor(3);
	cout << "*     3.退出      *";
	SetCursorPosition(20, 5);
	cout << "*******************";
	SetCursorPosition(20, 6);
	SetColor(3);
	cout << "  请按上下键选择:";
	SetCursorPosition(15, 7);
	cout << "*****************************************";
	SetColor(3);
	cout << endl;

	int ch; // 检测输入选项
	loginSelect = 1; // 初始选项为第一个
	bool PressEnter = false; // 是否按下enter键
	while (ch = _getch()) {
		switch (ch) {
		case 72: // 上方向键
			if (loginSelect > 1) {
				switch (loginSelect) {
				case 2:
					SetCursorPosition(20, 2);
					SetBackColor();
					cout << "*     1.登陆      *";

					SetCursorPosition(20, 3);
					SetColor(3);
					cout << "*     2.注册      *";
					loginSelect--;
					break;
				case 3:
					SetCursorPosition(20, 3);
					SetBackColor();
					cout << "*     2.注册      *";

					SetCursorPosition(20, 4);
					SetColor(3);
					cout << "*     3.退出      *";
					loginSelect--;
					break;
				}
			}
			break;
		case 80: // 下方向键
			if (loginSelect < 3) {
				switch (loginSelect) {
				case 1:
					SetCursorPosition(20, 3);
					SetBackColor();
					cout << "*     2.注册      *";

					SetCursorPosition(20, 2);
					SetColor(3);
					cout << "*     1.登陆      *";
					loginSelect++;
					break;
				case 2:
					SetCursorPosition(20, 4);
					SetBackColor();
					cout << "*     3.退出      *";

					SetCursorPosition(20, 3);
					SetColor(3);
					cout << "*     2.注册      *";
					loginSelect++;
					break;
				}
			}
			break;
		case 13:
			PressEnter = true;
			break;
		default: // 无效按键
			break;
		}
		if (PressEnter) break;
	}
	
}

// 操作菜单
void View::operatorMenu() {
	SetColor(3);
	SetCursorPosition(15, 0);
	cout << "**************用户操作界面**************";
	SetCursorPosition(20, 1);
	SetColor(3);
	cout << "*******************";
	SetCursorPosition(20, 2);
	SetColor(3);
	SetBackColor();
	cout << "*     1.存款      *";
	SetCursorPosition(20, 3);
	SetColor(3);
	cout << "*     2.提现      *";
	SetCursorPosition(20, 4);
	SetColor(3);
	cout << "*     3.转账      *";
	SetCursorPosition(20, 5);
	SetColor(3);
	cout << "*     4.明细      *";
	SetCursorPosition(20, 6);
	SetColor(3);
	cout << "*     5.退出      *";
	SetCursorPosition(20, 7);
	SetColor(3);
	cout << "*******************";
	SetCursorPosition(20, 8);
	cout << "  请按上下键选择:";
	SetColor(3);
	SetCursorPosition(15, 9);
	cout << "****************************************";

	int ch;
	operSelect = 1; // 默认在存款选项
	bool PressEnter = false;

	while (ch = _getch()) {
		switch (ch) {
		case 72:
			if (operSelect > 1) {
				switch (operSelect) {
				case 2:
					SetCursorPosition(20, 2);
					SetBackColor();
					cout << "*     1.存款      *";

					SetCursorPosition(20, 3);
					SetColor(3);
					cout << "*     2.提现      *";
					operSelect--;
					break;
				case 3:
					SetCursorPosition(20, 3);
					SetBackColor();
					cout << "*     2.提现      *";

					SetCursorPosition(20, 4);
					SetColor(3);
					cout << "*     3.转账      *";
					operSelect--;
					break;
				case 4:
					SetCursorPosition(20, 4);
					SetBackColor();
					cout << "*     3.转账      *";

					SetCursorPosition(20, 5);
					SetColor(3);
					cout << "*     4.明细      *";
					operSelect--;
					break;
				case 5:
					SetCursorPosition(20, 5);
					SetBackColor();
					cout << "*     4.明细      *";

					SetCursorPosition(20, 6);
					SetColor(3);
					cout << "*     5.退出      *";
					operSelect--;
					break;
				}
			}
			break;
		case 80:
			if (operSelect < 5) {
				switch (operSelect) {
				case 1:
					SetCursorPosition(20, 2);
					SetColor(3);
					cout << "*     1.存款      *";

					SetCursorPosition(20, 3);
					SetBackColor();
					cout << "*     2.提现      *";
					operSelect++;
					break;
				case 2:
					SetCursorPosition(20, 3);
					SetColor(3);
					cout << "*     2.提现      *";

					SetCursorPosition(20, 4);
					SetBackColor();
					cout << "*     3.转账      *";
					operSelect++;
					break;
				case 3:
					SetCursorPosition(20, 4);
					SetColor(3);
					cout << "*     3.转账      *";

					SetCursorPosition(20, 5);
					SetBackColor();
					cout << "*     4.明细      *";
					operSelect++;
					break;
				case 4:
					SetCursorPosition(20, 5);
					SetColor(3);
					cout << "*     4.明细      *";

					SetCursorPosition(20, 6);
					SetBackColor();
					cout << "*     5.退出      *";
					operSelect++;
					break;
				}
			}
			break;
		case 13:
			PressEnter = true;
			break;
		default:
			break;
		}
		if (PressEnter) break;
	}
	
}
