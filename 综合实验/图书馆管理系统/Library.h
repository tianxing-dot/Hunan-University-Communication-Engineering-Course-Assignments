#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Book.h"
#include "User.h"

class Library {
private:
    std::vector<Book*> inventory;
    std::vector<User*> users; 

public:
    Library();
    ~Library();
    
    int findBookIndex(const std::string& isbn) const;
    void addBook();
    void showAllBooks() const;
    void showTopBorrowed() const;
    void deleteBook(); 
    void resetReaderPassword();
    Book* searchByISBN(const std::string& isbn) const;
    std::vector<Book*> searchBooks(const std::string& keyword, int type) const;
    
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    
    void saveUsersToFile(const std::string& filename) const;
    void loadUsersFromFile(const std::string& filename);
	bool registerUser(std::string acc, std::string pwd, int role);
	User* login(std::string acc, std::string pwd);
	
	bool borrowBookByISBN(User* user, const std::string& isbn);
	void showReaderBorrowedBooks(Reader* reader) const;

    
    void modifyBook(); // 改：修改书籍信息
	
	bool returnBook(Reader* reader, const std::string& isbn);
	
	void showLatestBooks() const;
	
	void showAllReaders() const;          // 查：显示所有读者
	void deleteReader();                  // 删：删除读者账号
	void modifyReader();                  // 改：修改读者账号或角色
};

#endif
