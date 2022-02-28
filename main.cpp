#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

vector<string> tokenize(vector<string> file) {
    vector<string> tokens;
    string token = "";
    for (string line : file) {
        for (int c = 0; c < line.length(); c ++) {
            if (line[c] == ' ') {
                if (token.length() > 0) {
                    tokens.push_back(token);
                    token = "";
                }
                continue;
            }
            else if (line[c] == '+' or line[c] == '-' or line[c] == '/' or line[c] == '*') {
                if (token.length() > 0) {
                    tokens.push_back(token);
                    token = "";
                }
                string tmp_string = "";
                tmp_string.push_back(line[c]);
                tokens.push_back(tmp_string);
            }
            else if (line[c] == '=') {
                string tmp_string = "=";
                if (line[c+1] == '=') {
                    c += 1;
                    tmp_string.push_back('=');
                }
                if (token.length() > 0) {
                    tokens.push_back(token);
                    token = "";
                }
                tokens.push_back(tmp_string);
            }
            else if (line[c] == ';') {
                if (token.length() > 0) {
                    tokens.push_back(token);
                    token = "";
                }
                tokens.push_back(";");
            }
            else {
                token += line[c];
            }
        }
        if (token.length() > 0) {
            tokens.push_back(token);
            token = "";
        }
    }
    return tokens;
}

int main(int argc, char *argv[]) {
    ifstream file(argv[1]);
    vector<string> tokens;
    vector<string> text;
    string buffer;

    while (getline(file, buffer)) {
        text.push_back(buffer);
    }

    tokens = tokenize(text);
    for (int i; i < tokens.size(); i++) {
        cout << i <<  " " << tokens[i] << "\n";
    }
}