#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book {
private:
    // 成员变量
    std::string title;      // 题名
    std::string isbn;       // ISBN
    std::string author;     // 作者
    std::string publisher;  // 出版社
    double price;           // 价格
    int borrowCount;        // 借阅次数 
	std::string publishDate;
	
public:
    // 构造函数
    Book(std::string _title, std::string _isbn, std::string _author, std::string _publisher, double _price, std::string _publishDate);

    // 析构函数
    virtual ~Book() {}

    // Getter 函数
    std::string getTitle() const { return title; }
    std::string getISBN() const { return isbn; }
    std::string getAuthor() const { return author; }
    double getPrice() const { return price; }
    int getBorrowCount() const { return borrowCount; }
	std::string getPublishDate() const { return publishDate; }
	
    // 借书业务
    void addBorrow() { borrowCount++; }
    void addBorrowCount() { borrowCount++; }
    
    // 显示函数
    void display() const;
    
	// setter 函数 
    void setTitle(std::string t) { title = t; }
    void setAuthor(std::string a) { author = a; }
    void setPublisher(std::string p) { publisher = p; }
    void setPublishDate(std::string d) { publishDate = d; }
    void setPrice(double p) { price = p; }

	// 保存与加载 
    void saveToFile(std::ostream& os) const;
    static Book* loadFromFile(std::istream& is);
};

#endif
