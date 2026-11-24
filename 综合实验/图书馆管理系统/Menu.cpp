#include "Menu.h"
#include <iostream>
#include <limits>

using namespace std;

Menu::Menu(Library& library) : lib(library), currentUser(nullptr) {}

// 清屏
void Menu::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// 暂停
void Menu::pause() {
    cout << "\n按回车键继续...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

//主要运行入口 
void Menu::run() {
    int choice;
    while (true) {
        clearScreen();
        cout << "\t\t\t\t||====================================||" << endl;
        cout << "\t\t\t\t||      H大学图书管理系统 (v1.0)      ||" << endl;
        cout << "\t\t\t\t||====================================||" << endl;
        cout << "\t\t\t\t||         1. 用户登录                ||" << endl;
        cout << "\t\t\t\t||         2. 访客浏览 (仅查看书籍)   ||" << endl;
        cout << "\t\t\t\t||         3. 注册账号                ||" << endl;
        cout << "\t\t\t\t||         0. 退出系统                ||" << endl;
        cout << "\t\t\t\t||------------------------------------||" << endl;
        cout << "\t\t\t\t请输入选择: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
		
        if (choice == 0) break;
        switch (choice) {
            case 1: loginMenu(); break;
            case 2: lib.showAllBooks(); pause(); break;
            case 3:  
            {
                while (true) { 
                    clearScreen();
                    cout << "------ 创建用户 ------" << endl; 
                    cout << "1. 创建管理员账户" << endl;
                    cout << "2. 创建读者账号" << endl; 
                    cout << "0. 返回主菜单" << endl;
                    cout << "----------------------" << endl;
                    cout << "请输入选择: ";
                    
                    int role;
                    if (!(cin >> role)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue; 
                    }

                    if (role == 0) break; 

                    if (role != 1 && role != 2) {
                        cout << "无效的选择！" << endl;
                        pause();
                        continue;
                    }

                    string acc, pwd;

                    cout << "请输入账号 (输入 0 返回上一步): ";
                    cin >> acc;
                    if (acc == "0") {
                        continue;
                    }

                    cout << "请输入密码 (输入 0 返回上一步): ";
                    cin >> pwd;
                    if (pwd == "0") {
                        continue;
                    }
                    
                    if(lib.registerUser(acc, pwd, role)) {
                        cout << "注册成功！请使用新账号登录。" << endl;
                        pause();
                        break;
                    } else {
                        pause();
                    }
                }
                break;
            }
            default: cout << "选择无效，请重试。" << endl; pause();
        }
    }
}

// 登录子菜单
void Menu::loginMenu() {
    string acc, pwd;
    cout << "账号: "; cin >> acc;
    cout << "密码: "; cin >> pwd;

    currentUser = lib.login(acc, pwd);

    if (currentUser) {
        cout << "登录成功！" << endl;
        pause(); 
        if (currentUser->getRole() == 1) adminMenu();
        else readerMenu();
    } else {
        cout << "登录失败：账号不存在或密码错误。" << endl;
        pause();
    }
    currentUser = nullptr; 
}

// 管理员分级菜单
void Menu::adminMenu() {
    int choice;
    while (true) {
        clearScreen();
        cout << "--- 管理员模式 [" << currentUser->getAccount() << "] ---" << endl;
        cout << "1. 书籍信息管理 (增删改查)" << endl;
        cout << "2. 读者账户密码重置" << endl;
        cout << "3. 查看借阅排行榜" << endl;
        cout << "4. 查看个人信息" << endl;
        cout << "5. 读者用户信息管理" << endl;
        cout << "6. 借阅次数前十的图书" << endl;
		cout << "7. 最新出版前十的图书" << endl;  
        cout << "0. 返回上级菜单" << endl;
        cout << "选择: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1: 
                adminoperate();
                break;
            case 2:
            	lib.resetReaderPassword();
            	pause();
            	break;
            case 3:
                lib.showTopBorrowed();
                pause();
                break;
            case 4:
            	currentUser->displayInfo();
            	pause();
            	break;
            case 5:
            	clearScreen();
            	cout << "--- 读者管理 ---" << endl;
            	cout << "1. 查看所有读者\n2. 删除读者账号\n3. 重置读者密码\n0. 返回\n选择: ";
            	int sub; cin >> sub;
            	if (sub == 1) lib.showAllReaders();
            	else if (sub == 2) lib.deleteReader();
            	else if (sub == 3) lib.resetReaderPassword();
            	pause();
            	case 0:
            	break;
            case 6:
				lib.showTopBorrowed();
				pause();
				break;
			case 7:
				lib.showLatestBooks();
				pause();
				break;
        }
    }
}

// 读者分级菜单
void Menu::readerMenu() {
    int choice;
    while (true) {
        clearScreen();
        cout << "--- 读者模式 [" << currentUser->getAccount() << "] ---" << endl;
        cout << "1. 搜索图书 (任意信息)" << endl;
        cout << "2. 借阅图书" << endl;
        cout << "3. 查看借阅的书籍" << endl;
        cout << "4. 归还图书" << endl;
        cout << "5. 查看个人信息" << endl; 
        cout << "6. 借阅次数前十的图书" << endl;
		cout << "7. 最新出版前十的图书" << endl;  
        cout << "0. 返回上级菜单" << endl;
        cout << "选择: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1:
                searchMenu();
                break;
            case 2:
            	borrowProcess();
            	pause();
            	break;
            case 3:
            {
			    Reader* r = dynamic_cast<Reader*>(currentUser);
            	lib.showReaderBorrowedBooks(r);
            	pause();
				break;
			}
			case 4: {
                Reader* r = dynamic_cast<Reader*>(currentUser);

                lib.showReaderBorrowedBooks(r); 
                if (r->getBorrowedISBNs().empty()) {
                    pause();
                    break;
                }
                cout << "请输入要归还书籍的 ISBN: ";
                string isbn;
                cin >> isbn;

                if (lib.returnBook(r, isbn)) {
                    cout << "归还成功！欢迎再次借阅。" << endl;
                }
                pause();
                break;
            }
			case 5: 
			{
				currentUser->displayInfo();
				pause();
				userSettings(); 
				pause();
				break;
			}
			case 6:
				lib.showTopBorrowed();
				pause();
				break;
			case 7:
				lib.showLatestBooks();
				pause();
				break;
        }
    }
}

void Menu::searchMenu() {
    clearScreen();
    cout << "--- 图书搜索 ---" << endl;
    cout << "1. 按题名搜索\n2. 按ISBN搜索\n3. 按作者搜索\n请选择方式: ";
    int type; cin >> type;
    
    cout << "请输入关键字: ";
    string keyword;
    cin.ignore(); 
    getline(cin, keyword);

    vector<Book*> results = lib.searchBooks(keyword, type);

    if (results.empty()) {
        cout << "\n未找到相关书籍。" << endl;
    } else {
        cout << "\n共找到 " << results.size() << " 本相关书籍：" << endl;
        for (Book* b : results) {
            b->display();
        }
    }
    pause();
}

void Menu::adminoperate()
{
	int choice;
	while(true)
	{
		clearScreen();
		cout<<"------书籍信息管理------"<<endl;
		cout<<"1.增加书籍"<<endl;
		cout<<"2.删除书籍"<<endl;
		cout<<"3.改动书籍"<<endl;
		cout<<"4.查找书籍"<<endl; 
		cout<<"0.返回上级菜单"<<endl;
		cout<<"请输入选择："<<endl;
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				lib.addBook();
				pause();
				break;
			case 2:
				lib.deleteBook();
				pause();
				break;
			case 3:
                lib.modifyBook(); 
                pause();
                break;
			case 4: {
                int type;
                cout << "------ 查询书籍 ------" << endl;
                cout << "1. By 书名" << endl;
                cout << "2. By ISBN" << endl;
                cout << "3. By 作者" << endl;
                cout << "请输入查询途径: ";
                if (!(cin >> type)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "输入无效！" << endl;
                    pause();
                    break;
                }

                cout << "请输入关键词: ";
                string keyword;
                cin.ignore();
                getline(cin, keyword);
                vector<Book*> results = lib.searchBooks(keyword, type);
                if (results.empty()) {
                    cout << "\n未找到相关书籍。" << endl;
                } else {
                    cout << "\n共找到 " << results.size() << " 本相关书籍：" << endl;
                    for (Book* b : results) {
                        b->display();
                    }
                }
                
                pause();
                break;
            }
			case 0:
				return;
		 } 
	 } 
} 

/*
void Menu::borrowProcess() {
    clearScreen();
    cout << "--- 借阅图书 (第一步：搜索) ---" << endl;
    cout << "1. 按题名搜索 | 2. 按ISBN搜索 | 3. 按作者搜索" << endl;
    int type; cin >> type;
    
    cout << "请输入搜索关键字: ";
    string key;
    cin.ignore();
    getline(cin, key);

    vector<Book*> results = lib.searchBooks(key, type);

    if (results.empty()) 
	{
        cout << "未找到相关书籍，无法借阅。" << endl;
        pause();
        return;
    }

    cout << "\n搜索结果如下：" << endl;
    for (Book* b : results) {
        b->display(); 
    }

    cout << "\n请输入您要借阅书籍的完整 ISBN (输入 0 取消): ";
    string targetIsbn;
    cin >> targetIsbn;

    if (targetIsbn == "0") return;

    if (lib.borrowBookByISBN(currentUser, targetIsbn)) {
        cout << "借阅成功！书籍借阅次数已更新。" << endl;
    }
}
*/
// 请替换 Menu.cpp 中的 borrowProcess 函数
void Menu::borrowProcess() {
    clearScreen();
    cout << "--- 借阅图书 (第一步：搜索) ---" << endl;
    cout << "1. 按题名搜索 | 2. 按ISBN搜索 | 3. 按作者搜索" << endl;
    cout << "请输入搜索类型: ";

    int type; 
    // 【修改点1】健壮的输入检查
    // 如果 cin 读取 type 失败（比如用户输入了字母，或者乱按回车导致流错误）
    if (!(cin >> type)) {
        cin.clear(); // 1. 修复 cin 的错误状态
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 2. 清空缓冲区里的垃圾字符
        cout << "输入无效！借阅流程已中止。" << endl;
        return; // 直接退出函数，防止死循环
    }

    // 【修改点2】范围检查
    if (type < 1 || type > 3) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空可能多余的输入
        cout << "选择无效 (1-3)！" << endl;
        return;
    }
    
    // 【修改点3】清除缓冲区的一个换行符，为后面的 getline 做准备
    // 只有在输入流正常的情况下才执行这一步
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "请输入搜索关键字: ";
    string key;
    // 这里不需要再写 cin.ignore() 了，因为上面已经清理过了
    getline(cin, key);

    // 如果用户只敲了回车，key 是空的，拦截一下
    if (key.empty()) {
        cout << "关键字不能为空。" << endl;
        return;
    }

    vector<Book*> results = lib.searchBooks(key, type);

    if (results.empty()) {
        cout << "未找到相关书籍，无法借阅。" << endl;
        return;
    }

    cout << "\n搜索结果如下：" << endl;
    for (Book* b : results) {
        b->display(); 
    }

    cout << "\n请输入您要借阅书籍的完整 ISBN (输入 0 取消): ";
    string targetIsbn;
    cin >> targetIsbn;

    if (targetIsbn == "0") return;

    if (lib.borrowBookByISBN(currentUser, targetIsbn)) {
        cout << "借阅成功！书籍借阅次数已更新。" << endl;
    } else {
        cout << "借阅失败：未找到该 ISBN 或其他错误。" << endl;
    }
}
void Menu::userSettings() {
    clearScreen();
    cout << "--- 账号设置 ---" << endl;
    cout << "1. 修改密码" << endl;
    cout << "0. 返回" << endl;
    int choice; cin >> choice;

    if (choice == 1) {
        if (currentUser->changePassword()) {
            lib.saveUsersToFile("users_data.txt"); 
            cout << "设置已自动同步到本地存档。" << endl;
        }
        pause();
    }
}
