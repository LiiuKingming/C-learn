namespace _tmp{
    string numLetter[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
}

 void dealLetterCombinations(string &digits, size_t pos, vector<string> &alldata){//Ԫ��, ����, alldata�������
    static string res = digits;//����, ��������ջ��ʧ

    if(pos < digits.size()){
        for(auto &i : _tmp::numLetter[digits[pos] - '2']){
            //_tmp::numLetter[digits[pos] - '2']��string��Ԫ��, ������б���
            res[pos] = i;//�����ַ� ��abc
            dealLetterCombinations(digits, pos + 1, alldata);
        }
    }else{//��������, ����res
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