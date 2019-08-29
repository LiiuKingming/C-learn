#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

//#define MAX_PERSON_INFO_SIZE 1000
#define MAX_DATA_SIZE 1024

typedef struct PersonInfo{
    char name[MAX_DATA_SIZE];
    char phone[MAX_DATA_SIZE];
    char sex[MAX_DATA_SIZE];
    char age[MAX_DATA_SIZE];
    char address[MAX_DATA_SIZE];
}PersonInfo;

typedef struct AddressBook{
    PersonInfo* person;
    int size;
    int capacity;
}AddressBook;

AddressBook g_address_book;//g��ʾȫ�ֱ���

void Init(){
    assert(&g_address_book != NULL);
    g_address_book.size=0;
    g_address_book.capacity=1;
    g_address_book.person=(PersonInfo*)malloc(sizeof(PersonInfo)*g_address_book.capacity);

    for (int i = 0; i <g_address_book.capacity ; ++i) {
        memset(g_address_book.person[i].name,0,MAX_DATA_SIZE);
        memset(g_address_book.person[i].phone,0,MAX_DATA_SIZE);
        memset(g_address_book.person[i].sex,0,MAX_DATA_SIZE);
        memset(g_address_book.person[i].age,0,MAX_DATA_SIZE);
        memset(g_address_book.person[i].address,0,MAX_DATA_SIZE);
    }
}

int Menu(){
    printf("==========================\n");
    printf("1.������ϵ��\n");
    printf("2.ɾ����ϵ��\n");
    printf("3.������ϵ��\n");
    printf("4.������ϵ����Ϣ\n");
    printf("5.��ӡȫ����ϵ��\n");
    printf("6.������ϵ��\n");
    printf("7.�����ϵ��\n");
    printf("0.�˳�\n");
    printf("==========================\n");
    printf("����������ѡ��:");
    int choice=0;
    scanf("%d",&choice);
    return choice;
}


void Empty(){
    //���������������,���ź��û�����һ��.
}

void AddPersonInfo(){
    printf("*������ϵ��*\n");
    if(g_address_book.size>=g_address_book.capacity){
        //����
        printf("������...\n");
        g_address_book.capacity+=10;
        free(g_address_book.person);
        g_address_book.person=(PersonInfo*)malloc(sizeof(PersonInfo)*g_address_book.capacity);
        printf("���ݳɹ�!\n");
    }
    PersonInfo* person_info=&g_address_book.person[g_address_book.size];
    printf("��������ϵ������:");
    //�����ȡ��һ��ָ��,�޸ĵ�������һ��Ԥ�ڵ�����(����person_infoֻ��һ�ݿ���,�޷��޸�)
    scanf("%s",person_info->name);
    printf("��������ϵ�˵绰:");
    scanf("%s",person_info->phone);
    printf("��������ϵ���Ա�(male ��,female Ů,unknow δ֪):");
    scanf("%s",person_info->sex);
    printf("��������ϵ������:");
    scanf("%s",person_info->age);
    printf("��������ϵ�˵�ַ:");
    scanf("%s",person_info->address);
    ++g_address_book.size;
    printf("������ϵ�˳ɹ�!\n");
}

void DelPersonInfo(){//����Ҫɾ������ϵ�˺����һ����ϵ��,Ȼ��ִ��ɾ�����һ����ϵ�˵Ĳ���
    printf("*ɾ����ϵ��*\n");
    if(g_address_book.size<=0){
        printf("ɾ��ʧ��,ͨѶ¼Ϊ��!\n");
        return;
    }
    printf("������Ҫɾ������ţ�");
    int id =0;
    scanf("%d",&id);
    if(id<0||id>=g_address_book.size){
        printf("ɾ��ʧ�ܣ��������!\n");
        return;
    }
    g_address_book.person[id]=g_address_book.person[g_address_book.size - 1];//�ṹ��֮�丳ֵ
    --g_address_book.size;
    printf("ɾ����ϵ�˳ɹ���\n");
}

void FindPersonInfo(){
    printf("*������ϵ��*\n");
    if(g_address_book.size<=0){
        printf("ͨѶ¼Ϊ��,�޷�������ϵ��!\n");
        return;
    }
    printf("������Ҫ���ҵ�����:");
    char name[MAX_DATA_SIZE]={0};
    scanf("%s",name);
    for (int i = 0; i <g_address_book.size ; ++i) {
        PersonInfo* info= &g_address_book.person[i];
        if(strcmp(info->name,name)==0){
            printf("[%d] %s\t%s\n",i,info->name,info->phone);
        }else{
            printf("��ϵ���б���޴���!\n");
            return;
        }
    }
    printf("������ϵ�˳ɹ�!\n");
}

void UpdatePersonInfo(){
    printf("*������ϵ����Ϣ*\n");
    if(g_address_book.size<=0){
        printf("ͨѶ¼Ϊ��,�޷�������ϵ��!\n");
        return;
    }
    printf("������Ҫ���µ���ϵ�����:");
    int id=0;
    scanf("%d",&id);
    if(id<0||id>=g_address_book.size){
        printf("�������,�޸�ʧ��!\n");
        return;
    }
    PersonInfo* info=&g_address_book.person[id];
    printf("�ɵ�����Ϊ:(%s),�������µ�����(�����޸�������*):\n",info->name);
    char name[MAX_DATA_SIZE]={0};
    scanf("%s",name);
    if(strcmp(name,"*")!=0){
        strcpy(info->name,name);
    }
    char phone[MAX_DATA_SIZE]={0};
    printf("�ɵĺ���Ϊ:(%s),�������µĵ绰(�����޸�������*):\n",info->phone);
    scanf("%s",phone);
    if(strcmp(phone,"*")!=0){
        strcpy(info->phone,phone);
    }
    printf("�ɵ��Ա�Ϊ:(%s),�������µ��Ա�(�����޸�������*):\n",info->sex);
    char sex[MAX_DATA_SIZE]={0};
    scanf("%s",sex);
    if(strcmp(sex,"*")!=0){
        strcpy(info->sex,sex);
    }
    printf("�ɵ�����Ϊ:(%s),�������µ�����(�����޸�������*):\n",info->age);
    char age[MAX_DATA_SIZE]={0};
    scanf("%s",age);
    if(strcmp(age,"*")!=0){
        strcpy(info->age,age);
    }
    printf("�ɵĵ�ַΪ:(%s),�������µĵ�ַ(�����޸�������*):\n",info->address);
    char address[MAX_DATA_SIZE]={0};
    scanf("%s",address);
    if(strcmp(address,"*")!=0){
        strcpy(info->address,address);
    }
    printf("�ɹ�������ϵ����Ϣ!\n");
}

void PrintAllPersonInfo(){
    printf("*��ӡȫ����ϵ��*\n");
    for (int i = 0; i <g_address_book.size ; ++i) {
        PersonInfo* info =&g_address_book.person[i];//�ṹ���������������Ҫ����һ��ָ��
        printf("[%d]����:%s\t�绰:%s\t�Ա�:%s\t����:%s\t��ַ:%s\n",
               i,info->name,info->phone,info->sex,info->age,info->address);
    }
    printf("����ӡ��%d�����ݣ�\n",g_address_book.size);
    printf("��ӡȫ����ϵ�˳ɹ���\n");
}

void SortPersonInfo(){//strcmp �����ֵ���
    if(g_address_book.size<=0){
        printf("ͨѶ¼Ϊ��,�޷�������ϵ��!\n");
        return;
    }
    for (int bound = 0; bound < g_address_book.size ; ++bound) {
        for (int cur = (g_address_book.size)-1; cur >bound ; --cur) {
            PersonInfo* latter=&g_address_book.person[cur];
            PersonInfo* former=&g_address_book.person[cur - 1];
            if(strcmp(latter->name, former->name) < 0){
                ++g_address_book.size;
                g_address_book.person[g_address_book.size-1]=g_address_book.person[cur];
                g_address_book.person[cur]=g_address_book.person[cur-1];
                g_address_book.person[cur-1]=g_address_book.person[g_address_book.size-1];
                --g_address_book.size;
            }
        }
    }
    printf("��ϵ������ɹ�!\n");
}

void ClearPersonInfo(){
    printf("*�����ϵ��*\n");
    if(g_address_book.size<=0){
        printf("ͨѶ¼��Ϊ��!\n");
        return;
    }
    printf("!-------����-------!\n");
    printf("�����Ҫ�������������???\n");
    printf("�ǵ�!(Y) ����!(N)\n");
    printf("!-------����-------!\n");
    char choice[1024]={0};
    scanf("%s",choice);
    if(strcmp(choice,"Y")==0){
        g_address_book.size=0;
        printf("�ɹ����ȫ����ϵ������!\n");
    }else{
        printf("��ղ���ȡ��\n");
    }
}

typedef  void(*Func)();

int main(){
    Func arr[]={
            Empty,
            AddPersonInfo,
            DelPersonInfo,
            FindPersonInfo,
            UpdatePersonInfo,
            PrintAllPersonInfo,
            SortPersonInfo,
            ClearPersonInfo
    };

    Init();

    while (1){
        int choice =Menu();
        if(choice<0||choice>= sizeof(arr)/ sizeof(arr[0])){
            printf("������������!\n");
            continue;
        }
        if(choice==0){
            printf("goodbye!\n");
            break;
        }
        arr[choice]();//����ת�Ʊ���ø�������,ת�Ʊ�:����ָ������
    }
    return 0;
}
