//
// Created by 28943 on 2019/10/30.
//
#include <iostream>
#include <string>
#include <typeinfo>
#include <algorithm>
using namespace std;

int  _main1(){
    string s1;
    string s2("caixukunsbcaixukunsb");
    string s3(s2);
    string s4(5, '6');

    /*cout << s1 << endl
         << s2 << endl
         << s3 << endl
         << s4 << endl;*/


    s3.resize(53, 'n');//预留16倍数 - 1的空间, 应为511
//    s4.reserve(499);
    s3.push_back('6');
    for(auto& i : s3){
        cout << i;
    }
    //c++11之前的写法
    /*string::iterator i;
    for(auto i = s3.begin(); i != s1.end(); i++){
        cout << *i;
    }*/

//    cout << s3.capacity() << endl;
//    cout << s4.capacity() << endl;
//    cout << s3.size() << endl;
//    cout << s4.size() << endl;
//    s3.clear();
//    cout << s3.size() << endl;


    /*cout << s1.size()<< endl
         << s2.size() << endl
         << s3.length() << endl
         << s4.size() << endl;

    cout << s1.capacity() << endl
         << s2.capacity() << endl
         << s3.capacity() << endl
         << s4.capacity() << endl;
*/
    return 0;
}

//string类的使用

//构造
//默认构造
//传入一个字符串
// 拷贝构造
//n个字符

//1.size/length 这两个函数没有参数, 实现原理相同
//返回值为字符串的长度

//2.capacity 没有参数,返回值是容器的容量
//(容量16的倍数 - 1, 容量只会增大不会缩小

//empty 判断容器是否为空, 空1, 非空0

//clear 清空字符串

//reserve 调整容量(只会向大调整, 为了避免频烦扩容导致的效率损失)
//参数是要调整到的容量大小, 如果比已有的容量小, 则无效

//resize 强制调整字符串长度, 参数是要调整的大小,
// 第二个参数是缺省参数, 是向大调整时, 扩展部分的空间要赋的值
//如果不给第二个参数, 那么默认给0, resize 会先调用reserve

//append 可以对字符串进行追加 类似+=, 但也可以传n个字符的形式

//重载[], +=   +  =


int _main2(){
    /*
    string s1("xiao zhu pei qi");
    string s2("pei pei");
    string s3("pei qi");
    cout << s1.find('p', 0) << endl;
    cout << s1.find(s2, 4) << endl;
    cout << s1.find(s3) << endl;
    cout << s1.find("pei pei") << endl;
    cout << s1.find("pei pei", 0, 7) << endl;

    cout << s1.rfind('p', s1.size() - 1) << endl;
    cout << "6" << endl;
    cout << s1.substr(0, 8) << endl;*/

    string s1;
    char str[1000] = {0};
    //C语言解决方案
//    scanf("%[^\n]", str);//可以输入一行, 碰到\n结束
//    fgets(str, 1000, stdin);

//    cin.getline(str, 100);
    getline(cin, s1);
    cout << str;


    return 0;
}
//一.string的查找

//find函数可以传三种东西
//1.字符
//2.字符串
//3.字符容器

//find从前面开始找 rfind 从后面开始找

//缺省参数:
//从什么位置开始找. 找到了返回下标, 找不到返回 - 1
//但是由于pos返回值类型是unsigned类型, 所以打印出来就成了4294967295

//substr 切割函数

//+的重载不是string容器的成员, +=才是
//getline 是为了解决cin碰到空格就停的问题, getline碰到回车才停
 void reverseString(string& s) {
    int i, j;
    for (i = 0, j = s.size() - 1; i < j; i++, j--) {
        swap(s[i], s[j]);//#include <algorithm>
    }
}

int firstUniqChar(string s){
    int count[26] = {0};

    for (auto& ch : s){
        count[ch - 'a']++;
    }
    //test
/*    int j = 0;
    for (auto & i : count){
        cout << (char)('a' + j++) << ' ' << i << endl;
    }*/
    for (int i = 0; i < s.size(); ++i) {
        if(count[s[i] - 'a'] == 1 ){
            return i;
        }
    }
    return -1;

    return 0;
}

bool isLetterOrNum(char ch){
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9');
}

bool isSame(char a, char b){

    return (a == b) ||
            (a | 1 << 5 )== (b | 1 << 5);
}

bool isPalindrome(string s){
    string tmp;
    for (auto & ch : s){
        if(isLetterOrNum(ch)){
            tmp.push_back(ch);
        }
    }
    int i, j;
    for (i = 0, j = tmp.size() - 1; i < j ; i++,j-- ){
        if(!isSame(tmp[i], tmp[j])){
            return false;
        }
    }
    return true;
}

int main(){
//    string s1("ikun");
//    reverseString(s1);
//    cout << s1;
    string s1;
//    cin >> s1;
//    firstUniqChar(s1);

//    while(getline(cin, s1)){
//        size_t pos = s1.rfind(' ');
//        cout << s1.size() - pos - 1 << endl;
//    }

    return 0;
}

