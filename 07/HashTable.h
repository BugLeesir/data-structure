#ifndef HASHTABLE
#define HASHTABLE
#define HashMax 100
#endif
template <typename datatype>
struct HashNode{
    datatype data;
    HashNode* next;
};//构建哈希表

template <typename datatype>
using HashTable=HashNode<datatype>*[HashMax];

template <typename datatype>
void NewHashTable(HashTable<datatype>&ht){
    for(int i=0;i<HashMax;++i)ht[i]=nullptr;//初始化哈希表
}

template<typename datatype>
unsigned HashCode(datatype &key){//哈希函数，将数据转化为哈希值
    unsigned hash_code= (key)%HashMax;//取余法得到哈希值
    if(hash_code==0){
        hash_code=(hash_code+10086)%HashMax;
    }
    return hash_code;
}

template<typename datatype>
void CreateHashTable(HashTable<datatype>&ht,datatype arr[],int num){//构建哈希表
    for(int i=0;i<num;++i){
        unsigned hash_code=HashCode(arr[i]);
        HashNode<datatype>*temp=new HashNode<datatype>;
        temp->data=arr[i];
        temp->next=nullptr;
        if(ht[hash_code]==nullptr){//若哈希表的该节点为空则加入节点
            ht[hash_code]=temp;
        }else{                     //使用拉链法解决地址冲突问题
            temp->next=ht[hash_code];   //若节点不为空，则头插法插入节点
            ht[hash_code]=temp;
        }
    }
}

template<typename datatype>
datatype FindValue(HashTable<datatype>ht,datatype data){//在哈希表中查找元素
     unsigned hash_code=HashCode(data);//调用哈希函数获取查找对象的哈希值
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

