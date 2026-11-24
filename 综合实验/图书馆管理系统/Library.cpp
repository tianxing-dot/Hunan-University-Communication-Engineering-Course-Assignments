#include "Library.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;
// 构造函数
Library::Library() {}

// 析构函数
Library::~Library() {
	//释放book容器内存 
    for (Book* b : inventory) {
        delete b;
    }
    inventory.clear();
    //释放user容器内存 
    for (User* u : users) {
        delete u;
    }
    users.clear();
}

//根据 ISBN 查找索引
int Library::findBookIndex(const string& isbn) const {
    for (int i = 0; i < inventory.size(); ++i) {
        if (inventory[i]->getISBN() == isbn) {
            return i;
        }
    }
    return -1;
}


// 添加书籍
void Library::addBook() {
    string t, i, a, p, pd;
    double pr;

    cout << "--- 添加新书 ---" << endl;
    cout << "请输入书名: ";
    cin.ignore();
    getline(cin, t);
    
    cout << "请输入ISBN: ";
    getline(cin, i);
    
    for (Book* b : inventory) {
        if (b->getISBN() == i) {
            cout << "错误：该ISBN已存在，请勿重复添加！" << endl;
            return;
        }
    }

    cout << "请输入作者: ";
    getline(cin, a);
    
    cout << "请输入出版社: ";
    getline(cin, p);
    
    cout << "请输入出版时间：";
    getline(cin, pd);
    
    cout << "请输入价格: ";
    cin >> pr;
	
    Book* newBook = new Book(t, i, a, p, pr, pd);
    inventory.push_back(newBook);
    saveToFile("books_data.txt"); 

    cout << "书籍添加成功！" << endl;
}


// 删除书籍
void Library::deleteBook() {
    string targetIsbn;
    cout << "请输入要删除书籍的 ISBN: ";
    cin >> targetIsbn;

    bool found = false;
    for (auto it = inventory.begin(); it != inventory.end(); ) {
        if ((*it)->getISBN() == targetIsbn) {
            delete *it; 
            it = inventory.erase(it); 
            found = true;
            cout << "书籍删除成功！" << endl;
            break; 
        } else {
            ++it;
        }
    }

    if (!found) {
        cout << "未找到 ISBN 为 " << targetIsbn << " 的书籍。" << endl;
        return;
    }

    saveToFile("books_data.txt"); 
}


// ISBN 搜索
Book* Library::searchByISBN(const std::string& isbn) const {
    int index = findBookIndex(isbn);
    if (index != -1) {
        return inventory[index];
    }
    return nullptr;
}


// 显示所有图书
void Library::showAllBooks() const {
    if (inventory.empty()) {
        cout << "图书馆目前没有馆藏。" << endl;
        return;
    }
    for (const auto& b : inventory) {
        b->display();
    }
}


// 保存到文件
void Library::saveToFile(const string& filename) const {
    ofstream ofs(filename);
    if (!ofs) {
        cerr << "错误：无法打开文件 " << filename << " 进行写入。" << endl;
        return;
    }
    for (const auto& b : inventory) {
        b->saveToFile(ofs);
    }
    ofs.close();
    cout << "书籍数据已成功保存至 " << filename << std::endl;
}


// 从文件加载
void Library::loadFromFile(const string& filename) {

    ifstream ifs(filename);

    if (!ifs) {
        cout << "未发现存档文件，将创建新数据库。" << endl;
        return;
    }
    for (Book* b : inventory) delete b;
    inventory.clear();
    while (true) {
        Book* b = Book::loadFromFile(ifs);
        if (b == nullptr) break;
        inventory.push_back(b);
    }
    ifs.close();
    cout << "成功加载 " << inventory.size() << " 本图书信息 ";
}


// 排行榜：借阅次数前十
void Library::showTopBorrowed() const {
    if (inventory.empty()) {
        cout << "图书馆目前没有馆藏。" << endl;
        return;
    }
    vector<Book*> temp = inventory;
    sort(temp.begin(), temp.end(), [](Book* a, Book* b) {
        return a->getBorrowCount() > b->getBorrowCount();
    });
    cout << "--- 借阅排行榜（前10） ---" << endl;
    int limit = min((int)temp.size(), 10);
    for (int i = 0; i < limit; ++i) {
        cout << i + 1 << ". ";
        temp[i]->display();
    }
}

//重置读者密码 
void Library::resetReaderPassword() {
	string account;
	cout<<"输入要重置的读者用户名："<<endl;
	cin>>account;
    for (User* u : users) {
        if (u->getAccount() == account && u->getRole() == 2) { 
            u->setPassword("123456"); // 
            std::cout << "用户 " << account << " 的密码已重置为 123456。" << std::endl;
            return;
        }
    }
    cout << "未找到该读者账号！" << std::endl;
}

// 从任意信息搜索图书 
std::vector<Book*> Library::searchBooks(const std::string& keyword, int type) const {
    std::vector<Book*> results;

    for (Book* b : inventory) {
        bool match = false;
        if (type == 1 && b->getTitle() == keyword) match = true;      // 题名精确匹配
        else if (type == 2 && b->getISBN() == keyword) match = true; // ISBN精确匹配
        else if (type == 3 && b->getAuthor() == keyword) match = true; // 作者匹配

        if (match) {
            results.push_back(b);
        }
    }

    if (type == 3 && !results.empty()) {
        std::sort(results.begin(), results.end(), [](Book* a, Book* b) {
            return a->getTitle() < b->getTitle(); // 字典序升序
        });
    }

    return results;
}

// 保存用户信息 
void Library::saveUsersToFile(const std::string& filename) const 
	{
    	std::ofstream ofs(filename);
    	if (!ofs) 
		{
        	std::cerr << "错误：无法创建用户数据文件！" << std::endl;
        	return;
    	}

    for (User* u : users) 
	{
        u->save(ofs);
        ofs << "\n";
    } 
    ofs.close();
    std::cout << "用户信息已成功备份。" << std::endl;
}

// 加载用户信息 
void Library::loadUsersFromFile(const string& filename) {
    ifstream ifs(filename);
    if (!ifs) return;

    string line;
    while (getline(ifs, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string acc, pwd, rStr, bCountStr;
        
        getline(ss, acc, '|');
        getline(ss, pwd, '|');
        getline(ss, rStr, '|');
        getline(ss, bCountStr, '|');

        if (rStr == "1") { // 管理员
            users.push_back(new Admin(acc, pwd));
        } else if (rStr == "2") { // 读者
            Reader* r = new Reader(acc, pwd);
            r->setBorrowCount(stoi(bCountStr));
            users.push_back(r);
        }
    }
    ifs.close();
}

// 读者注册 
bool Library::registerUser(string acc, string pwd, int role) 
{
    for (User* u : users) 
	{
        if (u->getAccount() == acc) 
		{
            cout << "错误：该用户名已被注册！" << endl;
            return false;
        }
    }

    User* newUser = nullptr;
    if (role == 1) newUser = new Admin(acc, pwd);
    else newUser = new Reader(acc, pwd);

    users.push_back(newUser); 

    saveUsersToFile("users_data.txt"); 
    return true;
}

// 登录 
User* Library::login(string acc, string pwd) 
{
    for (User* u : users) 
	{
        if (u->getAccount() == acc && u->getPassword() == pwd) 
		{
            return u;
        }
    }
    return nullptr;
}

//通过 ISBN 借书 
bool Library::borrowBookByISBN(User* user, const string& isbn) {
    int index = findBookIndex(isbn);
    if (index == -1) return false;

    inventory[index]->addBorrow(); 
    
    if (user->getRole() == 2) {
        Reader* r = dynamic_cast<Reader*>(user);
        r->addBorrowCount();
        r->addBorrowedBook(isbn);
    }

    saveToFile("books_data.txt"); 
    saveUsersToFile("users_data.txt");
    return true;
}

// 展示借阅记录 
void Library::showReaderBorrowedBooks(Reader* reader) const {
    const auto& isbns = reader->getBorrowedISBNs();
    
    if (isbns.empty()) {
        cout << "您当前没有任何借阅记录。" << endl;
        return;
    }

    cout << "--- 您当前借阅的书籍 ---" << endl;
    for (const string& isbn : isbns) {
        int index = findBookIndex(isbn);
        if (index != -1) {
            inventory[index]->display();
        }
    }
}

// 还书 
bool Library::returnBook(Reader* reader, const string& isbn) {
    bool hasBorrowed = false;
    const auto& list = reader->getBorrowedISBNs();
    for (const string& id : list) {
        if (id == isbn) {
            hasBorrowed = true;
            break;
        }
    }

    if (!hasBorrowed) {
        cout << "错误：您的借阅列表中没有这本书！" << endl;
        return false;
    }

    reader->returnBook(isbn);

    saveUsersToFile("users_data.txt");

    return true;
}


// 排行榜：最晚出版的书籍 
void Library::showLatestBooks() const {
    vector<Book*> temp = inventory;
    sort(temp.begin(), temp.end(), [](Book* a, Book* b) {
        return a->getPublishDate() > b->getPublishDate();
    });
    
    cout << "--- 最新出版前十 ---" << endl;
    for (int i = 0; i < min((int)temp.size(), 10); ++i) {
        temp[i]->display();
    }
}

// 显示所有读者
void Library::showAllReaders() const {
    cout << "--- 读者列表 ---" << endl;
    for (User* u : users) {
        if (u->getRole() == 2) {
            cout << "账号: " << u->getAccount() << " | 借阅总数: " << u->getBorrowCount() << endl;
        }
    }
}


// 删除读者
void Library::deleteReader() {
    string acc;
    cout << "请输入要删除的读者账号: ";
    cin >> acc;
    for (auto it = users.begin(); it != users.end(); ++it) {
        if ((*it)->getAccount() == acc && (*it)->getRole() == 2) {
            delete *it;
            users.erase(it);
            saveUsersToFile("users_data.txt");
            cout << "读者账号已成功删除。" << endl;
            return;
        }
    }
    cout << "删除失败：未找到该账号。" << endl;
}

// 更改书籍信息 
void Library::modifyBook() {
    cout << "--- 修改书籍信息 ---" << endl;
    cout << "请输入要修改书籍的 ISBN: ";
    string isbn;
    cin >> isbn;

    Book* bookToModify = searchByISBN(isbn);

    if (bookToModify == nullptr) {
        cout << "错误：未找到 ISBN 为 " << isbn << " 的书籍。" << endl;
        return;
    }

    cout << "当前书籍信息：" << endl;
    bookToModify->display();

    while (true) {
        cout << "\n--- 请选择要修改的项目 ---" << endl;
        cout << "1. 修改书名" << endl;
        cout << "2. 修改作者" << endl;
        cout << "3. 修改出版社" << endl;
        cout << "4. 修改出版时间" << endl;
        cout << "5. 修改价格" << endl;
        cout << "0. 完成修改并保存" << endl;
        cout << "选择: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 0) break;

        string tempStr;
        double tempPrice;

        switch (choice) {
            case 1:
                cout << "请输入新书名: ";
                cin.ignore();
                getline(cin, tempStr);
                bookToModify->setTitle(tempStr);
                cout << "书名已更新！" << endl;
                break;
            case 2:
                cout << "请输入新作者: ";
                cin.ignore();
                getline(cin, tempStr);
                bookToModify->setAuthor(tempStr);
                cout << "作者已更新！" << endl;
                break;
            case 3:
                cout << "请输入新出版社: ";
                cin.ignore();
                getline(cin, tempStr);
                bookToModify->setPublisher(tempStr);
                cout << "出版社已更新！" << endl;
                break;
            case 4:
                cout << "请输入新出版时间: ";
                cin.ignore();
                getline(cin, tempStr);
                bookToModify->setPublishDate(tempStr);
                cout << "出版时间已更新！" << endl;
                break;
            case 5:
                cout << "请输入新价格: ";
                cin >> tempPrice;
                if(tempPrice < 0) {
                    cout << "价格不能为负数！" << endl;
                } else {
                    bookToModify->setPrice(tempPrice);
                    cout << "价格已更新！" << endl;
                }
                break;
            default:
                cout << "无效选择。" << endl;
        }
    }

    saveToFile("books_data.txt");
    cout << "所有修改已保存到数据库。" << endl;
}
