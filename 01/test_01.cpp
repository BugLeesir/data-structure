#include <iostream>
#include <string>
#define MAX_SUBJECT 4
using namespace std;
typedef struct Link_List {//创建链表
  long id;
  string name;
  int score[MAX_SUBJECT];
  Link_List *next;
} Link_List;
void input_data(Link_List *);//函数原型声明
Link_List *create_student(int, Link_List *);
void find_no_pass(Link_List *);
void find_excellent_student(Link_List *);
int main() {
  Link_List *head = nullptr;
  int option;
  bool flag = true;
  while (flag) {
    cout << "1,录入学生信息 " << endl
         << "2,找到不及格者" << endl
         << "3,找到平均分90分以上的人" << endl
         << "4,退出" << endl
         << "请输入命令";
    cin >> option;
    switch (option) {//switch语句打印菜单
      case 1:
        int student_number;
        cout << "请输入要录入的人数" << endl;
        cin >> student_number;
        head = create_student(student_number, head);
        break;
      case 2:
        find_no_pass(head);
        break;
      case 3:
        find_excellent_student(head);
        break;
      case 4:
        flag = false;
        break;
      default:
        cout << "输入错误" << endl;
        break;
    }
  }

  return 0;
}
void input_data(Link_List *node) {//对数据进行输入
  cout << "请输入姓名" << endl;
  cin >> node->name;
  cout << "请输入学号" << endl;
  cin >> node->id;
  cout << "请依次输入四科成绩，以空格分割" << endl;
  cin >> node->score[0] >> node->score[1] >> node->score[2] >> node->score[3];
}
Link_List *create_student(int student_number, Link_List *head) {//向链表后端添加节点
  Link_List *p = head;
  for (int i = 0; i < student_number; ++i) {
    if (!head) {
      head = new Link_List;//对空头进行另外处理
      head->next = nullptr;
      p = head;
      input_data(head);
    } else {
      Link_List *pr = new Link_List;
      p->next = pr;//尾插法加入节点
      pr->next = nullptr;
      input_data(pr);
      p = pr;
    }
  }
  return head;
}
void find_no_pass(Link_List *head) {//找到不及格的学生
  Link_List *p = head;
  if (!p) {
    cout << "尚未录入信息" << endl;
    return;
  } else {
    while (p) {
      if (p->score[0] < 60 || p->score[1] < 60 || p->score[2] < 60 ||
          p->score[3] < 60) {
        cout << p->name << "没及格" << endl;
      }
      p = p->next;
    }
  }
}
void find_excellent_student(Link_List *head) {//找到平均分90以上的学生
  Link_List *p = head;
  if (!p) {
    cout << "尚未录入信息" << endl;
    return;
  } else {
    while (p) {
      if ((p->score[0] + p->score[1] + p->score[2] + p->score[3]) / 4.0 >= 90) {
        cout << p->name << "平均分在90以上" << endl;
      }
      p = p->next;
    }
  }
}
