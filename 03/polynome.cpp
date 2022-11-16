#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct pNode {
  float coef;  //ϵ��
  int expn;    //ָ��
  struct pNode *next;
} pNode, *polynomial;
void CreatePolyn(polynomial &p, int n) {
  p = new pNode;  //�ձ��ʼ��
  p->next = nullptr;//����һ����ͷ�ڵ�ĵ�����
  for (int i = 0; i < n; ++i) {
    polynomial s = new pNode;  //��������n��
    cout << "������ϵ����ָ�����м��Կո�ָ�" << endl;
    cin >> s->coef >> s->expn;
    polynomial pre = p;
    polynomial q = p->next;
    while (q && q->expn < s->expn) {  //ͨ���Ƚ��ҵ���һ��ָ������s����q
      pre = q;
      q = q->next;
    }
    s->next = q;  //��s����pre��q�м�
    pre->next = s;
  }
}
void AddPolyn(polynomial &pa, polynomial &pb) {
  polynomial p1 = pa->next;
  polynomial p2 = pb->next;                       
  polynomial p3 = pa;
  polynomial r = nullptr;
  while (p1 && p2) {
    if (p1->expn == p2->expn) {//ָ�����
      float sum = p1->coef + p2->coef;//sum����Ϊ��ϵ����
      if (sum) {
        p1->coef = sum;
        p3->next = p1;
        p3 = p1;
        p1 = p1->next;
        r = p2;
        p2 = p2->next;
        delete r;//ɾ��ָ��ĵ�ǰ�ڵ��ͷ��ڴ�
      } else {
        r = p1;
        p1 = p1->next;
        delete r;
        r = p2;
        p2 = p2->next;
        delete r;
      }
    } else if (p1->expn < p2->expn) {//pa��ǰ�ڵ��ָ��ֵС
      p3->next = p1;
      p3 = p1;
      p1 = p1->next;
    } else {//pb��ǰ�ڵ��ָ��ֵС
      p3->next = p2;
      p3 = p2;
      p2 = p2->next;
    }
  }
  p3->next = p1 ? p1 : p2;//ʹ����Ԫ���������ǿ����ʣ���
  delete pb;
}
void Display(polynomial p) {                //��ӡ����ʽ
  if (!p->next) {
    cout << "����¼������" << endl;
    return;
  } else {
    p=p->next;
    while (p) {
      cout << "ϵ��:" << p->coef << " "
           << "ָ����" << p->expn << endl;
           p=p->next;
    }
  }
}
int main() {
  polynomial p1, p2 = nullptr;
  cout<<"������һ���ڵ�"<<endl;
  CreatePolyn(p1, 2);
  cout<<"�����ڶ����ڵ�"<<endl;
  CreatePolyn(p2, 2);
  AddPolyn(p1, p2);                       //�ϲ�����ʽ
  Display(p1);                            //��ӡ���պϲ��Ķ���ʽ
  system("pause");
}
