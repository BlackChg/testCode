#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
public:
    vector<string> result;
    string s;
    void backtracking(const string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';        // ��indexָ�������תΪint
        string letters = letterMap[digit];      // ȡ���ֶ�Ӧ���ַ���
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);            // ����
            backtracking(digits, index + 1);    // �ݹ飬ע��index+1��һ�²�Ҫ������һ��������
            s.pop_back();                       // ����
        }
    }
    vector<string> letterCombinations(string digits) {
        s.clear();
        result.clear();
        if (digits.size() == 0) {
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
};
int main()
{
    static const char* nums[] = { "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    static const string lettermap[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    cout << nums[1][2] << endl;
	//test();
	return 0;
}