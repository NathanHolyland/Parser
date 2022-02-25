#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

vector<string> tokenize(string line) {
    vector<string> tokenList;
    string token = "";
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ';') {
            tokenList.push_back(token);
            token = "";
            break;
        }
        if (line[i] == ' ') {
            if (token.length() == 0) {
                continue;
            }
            tokenList.push_back(token);
            token = "";
            continue;
        }
        if (line[i] == '+' or line[i] == '-' or line[i] == '=' or line[i] == '*' or line[i] == '/') {
            if (token.length() > 0) {
                tokenList.push_back(token);
                token = "";
            }
            token = token + line[i];
            tokenList.push_back(token);
            token = "";
            continue;
        }
        token = token + line[i];
    }
    return tokenList;
}

int main(int argc, char *argv[]) {
    ifstream file(argv[1]);
    vector<vector<string>> tokens;
    string buffer;

    while (getline(file, buffer)) {
        vector<string> tokenList;
        tokenList = tokenize(buffer);
        tokens.push_back(tokenList);
        for (int i = 0; i < tokenList.size(); i++) {
            cout << i << " " << tokenList[i] << "\n";
        }
    }
}