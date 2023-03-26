#include <iostream>
#include <bitset>
#include <cmath>
#include <string>


std::string make_bin_str(int int_num) {
    std::string bin_str = std::bitset<32>(int_num).to_string();
    return bin_str.substr(bin_str.find_first_not_of('0'));
}

std::string unary_coding(std::string inp_str) {
    std::string ret_str = "";
    for (int i = 0; i < stoi(inp_str); i++) {
        ret_str = ret_str + "1";
    }
    ret_str = ret_str + "0";
    return ret_str;
}

int main() {
    int x, m;
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "m: ";
    std::cin >> m;

    if (m == 1) {
        std::cout << unary_coding(std::to_string(x));
    }
    else if (log2(m) == floor(log2(m))) {
        std::string first_part = unary_coding(std::to_string(floor(x / m)));
        int second_part = x - floor(x / m) * m;
        int k_bits = log2(m);
        std::string second_part_str = make_bin_str(second_part);
        if (second_part_str.length() < k_bits) {
            int num = k_bits - second_part_str.length();
            std::string zero_str = "";
            for (int i = 0; i < num; i++) {
                zero_str = zero_str + "0";
            }
            second_part_str = zero_str + second_part_str;
        }
        std::cout << first_part + second_part_str;
    }
    else {
        int n = floor(x / m);
        std::string first_part = unary_coding(std::to_string(n));
        int b = ceil(log2(m));
        int r = x - n * m;
        if (r < (pow(2, b) - m)) {
            std::string r_bin = make_bin_str(r);
            int num_bits = b - 1;
            if (r_bin.length() < num_bits) {
                int num = num_bits - r_bin.length();
                std::string zero_str = "";
                for (int i = 0; i < num; i++) {
                    zero_str = zero_str + "0";
                }
                r_bin = zero_str + r_bin;
            }
            std::cout << first_part + r_bin;
        }
        else {
            int rr = r + pow(2, b) - m;
            std::string r_bin = make_bin_str(rr);
            int num_bits = b;
            if (r_bin.length() < num_bits) {
                int num = num_bits - r_bin.length();
                std::string zero_str = "";
                for (int i = 0; i < num; i++) {
                    zero_str = zero_str + "0";
                }
                r_bin = zero_str + r_bin;
            }
            std::cout << first_part + r_bin;
        }
    }

    return 0;
}
