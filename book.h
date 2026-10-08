#ifndef BOOK_H
#define BOOK_H

#define MAX_ISBN 100
#define MAX_TITLE 100
#define MAX_AUTHOR 100

typedef struct node{ // 单个图书结点
char isbn[MAX_ISBN];
char title[MAX_TITLE];
char author[MAX_AUTHOR];
float price;
int stock;
struct node *next;
}Book;

typedef struct { // 图书链表
Book *head; // 头结点，不存数据
int count; // 图书总数
} BookList;

void InitList(BookList *L);  //初始化链表 

int AddBook(BookList *L, Book b); //尾插法添加图书，ISBN重复返回0，成功返回1 

Book* FindByIsbn(BookList *L, const char *isbn); //按ISBN查书，返回结点指针，找不到返回NULL 

int DeleteBook(BookList *L, const char *isbn); //按ISBN删除图书，未找到返回0，成功释放节点内存并返回1 

void ShowAll(BookList *L); //以表格形式输出所有图书信息

void DestroyList(BookList *L); //销毁链表，释放节点内存 

void Statistics(BookList *L); //统计图书总数，总库存，总价值 

#endif
