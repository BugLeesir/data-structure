//˳�����������㷨
#include <iostream>
#define MaxSize 50
using namespace std;
typedef int ElemType;
typedef struct List {
  ElemType data[MaxSize];  //���˳���Ԫ��
  int length;              //���˳���ĳ���
} List, *SqList;           //˳��������
SqList CreateList(ElemType a[], int n)
//����˳���
{
  SqList L = new List;
  for (int i = 0; i < n; i++) L->data[i] = a[i];
  L->length = n;
  return L;
}
void DestroyList(SqList L) { delete L; }  //�ͷ��ڴ�
void DispList(SqList L) {
  for (int i = 0; i < L->length; i++) cout << L->data[i] << " ";
  cout << endl;
}
void Revese(SqList L) {
  typedef struct StackNode {//ʹ��ջ�ṹ���з�ת
    ElemType data;
    struct StackNode *next;
  } StackNode, *LinkStack;
  LinkStack temp = nullptr;
  for (int i = 0; i < L->length; ++i) {//��ջ
    LinkStack p = new StackNode;
    p->data = L->data[i];
    p->next = temp;
    temp = p;
  }
  for (int i = 0; i < L->length; ++i) {//��ջ
    L->data[i] = temp->data;
    LinkStack p = temp;
    temp = temp->next;
    delete p;
  }
}
bool GetElem(SqList L, int i, ElemType &e) {  //ȡ������Ԫ��
  if (i < 1 || i > L->length) return false;
  e = L->data[i - 1];
  return true;
}
int LocateElem(SqList L, ElemType e) {  //ȡ������Ԫ�ص��±�
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
  i--;                             //��˳���λ��ת��Ϊelem�±�
  for (j = L->length; j > i; j--)  //��data[i]������Ԫ�غ���һ��λ��
    L->data[j] = L->data[j - 1];
  L->data[i] = e;
  L->length++;  //˳�������1
  return true;
}
bool ListDelete(SqList L, int i, ElemType &e) {
  int j;
  if (i < 1 || i > L->length) return false;
  i--;  //��˳���λ��ת��Ϊelem�±�
  e = L->data[i];
  for (j = i; j < L->length - 1; j++)  //��data[i]֮���Ԫ��ǰ��һ��λ��
    L->data[j] = L->data[j + 1];
  L->length--;  //˳����ȼ�1
  return true;
}
int main() {
  bool flag = true;
  int option;
  SqList L = nullptr;
  while (flag) {  //�����˵�
    cout << "1,����˳���" << endl
         << "2,˳������" << endl
         << "3,˳���ɾ��" << endl
         << "4,˳���Ĳ���" << endl
         << "5,˳���ת" << endl
         << "6,�˳�" << endl
         << "����������";
    cin >> option;
    switch (option) {
      case 1: {
        int n;
        cout << "��������Ҫ�������ݵĸ���" << endl;
        cin >> n;
        ElemType a[n];
        for (int i = 0; i < n; ++i) {
          cout << "�������" << i + 1 << "����" << endl;
          cin >> a[i];
        }
        L = CreateList(a, n);
        break;
      }
      case 2: {
        if (!L) {
          cout << "����¼������" << endl;
        } else {
          ElemType e;
          int i;
          cout << "��������������" << endl;
          cin >> e;
          cout << "���������λ��" << endl;
          cin >> i;
          if (ListInsert(L, i, e)) {
            cout << "����ɹ�" << endl;
            DispList(L);
          } else {
            cout << "����ʧ��<<endl";
          }
        }
        break;
      }
      case 3: {
        if (!L) {
          cout << "����¼������" << endl;
        } else {
          int et;
          ElemType &e = et;
          int i;
          cout << "������Ҫɾ����λ��" << endl;
          cin >> i;
          if (ListDelete(L, i, e)) {
            cout << "ɾ���ɹ���ɾ������" << e << endl;
            DispList(L);
          } else {
            cout << "ɾ��ʧ��" << endl;
          }
        }
        break;
      }
      case 4: {
        if (!L) {
          cout << "����¼������" << endl;
        } else {
          int et;
          ElemType &e = et;
          int location;
          cout << "������Ҫ���ҵ�����" << endl;
          cin >> e;
          location = LocateElem(L, e);
          if (location) {
            GetElem(L, location, e);
            cout << "�ɹ��ҵ�����Ԫ���ǵ�" << location << "��Ԫ��,ֵΪ" << e
                 << endl;
          } else {
            cout << "δ�ҵ���Ԫ��" << endl;
          }
        }
        break;
      }
      case 5:
        if (!L) {
          cout << "����¼������" << endl;
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
        cout << "�������" << endl;
        break;
    }
  }
  return 0;
}