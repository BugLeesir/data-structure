//顺序表基本运算算法
#include <iostream>
#define MaxSize 50
using namespace std;
typedef int ElemType;
typedef struct List {
  ElemType data[MaxSize];  //存放顺序表元素
  int length;              //存放顺序表的长度
} List, *SqList;           //顺序表的类型
SqList CreateList(ElemType a[], int n)
//建立顺序表
{
  SqList L = new List;
  for (int i = 0; i < n; i++) L->data[i] = a[i];
  L->length = n;
  return L;
}
void DestroyList(SqList L) { delete L; }  //释放内存
void DispList(SqList L) {
  for (int i = 0; i < L->length; i++) cout << L->data[i] << " ";
  cout << endl;
}
void Revese(SqList L) {
  typedef struct StackNode {//使用栈结构进行反转
    ElemType data;
    struct StackNode *next;
  } StackNode, *LinkStack;
  LinkStack temp = nullptr;
  for (int i = 0; i < L->length; ++i) {//入栈
    LinkStack p = new StackNode;
    p->data = L->data[i];
    p->next = temp;
    temp = p;
  }
  for (int i = 0; i < L->length; ++i) {//出栈
    L->data[i] = temp->data;
    LinkStack p = temp;
    temp = temp->next;
    delete p;
  }
}
bool GetElem(SqList L, int i, ElemType &e) {  //取得所找元素
  if (i < 1 || i > L->length) return false;
  e = L->data[i - 1];
  return true;
}
int LocateElem(SqList L, ElemType e) {  //取得所找元素的下标
  int i = 0;
  while (i < L->length && L->data[i] != e) i++;
  if (i >= L->length)
    return 0;
  else
    return i + 1;
}
bool ListInsert(SqList L, int i, ElemType e) {
  int j;
  if (i < 1 || i > L->length + 1) return false;
  i--;                             //将顺序表位序转化为elem下标
  for (j = L->length; j > i; j--)  //将data[i]及后面元素后移一个位置
    L->data[j] = L->data[j - 1];
  L->data[i] = e;
  L->length++;  //顺序表长度增1
  return true;
}
bool ListDelete(SqList L, int i, ElemType &e) {
  int j;
  if (i < 1 || i > L->length) return false;
  i--;  //将顺序表位序转化为elem下标
  e = L->data[i];
  for (j = i; j < L->length - 1; j++)  //将data[i]之后的元素前移一个位置
    L->data[j] = L->data[j + 1];
  L->length--;  //顺序表长度减1
  return true;
}
int main() {
  bool flag = true;
  int option;
  SqList L = nullptr;
  while (flag) {  //创建菜单
    cout << "1,创建顺序表" << endl
         << "2,顺序表插入" << endl
         << "3,顺序表删除" << endl
         << "4,顺序表的查找" << endl
         << "5,顺序表反转" << endl
         << "6,退出" << endl
         << "请输入命令";
    cin >> option;
    switch (option) {
      case 1: {
        int n;
        cout << "请输入您要输入数据的个数" << endl;
        cin >> n;
        ElemType a[n];
        for (int i = 0; i < n; ++i) {
          cout << "请输入第" << i + 1 << "个数" << endl;
          cin >> a[i];
        }
        L = CreateList(a, n);
        break;
      }
      case 2: {
        if (!L) {
          cout << "请先录入数据" << endl;
        } else {
          ElemType e;
          int i;
          cout << "请输入插入的数据" << endl;
          cin >> e;
          cout << "请输入插入位置" << endl;
          cin >> i;
          if (ListInsert(L, i, e)) {
            cout << "插入成功" << endl;
            DispList(L);
          } else {
            cout << "插入失败<<endl";
          }
        }
        break;
      }
      case 3: {
        if (!L) {
          cout << "请先录入数据" << endl;
        } else {
          int et;
          ElemType &e = et;
          int i;
          cout << "请输入要删除的位置" << endl;
          cin >> i;
          if (ListDelete(L, i, e)) {
            cout << "删除成功，删除的是" << e << endl;
            DispList(L);
          } else {
            cout << "删除失败" << endl;
          }
        }
        break;
      }
      case 4: {
        if (!L) {
          cout << "请先录入数据" << endl;
        } else {
          int et;
          ElemType &e = et;
          int location;
          cout << "请输入要查找的数据" << endl;
          cin >> e;
          location = LocateElem(L, e);
          if (location) {
            GetElem(L, location, e);
            cout << "成功找到，该元素是第" << location << "个元素,值为" << e
                 << endl;
          } else {
            cout << "未找到该元素" << endl;
          }
        }
        break;
      }
      case 5:
        if (!L) {
          cout << "请先录入数据" << endl;
        } else {
          Revese(L);
          DispList(L);
        }
        break;
      case 6:
        DestroyList(L);
        flag = false;
        break;
      default:
        cout << "命令错误" << endl;
        break;
    }
  }
  return 0;
}