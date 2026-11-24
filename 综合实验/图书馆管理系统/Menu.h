#ifndef MENU_H
#define MENU_H

#include "Library.h"
#include "User.h"

class Menu {
private:
    Library& lib;          // 引用图书馆对象
    User* currentUser;     // 指针记录当前登录用户

    // 辅助工具函数
    void clearScreen();    // 清屏
    void pause();          // 暂停，等待用户按回车

    // 各级子菜单逻辑
    void loginMenu();      // 登录界面
    void adminMenu();      // 管理员专属界面
    void readerMenu();     // 读者专属界面
    
    void borrowProcess();
    
	void adminoperate();
	
	void searchMenu(); 
	void userSettings();
public:
    Menu(Library& library);
    void run();            // 系统总入口
};

#endif
