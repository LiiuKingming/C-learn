namespace _tmp{
    string numLetter[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
}

 void dealLetterCombinations(string &digits, size_t pos, vector<string> &alldata){//元素, 层数, alldata所有情况
    static string res = digits;//存结果, 不能随着栈消失

    if(pos < digits.size()){
        for(auto &i : _tmp::numLetter[digits[pos] - '2']){
            //_tmp::numLetter[digits[pos] - '2']是string的元素, 对其进行遍历
            res[pos] = i;//覆盖字符 如abc
            dealLetterCombinations(digits, pos + 1, alldata);
        }
    }else{//数字填完, 放入res
        cout << res <<endl;
        alldata.push_back(res);

    }
//    _tmp::numLetter[digits[pos] - '2'];
}
vector<string> letterCombinations(string digits) {
    vector<string> res;

    dealLetterCombinations(digits, 0, res);
    return res;
}

int main(){
    string digits = "2333";
    vector<string> data = letterCombinations(digits);
    return 0;
}