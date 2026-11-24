#include "Book.h"
#include <iostream>
#include <sstream>

using namespace std;


Book::Book(string t, string ISBN_val, string auth, string pub, double pr, string _pubDate)
    : title(t), isbn(ISBN_val), author(auth), publisher(pub), price(pr), borrowCount(0), publishDate(_pubDate)
{
    // 价格不能为负
    if (price < 0) {
        cerr << "书名《" << title << "》的价格输入非法，已重置为零" << endl;
        price = 0;
    }
    // 书名不能为空 
    if (title.empty()) {
        title = "未命名书籍";
    }
}

// 展示书籍信息 
void Book::display() const {
    cout << " | 【  书名  】: " << title<<endl 
         << " | 【  ISBN  】: " << isbn<<endl
         << " | 【  作者  】: " << author <<endl
         << " | 【 出版社 】: " << publisher <<endl
         << " | 【  价格  】: " << price <<endl
         << " | 【出版时间】: " << publishDate <<endl
         << " | 【借阅次数】: " << borrowCount <<endl << endl;
}

/*
 * 保存到文件
 * 使用 '|' 作为分隔符，防止书名中的空格破坏数据结构
 */
void Book::saveToFile(ostream& os) const {
    os << title << "|" 
       << isbn << "|" 
       << author << "|" 
       << publisher << "|"
	   << publishDate << "|" 
       << price << "|" 
       << borrowCount << endl;
}

/*
 * 从文件的一行中解析出 Book 对象
 */
Book* Book::loadFromFile(istream& is) {
    string line;
    if (getline(is, line) && !line.empty()) {
        stringstream ss(line);
        string t, i, a, p, pd, prStr, bcStr;

        if (getline(ss, t, '|') &&
            getline(ss, i, '|') &&
            getline(ss, a, '|') &&
            getline(ss, p, '|') &&
            getline(ss, pd, '|') &&
            getline(ss, prStr, '|') &&
            getline(ss, bcStr, '|')) 
		{
            
            try {
                double pr = stod(prStr);
                int bc = stoi(bcStr);
                
                Book* newBook = new Book(t, i, a, p, pr, pd);
                newBook->borrowCount = bc;
                return newBook;
            } catch (...) {
                return nullptr;
            }
        }
    }
    return nullptr;
}
