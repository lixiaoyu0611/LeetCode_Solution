class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string letter[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        res.push_back("");
        for (int i = 0; i < digits.size(); i++){
            vector<string> temp;
            string chars = letter[digits[i] - '0'];
            for (int c = 0; c < chars.size(); c++)
                for (int j = 0; j < res.size(); j++)
                    temp.push_back(res[j] + chars[c]);
            res = temp;
        }
        return res;
    }
};