#include "Library.h"
#include "Menu.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    system("chcp 65001");
    system("cls"); 

    Library myLibrary;
    //读取文件 
    myLibrary.loadUsersFromFile("users_data.txt");
    myLibrary.loadFromFile("books_data.txt");

    Menu systemMenu(myLibrary);
    
    try {
        systemMenu.run();
    } catch (...) {
        cout << "发生未知错误，系统即将关闭。" << endl;
    }

    // 退出前保存数据
    myLibrary.saveToFile("books_data.txt");
    myLibrary.saveUsersToFile("users_data.txt");
    return 0;
}
