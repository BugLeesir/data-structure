#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct pNode {
  float coef;  //系数
  int expn;    //指数
  struct pNode *next;
} pNode, *polynomial;
void CreatePolyn(polynomial &p, int n) {
  p = new pNode;  //空表初始化
  p->next = nullptr;//建立一个带头节点的单链表
  for (int i = 0; i < n; ++i) {
    polynomial s = new pNode;  //依次输入n项
    cout << "请输入系数与指数，中间以空格分割" << endl;
    cin >> s->coef >> s->expn;
    polynomial pre = p;
    polynomial q = p->next;
    while (q && q->expn < s->expn) {  //通过比较找到第一个指数大于s的项q
      pre = q;
      q = q->next;
    }
    s->next = q;  //将s插入pre和q中间
    pre->next = s;
  }
}
void AddPolyn(polynomial &pa, polynomial &pb) {
  polynomial p1 = pa->next;
  polynomial p2 = pb->next;                       
  polynomial p3 = pa;
  polynomial r = nullptr;
  while (p1 && p2) {
    if (p1->expn == p2->expn) {//指数相等
      float sum = p1->coef + p2->coef;//sum保存为两系数和
      if (sum) {
        p1->coef = sum;
        p3->next = p1;
        p3 = p1;
        p1 = p1->next;
        r = p2;
        p2 = p2->next;
        delete r;//删除指向的当前节点释放内存
      } else {
        r = p1;
        p1 = p1->next;
        delete r;
        r = p2;
        p2 = p2->next;
        delete r;
      }
    } else if (p1->expn < p2->expn) {//pa当前节点的指数值小
      p3->next = p1;
      p3 = p1;
      p1 = p1->next;
    } else {//pb当前节点的指数值小
      p3->next = p2;
      p3 = p2;
      p2 = p2->next;
    }
  }
  p3->next = p1 ? p1 : p2;//使用三元运算符插入非空项的剩余段
  delete pb;
}
void Display(polynomial p) {                //打印多项式
  if (!p->next) {
    cout << "请先录入数据" << endl;
    return;
  } else {
    p=p->next;
    while (p) {
      cout << "系数:" << p->coef << " "
           << "指数：" << p->expn << endl;
           p=p->next;
    }
  }
}
int main() {
  polynomial p1, p2 = nullptr;
  cout<<"创建第一个节点"<<endl;
  CreatePolyn(p1, 2);
  cout<<"创建第二个节点"<<endl;
  CreatePolyn(p2, 2);
  AddPolyn(p1, p2);                       //合并多项式
  Display(p1);                            //打印最终合并的多项式
  system("pause");
}
