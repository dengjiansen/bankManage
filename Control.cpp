#include "Control.h"
Control::Control() {
	this->view = new View();
	this->func = new Func();
}

Control::~Control() {
	if (view != nullptr) delete view;
	if (func != nullptr) delete func;
}

void Control::start() {

	func->initVec();

	while (true) {
		view->loginMenu();

		int select = view->getLoginSelect();

		switch (select) {
		case LOGIN:
			func->User_op(LOGIN);
			break;
		case REGISTER:
			func->User_op(REGISTER);
			break;
		case QUIT:
			func->exit_op();
			break;
		}
	}
}
