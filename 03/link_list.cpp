#include <cstdlib>
#include <iostream>
typedef int ElemType;
using namespace std;
typedef struct Node {
  ElemType elem;
  struct Node *next;
} Node, *Link_List;

void init_list(Link_List &l) {  //����һ���׽ڵ㲻Ϊ�յĵ�����
  l = new Node;
  l->next = nullptr;
}
void input_data(Link_List &p) { cin >> p->elem; }  //������������������
int get_length(Link_List p) {                      //ȡ������ĳ���
  p = p->next;
  int length = 0;
  while (p) {
    length += 1;
    p = p->next;
  }
  return length;
}
void display_data(Link_List l) {  //��ӡ�����е���������
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

void push_back(Link_List &l, int n) {  //ͨ��β�巨����ڵ�
  Link_List pr = l;
  while (pr->next) {
    pr = pr->next;
  }
  cout << "������Ҫ��������ݣ��м��Կո����" << endl;
  for (int i = 0; i < n; ++i) {
    Link_List p = new Node;
    input_data(p);
    pr->next = p;
    p->next = nullptr;
    pr = p;
  }
}
void search_by_index(Link_List &p, int i) {  //�������������Ҫ�ҵ��Ľڵ�
  int count = 0;
  while (count != i) {
    p = p->next;
    count++;
  }
}
void search_by_value(Link_List l, ElemType e) {  //ͨ������Ѱ�ҵ����ݲ���ӡ
  if (!l->next) {
    cout << "����¼������" << endl;
  } else {
    Link_List p = l;
    l = l->next;
    for (int i = 0; i < get_length(p); ++i) {
      if (l->elem == e) {
        cout << "�ɹ��ҵ�"
             << "����Ϊ��" << i + 1 << "ֵΪ:" << l->elem << endl;
        return;
      }
      l = l->next;
    }
    cout << "δ���ҵ�������" << endl;
  }
}
int delete_data(Link_List &l, int i) {  //ɾ���ڵ�
  if (i <= 0 || i > get_length(l)) {
    cout << "��������ȷ��ɾ������" << endl;
    return 0;
  } else {
    Link_List pr = l;
    search_by_index(pr, i);
    Link_List p = pr->next;
    if (!p) {  //��ĩβ�ڵ��ǰһ���ڵ�Ϊ�������±��������ҵ���ǰһ���ڵ㲢ɾ��
      pr = l;
      search_by_index(pr, i - 1);
      Link_List temp = pr->next;
      pr->next = nullptr;
      delete temp;
      return 1;
    } else {  //��ĩβ�ڵ㲻Ϊ����ֱ��ͨ����ɾ��ɾ��
      pr->elem = p->elem;
      pr->next = p->next;
      delete p;
      return 1;
    }
  }
}
void insert_node(Link_List &l, int i) {
  if (i <= 0 || i > get_length(l)) {
    cout << "��������ȷ�Ĳ�������" << endl;
  } else {
    Link_List pr = l;
    search_by_index(pr, i);
    Link_List pt = pr->next;
    Link_List p = new Node;
    if (pt) {
      int temp = pr->elem;
      cout << "������Ҫ���������" << endl;
      input_data(pr);
      pr->next =
          p;  //����λ��ǰ�����Ϊ��������λ���滻Ϊ�½ڵ��е����ݣ���ԭ�ڵ�����ݸ��Ƹ��½ڵ�
      p->elem = temp;
      p->next = pt;
    } else {
      cout << "������Ҫ���������" << endl;  //��ĩβ�ڵ�Ϊ����ֱ�Ӳ����½ڵ�
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
    cout << "1,¼������" << endl
         << "2,��ӡ����" << endl
         << "3,ɾ������" << endl
         << "4,��������" << endl
         << "5,��������" << endl
         << "6,����ת" << endl
         << "7,�˳�" << endl
         << "����������" << endl;
    cin >> option;
    switch (option) {
      case 1: {
        int n;
        cout << "������Ҫ��ӵĸ���" << endl;
        cin >> n;
        push_back(l, n);
        break;
      }
      case 2:
        display_data(l);
        break;
      case 3: {
        int i, j;
        cout << "������Ҫɾ�����ݵ�����" << endl;
        cin >> i;
        j = delete_data(l, i);
        if (j) cout << "ɾ���ɹ�" << endl;
        break;
      }
      case 4: {
        ElemType e;
        cout << "������Ҫ���ҵ�����" << endl;
        cin >> e;
        search_by_value(l, e);
        break;
      }
      case 5: {
        int i;
        cout << "������Ҫ���������" << endl;
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
        cout << "��������ȷ������" << endl;
        break;
    }
  }
  return 0;
}