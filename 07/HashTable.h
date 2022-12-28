#ifndef HASHTABLE
#define HASHTABLE
#define HashMax 100
#endif
template <typename datatype>
struct HashNode{
    datatype data;
    HashNode* next;
};//������ϣ��

template <typename datatype>
using HashTable=HashNode<datatype>*[HashMax];

template <typename datatype>
void NewHashTable(HashTable<datatype>&ht){
    for(int i=0;i<HashMax;++i)ht[i]=nullptr;//��ʼ����ϣ��
}

template<typename datatype>
unsigned HashCode(datatype &key){//��ϣ������������ת��Ϊ��ϣֵ
    unsigned hash_code= (key)%HashMax;//ȡ�෨�õ���ϣֵ
    if(hash_code==0){
        hash_code=(hash_code+10086)%HashMax;
    }
    return hash_code;
}

template<typename datatype>
void CreateHashTable(HashTable<datatype>&ht,datatype arr[],int num){//������ϣ��
    for(int i=0;i<num;++i){
        unsigned hash_code=HashCode(arr[i]);
        HashNode<datatype>*temp=new HashNode<datatype>;
        temp->data=arr[i];
        temp->next=nullptr;
        if(ht[hash_code]==nullptr){//����ϣ��ĸýڵ�Ϊ�������ڵ�
            ht[hash_code]=temp;
        }else{                     //ʹ�������������ַ��ͻ����
            temp->next=ht[hash_code];   //���ڵ㲻Ϊ�գ���ͷ�巨����ڵ�
            ht[hash_code]=temp;
        }
    }
}

template<typename datatype>
datatype FindValue(HashTable<datatype>ht,datatype data){//�ڹ�ϣ���в���Ԫ��
     unsigned hash_code=HashCode(data);//���ù�ϣ������ȡ���Ҷ���Ĺ�ϣֵ
    HashNode<datatype>*temp=ht[hash_code];
    while(temp){
        if(temp->data==data){
            return temp->data;
        }else{
            temp=temp->next;
        }
    }
    return -1;     
}

