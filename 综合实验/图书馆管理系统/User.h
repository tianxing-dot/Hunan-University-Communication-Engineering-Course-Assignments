#ifndef USER_H
#define USER_H
#include <vector>
#include <string>
#include <iostream>

class User {
protected:
    std::string account;
    std::string password;
    int role;
    int borrowCount;
	std::vector<std::string> borrowedISBNs;
public:
    User(std::string acc, std::string pwd, int r,int b) : account(acc), password(pwd), role(r), borrowCount(0) {}
    virtual ~User() {}

	virtual void save(std::ostream& os) const {
    	os << account << "|" << password << "|" << role << "|" << borrowCount << "|";
	}
    
    virtual void displayInfo() const {
        std::cout << "========= 个人信息 =========" << std::endl;
        std::cout << "账号: " << account << std::endl;
        std::cout << "身份: " << (role == 1 ? "管理员" : "读者") << std::endl;
    }
    
	bool authenticate(std::string acc, std::string pwd) { return account == acc && password == pwd; }
    
	std::string getAccount() const { return account; }
	std::string getPassword() const { return password; }
    int getRole() const { return role; }
    void setPassword(std::string pwd) { password = pwd; }
    int getBorrowCount() const {return borrowCount;}
    
    virtual void showMenu() = 0;
    
    bool changePassword() {
    std::string oldPwd, newPwd;
    std::cout << "请输入旧密码: ";
    std::cin >> oldPwd;
    if (oldPwd == this->password) {
        std::cout << "请输入新密码: ";
        std::cin >> newPwd;
        this->password = newPwd;
        std::cout << "密码修改成功!" << std::endl;
        return true;
    } else {
        std::cout << "旧密码错误，请重新输入" << std::endl;
        return false;
    }
}
}; 


class Admin : public User {
public:
    Admin(std::string acc, std::string pwd) : User(acc, pwd, 1, 0) {}
    void showMenu() override {
        std::cout << "\n--- 管理员菜单 ---\n1. 读者管理\n2. 书籍管理\n0. 退出\n选择: ";
    }
    void save(std::ostream& os) const override {
        // 格式：账号|密码|角色|借阅数|
        os << account << "|" << password << "|" << role << "|0|" << std::endl;
    }
	
	void displayInfo() const override {
        User::displayInfo();
        std::cout << "权限: 系统全权限管理" << std::endl;
        std::cout << "============================" << std::endl;
    }
    
};

class Reader : public User {
private:
	std::vector<std::string> borrowedISBNs; 
public:
    Reader(std::string acc, std::string pwd) : User(acc, pwd, 2, 0) {}
    void showMenu() override {
        std::cout << "\n--- 读者菜单 ---\n1. 搜索图书\n2. 借阅图书\n3. 归还图书\n0. 退出\n选择: ";
    }
    void setBorrowCount(int count) {
        	borrowCount = count;
    	}
    void addBorrowCount()
    {
    	this->borrowCount++; 
	}
    void save(std::ostream& os) const override {
    	os << account << "|" << password << "|" << role << "|" << borrowCount << "|";
    	for (size_t i = 0; i < borrowedISBNs.size(); ++i) {
        	os << borrowedISBNs[i] << (i == borrowedISBNs.size() - 1 ? "" : ",");
    	}
    	os << std::endl;
	}
	
	void addBorrowedBook(std::string isbn) { borrowedISBNs.push_back(isbn); }
	const std::vector<std::string>& getBorrowedISBNs() const { return borrowedISBNs; }
	int getBorrowCount() const {return borrowCount;}
	void displayInfo() const override {
        User::displayInfo();
        std::cout << "累计借书总数: " << borrowCount << " 本" << std::endl;
        std::cout << "============================" << std::endl;
    }
    
	void returnBook(const std::string& isbn) {
    	for (auto it = borrowedISBNs.begin(); it != borrowedISBNs.end(); ++it) {
        	if (*it == isbn) {
            	borrowedISBNs.erase(it);
            	break;
        	}
    	}
	}	
};

#endif
