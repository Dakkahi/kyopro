#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include <sstream>
using namespace std;
using ll = long long;

string convert_to_words(int n);

string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string thousands[] = {"", "thousand"};

string num_to_words(int n, string x) {
    string str = "";
    if (n > 19) {
        str += tens[n / 10] + " " + ones[n % 10];
    } else if (n > 10) {
        str += teens[n % 10];
    } else {
        str += ones[n];
    }
    if (n) {
        str += " " + x;
    }
    return str;
}

string convert_to_words(int n) {
    string result;

    result += num_to_words((n / 1000) % 100, "thousand");
    result += num_to_words((n / 100) % 10, "hundred");

    if (n > 100 && n % 100) {
        result += " and ";
    }

    result += num_to_words(n % 100, "");

    if (!result.empty()) {
        result[0] = toupper(result[0]);//最初の文字を大文字に
    }

    return result;
}

string convert_fractional_part(const string &fraction) {
    string result = "point";
    for (char digit : fraction) {
        result += " " + ones[digit - '0'];
    }
    return result;
}

string number_to_words(double num) {
    stringstream ss;
    ss << num;
    string num_str = ss.str();

    size_t dot_pos = num_str.find('.');
    int integer_part = stoi(num_str.substr(0, dot_pos));
    string fractional_part = dot_pos != string::npos ? num_str.substr(dot_pos + 1) : "";

    string result;
    if (integer_part == 0) {
        result = "zero";
    } else {
        result = convert_to_words(integer_part);
    }

    if (!fractional_part.empty()) {
        result +=convert_fractional_part(fractional_part);
    }

    return result;
}

int main() {
    double num;
    cin >> num;

    cout << number_to_words(num) << endl;

    return 0;
}
