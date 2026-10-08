#include "book.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

//辅助函数，比较两个字符串是否相等 
bool compare(const char *a, const char *b){
	int i;
	int len = strlen(a);
	if (len == strlen(b)) {
		for (i = 0; i < len; i++){
			if (a[i] != b[i]){
			  return false;
				}
			}
		return true;
	}else{
		return false;
	}
}

//初始化链表 
void InitList(BookList *L){
 	L->head = new Book;       //创建头结点
    L->head->next = NULL;     //初始化头结点 
    L->count = 0;
 }

//尾插法添加图书，ISBN重复返回0，成功返回1 
int AddBook(BookList *L, Book b){
	if (FindByIsbn(L, b.isbn) != NULL) {       //判断图书是否已经存在 
		cout << "该图书已存在" << endl; 
		return 0;
	}
	Book *newnode = new Book;   //创建新结点存放要添加的图书 
	*newnode = b;
	newnode->next = NULL;
	
	Book *p = L->head;
	while (p->next != NULL) {
		p=p->next;             //遍历链表，找到尾结点 
	}
	p->next = newnode;         //尾部插入 
	L->count++; 
	return 1;
}

//按ISBN查书，返回结点指针，找不到返回NULL
Book* FindByIsbn(BookList *L, const char *isbn){
		Book *p = L->head->next;
		while (p != NULL) {
			if (compare(p->isbn, isbn)){       //遍历链表，调用compare函数比较ISBN是否相同 
				return p;
			}
			p = p->next;
		}
	    return NULL;
}

//按ISBN删除图书，未找到返回0，成功释放节点内存并返回1 
int DeleteBook(BookList *L, const char *isbn){
	Book *pre = L->head;                   
	Book *cur = pre->next;
	while (cur != NULL) {
		if (compare(cur->isbn, isbn)) {
			pre->next = cur->next;         //找到则断链 
			delete cur;
			L->count--;
			cout << "删除成功" << endl;
			return 1;
		} else {
			pre = pre->next;               //否则两个指针向后移一个单位  
			cur = cur->next;
			}
    }
	cout << "未找到" << endl; 
	return 0;
}
				
//以表格形式输出所有图书信息
void ShowAll(BookList *L){
	 cout << left << setw(20) << "ISBN"
         << setw(20) << "书名"
         << setw(20) << "作者"
         << setw(20) << "价格"
         << setw(20) << "库存" << endl;

    Book *p = L->head->next;
    while (p != NULL) {
        cout << left << setw(20) << p->isbn          //按格式输出信息，用setw固定宽度 
             << setw(20) << p->title
             << setw(20) << p->author
             << setw(20) << fixed << setprecision(2) << p->price
             << setw(20) << p->stock << endl;
        p = p->next;
    }
}

//销毁链表，释放节点内存 
void DestroyList(BookList *L){
	Book *p = L->head;
	while (p != NULL) {
	Book *temp = p;           //临时结点指针保存要删除结点指针 
	p = p->next;
	delete temp;
	}
	L->head = NULL;
	L->count = 0;            //count清零 
}

//统计图书总数，总库存，总价值 
void Statistics(BookList *L) {
    int totalStock = 0;
    double totalValue = 0;
    Book *p = L->head->next;
    while (p != NULL) {
        totalStock += p->stock;                     //遍历链表，计算加和 
        totalValue += p->price *p->stock;
        p = p->next;
    }
    cout << "总数：" << L->count << endl;           //输出结果 
    cout << "总库存：" << totalStock << endl;
    cout << "总价值：" << fixed << setprecision(2) << totalValue << endl;
}

