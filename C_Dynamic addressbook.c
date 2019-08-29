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

AddressBook g_address_book;//g表示全局变量

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
    printf("1.新增联系人\n");
    printf("2.删除联系人\n");
    printf("3.查找联系人\n");
    printf("4.更新联系人信息\n");
    printf("5.打印全部联系人\n");
    printf("6.排序联系人\n");
    printf("7.清空联系人\n");
    printf("0.退出\n");
    printf("==========================\n");
    printf("请输入您的选择:");
    int choice=0;
    scanf("%d",&choice);
    return choice;
}


void Empty(){
    //这个函数用来凑数,令编号和用户输入一致.
}

void AddPersonInfo(){
    printf("*新增联系人*\n");
    if(g_address_book.size>=g_address_book.capacity){
        //扩容
        printf("扩容中...\n");
        g_address_book.capacity+=10;
        free(g_address_book.person);
        g_address_book.person=(PersonInfo*)malloc(sizeof(PersonInfo)*g_address_book.capacity);
        printf("扩容成功!\n");
    }
    PersonInfo* person_info=&g_address_book.person[g_address_book.size];
    printf("请输入联系人姓名:");
    //必须获取到一个指针,修改的内容是一个预期的内容(否则person_info只是一份拷贝,无法修改)
    scanf("%s",person_info->name);
    printf("请输入联系人电话:");
    scanf("%s",person_info->phone);
    printf("请输入联系人性别(male 男,female 女,unknow 未知):");
    scanf("%s",person_info->sex);
    printf("请输入联系人年龄:");
    scanf("%s",person_info->age);
    printf("请输入联系人地址:");
    scanf("%s",person_info->address);
    ++g_address_book.size;
    printf("新增联系人成功!\n");
}

void DelPersonInfo(){//交换要删除的联系人和最后一个联系人,然后执行删除最后一个联系人的操作
    printf("*删除联系人*\n");
    if(g_address_book.size<=0){
        printf("删除失败,通讯录为空!\n");
        return;
    }
    printf("请输入要删除的序号：");
    int id =0;
    scanf("%d",&id);
    if(id<0||id>=g_address_book.size){
        printf("删除失败！序号有误!\n");
        return;
    }
    g_address_book.person[id]=g_address_book.person[g_address_book.size - 1];//结构体之间赋值
    --g_address_book.size;
    printf("删除联系人成功！\n");
}

void FindPersonInfo(){
    printf("*查找联系人*\n");
    if(g_address_book.size<=0){
        printf("通讯录为空,无法查找联系人!\n");
        return;
    }
    printf("请输入要查找的姓名:");
    char name[MAX_DATA_SIZE]={0};
    scanf("%s",name);
    for (int i = 0; i <g_address_book.size ; ++i) {
        PersonInfo* info= &g_address_book.person[i];
        if(strcmp(info->name,name)==0){
            printf("[%d] %s\t%s\n",i,info->name,info->phone);
        }else{
            printf("联系人列表查无此人!\n");
            return;
        }
    }
    printf("查找联系人成功!\n");
}

void UpdatePersonInfo(){
    printf("*更新联系人信息*\n");
    if(g_address_book.size<=0){
        printf("通讯录为空,无法更新联系人!\n");
        return;
    }
    printf("请输入要更新的联系人序号:");
    int id=0;
    scanf("%d",&id);
    if(id<0||id>=g_address_book.size){
        printf("序号有误,修改失败!\n");
        return;
    }
    PersonInfo* info=&g_address_book.person[id];
    printf("旧的姓名为:(%s),请输入新的姓名(若不修改请输入*):\n",info->name);
    char name[MAX_DATA_SIZE]={0};
    scanf("%s",name);
    if(strcmp(name,"*")!=0){
        strcpy(info->name,name);
    }
    char phone[MAX_DATA_SIZE]={0};
    printf("旧的号码为:(%s),请输入新的电话(若不修改请输入*):\n",info->phone);
    scanf("%s",phone);
    if(strcmp(phone,"*")!=0){
        strcpy(info->phone,phone);
    }
    printf("旧的性别为:(%s),请输入新的性别(若不修改请输入*):\n",info->sex);
    char sex[MAX_DATA_SIZE]={0};
    scanf("%s",sex);
    if(strcmp(sex,"*")!=0){
        strcpy(info->sex,sex);
    }
    printf("旧的年龄为:(%s),请输入新的年龄(若不修改请输入*):\n",info->age);
    char age[MAX_DATA_SIZE]={0};
    scanf("%s",age);
    if(strcmp(age,"*")!=0){
        strcpy(info->age,age);
    }
    printf("旧的地址为:(%s),请输入新的地址(若不修改请输入*):\n",info->address);
    char address[MAX_DATA_SIZE]={0};
    scanf("%s",address);
    if(strcmp(address,"*")!=0){
        strcpy(info->address,address);
    }
    printf("成功更新联系人信息!\n");
}

void PrintAllPersonInfo(){
    printf("*打印全部联系人*\n");
    for (int i = 0; i <g_address_book.size ; ++i) {
        PersonInfo* info =&g_address_book.person[i];//结构体变量触发拷贝，要定义一个指针
        printf("[%d]姓名:%s\t电话:%s\t性别:%s\t年龄:%s\t地址:%s\n",
               i,info->name,info->phone,info->sex,info->age,info->address);
    }
    printf("共打印了%d条数据！\n",g_address_book.size);
    printf("打印全部联系人成功！\n");
}

void SortPersonInfo(){//strcmp 姓名字典序
    if(g_address_book.size<=0){
        printf("通讯录为空,无法排序联系人!\n");
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
    printf("联系人排序成功!\n");
}

void ClearPersonInfo(){
    printf("*清空联系人*\n");
    if(g_address_book.size<=0){
        printf("通讯录已为空!\n");
        return;
    }
    printf("!-------警告-------!\n");
    printf("您真的要清空所有数据吗???\n");
    printf("是的!(Y) 不是!(N)\n");
    printf("!-------警告-------!\n");
    char choice[1024]={0};
    scanf("%s",choice);
    if(strcmp(choice,"Y")==0){
        g_address_book.size=0;
        printf("成功清除全部联系人数据!\n");
    }else{
        printf("清空操作取消\n");
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
            printf("您的输入有误!\n");
            continue;
        }
        if(choice==0){
            printf("goodbye!\n");
            break;
        }
        arr[choice]();//借助转移表调用各个函数,转移表:函数指针数组
    }
    return 0;
}
