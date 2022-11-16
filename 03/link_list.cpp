#include <cstdlib>
#include <iostream>
typedef int ElemType;
using namespace std;
typedef struct Node {
  ElemType elem;
  struct Node *next;
} Node, *Link_List;

void init_list(Link_List &l) {  //建立一个首节点不为空的单链表
  l = new Node;
  l->next = nullptr;
}
void input_data(Link_List &p) { cin >> p->elem; }  //向数据域中输入数据
int get_length(Link_List p) {                      //取得链表的长度
  p = p->next;
  int length = 0;
  while (p) {
    length += 1;
    p = p->next;
  }
  return length;
}
void display_data(Link_List l) {  //打印链表中的所有数据
  if (!l->next) {
    return;
  }
  Link_List p = l;
  l = l->next;
  for (int i = 0; i < get_length(p); ++i) {
    cout << l->elem << " ";
    l = l->next;
  }
  cout << endl;
}

void push_back(Link_List &l, int n) {  //通过尾插法插入节点
  Link_List pr = l;
  while (pr->next) {
    pr = pr->next;
  }
  cout << "请输入要插入的数据，中间以空格分离" << endl;
  for (int i = 0; i < n; ++i) {
    Link_List p = new Node;
    input_data(p);
    pr->next = p;
    p->next = nullptr;
    pr = p;
  }
}
void search_by_index(Link_List &p, int i) {  //将链表遍历至需要找到的节点
  int count = 0;
  while (count != i) {
    p = p->next;
    count++;
  }
}
void search_by_value(Link_List l, ElemType e) {  //通过索引寻找到数据并打印
  if (!l->next) {
    cout << "请先录入数据" << endl;
  } else {
    Link_List p = l;
    l = l->next;
    for (int i = 0; i < get_length(p); ++i) {
      if (l->elem == e) {
        cout << "成功找到"
             << "索引为：" << i + 1 << "值为:" << l->elem << endl;
        return;
      }
      l = l->next;
    }
    cout << "未查找到该数据" << endl;
  }
}
int delete_data(Link_List &l, int i) {  //删除节点
  if (i <= 0 || i > get_length(l)) {
    cout << "请输入正确的删除索引" << endl;
    return 0;
  } else {
    Link_List pr = l;
    search_by_index(pr, i);
    Link_List p = pr->next;
    if (!p) {  //若末尾节点的前一个节点为空则重新遍历链表找到其前一个节点并删除
      pr = l;
      search_by_index(pr, i - 1);
      Link_List temp = pr->next;
      pr->next = nullptr;
      delete temp;
      return 1;
    } else {  //若末尾节点不为空则直接通过假删法删除
      pr->elem = p->elem;
      pr->next = p->next;
      delete p;
      return 1;
    }
  }
}
void insert_node(Link_List &l, int i) {
  if (i <= 0 || i > get_length(l)) {
    cout << "请输入正确的插入索引" << endl;
  } else {
    Link_List pr = l;
    search_by_index(pr, i);
    Link_List pt = pr->next;
    Link_List p = new Node;
    if (pt) {
      int temp = pr->elem;
      cout << "请输入要插入的数据" << endl;
      input_data(pr);
      pr->next =
          p;  //插入位置前后均不为空则将索引位置替换为新节点中的数据，将原节点的数据复制给新节点
      p->elem = temp;
      p->next = pt;
    } else {
      cout << "请输入要插入的数据" << endl;  //若末尾节点为空则直接插入新节点
      input_data(p);
      pr->next = p;
      p->next = nullptr;
    }
  }
}
void reverse(Link_List &l) {
  if (!l->next) {
    return;
  } else {
    Link_List head = l;
    Link_List p = l;
    p = p->next;
    head->next = nullptr;
    while (p) {
      Link_List q = p;
      p = p->next;
      q->next = head->next;
      head->next = q;
    }
    display_data(l);
  }
}
int main() {
  Link_List l = nullptr;
  init_list(l);
  bool flag = true;
  int option;
  while (flag) {
    cout << "1,录入数据" << endl
         << "2,打印链表" << endl
         << "3,删除数据" << endl
         << "4,查找数据" << endl
         << "5,插入数据" << endl
         << "6,链表反转" << endl
         << "7,退出" << endl
         << "请输入命令" << endl;
    cin >> option;
    switch (option) {
      case 1: {
        int n;
        cout << "请输入要添加的个数" << endl;
        cin >> n;
        push_back(l, n);
        break;
      }
      case 2:
        display_data(l);
        break;
      case 3: {
        int i, j;
        cout << "请输入要删除数据的索引" << endl;
        cin >> i;
        j = delete_data(l, i);
        if (j) cout << "删除成功" << endl;
        break;
      }
      case 4: {
        ElemType e;
        cout << "请输入要查找的数据" << endl;
        cin >> e;
        search_by_value(l, e);
        break;
      }
      case 5: {
        int i;
        cout << "请输入要插入的索引" << endl;
        cin >> i;
        insert_node(l, i);
        break;
      }
      case 6:
        reverse(l);
        break;
      case 7:
        flag = false;
        break;
      default:
        cout << "请输入正确的命令" << endl;
        break;
    }
  }
  return 0;
}