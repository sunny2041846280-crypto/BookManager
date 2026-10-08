#include <iostream>
#include<iomanip> 
#include "book.h"

using namespace std;

int main() {
	BookList L;
    InitList(&L);    //初始化链表 

        //菜单显示    
        cout << "========= 图书管理系统 =========" << endl;
        cout << "1. 添加图书" << endl;
        cout << "2. 查找图书（按ISBN）" << endl;
        cout << "3. 删除图书" << endl;
        cout << "4. 显示全部图书" << endl;
        cout << "5. 修改图书信息" << endl;
        cout << "6. 按书名模糊查找" << endl;
        cout << "7. 按价格排序" << endl;
        cout << "8. 统计信息" << endl;
        cout << "9. 保存到文件" << endl;
        cout << "0. 退出系统" << endl;
        cout << "===============================" << endl;
        
    int choice;
    while (true) {
        cout << "请输入你的选择：";
        cin >> choice;

        if (choice == 0) break;                  //输入0则退出系统 

        switch (choice) {
            case 1: {
                Book b;
                cout << "请输入图书信息（格式：ISBN,书名,作者,价格,库存）：" << endl;
                char c;
                int i;
                
                // 逐字符读取 ISBN，直到遇到逗号
                for (i = 0; i < MAX_ISBN - 1; i++) {
                    cin >> c;
                    if (c == ',') break;
                    b.isbn[i] = c;
                }
                b.isbn[i] = '\0';
                
                 // 逐字符读取书名，直到遇到逗号
                for (i = 0; i < MAX_TITLE - 1; i++) {
                    cin >> c;
                    if (c == ',') break;
                    b.title[i] = c;
                }
                b.title[i] = '\0';
                
                // 逐字符读取作者，直到遇到逗号
                for (i = 0; i < MAX_AUTHOR - 1; i++) {
                    cin >> c;
                    if (c == ',') break;
                    b.author[i] = c;
                }
                b.author[i] = '\0';
                
                cin >> b.price;
                cin >> c;          //跳过价格后面的逗号 
                cin >> b.stock;
                b.next = NULL;
                
                
                AddBook(&L, b);    //调用函数添加图书 
                break;
            }
            case 2: {
                char isbn[MAX_ISBN];
                cout << "请输入要查找的ISBN：";
                cin >> isbn;
                
                Book *p = FindByIsbn(&L, isbn);       //查找结点 
                if (p != NULL) {
                    //找到，输出完整信息 
                    cout << "ISBN：" << p->isbn << endl;
                    cout << "书名：" << p->title << endl;
                    cout << "作者：" << p->author << endl;
                    cout << "价格：" << fixed << setprecision(2) << p->price << endl;
                    cout << "库存：" << p->stock << endl;
                } else {
                    cout << "该书不存在" << endl;
                }
                break;
            }
            case 3: {
                char isbn[MAX_ISBN];
                cout << "请输入要删除的ISBN：";
                cin >> isbn;
                DeleteBook(&L, isbn);       //调用删除函数 
                break;
            }
            case 4:
                ShowAll(&L);               //显示全部图书 
                break;
            case 8:
                Statistics(&L);           //执行统计功能 
                break;
            default:                      
                cout << "无效选择，请重新输入。" << endl;
        }
    }

    DestroyList(&L);                     //退出程序前销毁链表，释放所有结点内存 
    return 0;
}
