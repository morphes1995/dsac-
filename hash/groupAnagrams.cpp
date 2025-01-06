#include <vector>
#include <list>
#include <unordered_map>
#include <string>
using namespace std;

/**
*49. 字母异位词分组
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的所有字母得到的一个新单词。


 * 由于互为字母异位词的两个字符串包含的字母相同，因此两个字符串中的相同字母出现的次数一定是相同的，
 * 故可以将每个字母出现的次数使用字符串表示，作为哈希表的键。
 */
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string,vector<string>> map;
    for (string str : strs) {
        vector<int> counts(26,0);
        int length = str.length();
        for (int i = 0; i < length; i++) {
            counts[str[i] - 'a']++;
        }
        // 将每个出现次数大于 0 的字母和出现次数按顺序拼接成字符串，作为哈希表的键
        string key;
        for (int i = 0; i < 26; i++) {
            if (counts[i] != 0) {
                key.push_back((char)('a' + i));
                key.append(to_string(counts[i]));
            }
        }
        if (!map.contains(key)) {
            map.emplace(key,vector<string>());
        }
        vector<string> &anagrams = map[key];
        anagrams.push_back(str);
    }

    for (auto it=map.begin();it!=map.end();it++) {
        res.push_back(it->second);
    }

    return res;
}

int main() {

    vector<string> strs ={"eat","tea","tan","ate","nat","bat"};
    groupAnagrams(strs);

}