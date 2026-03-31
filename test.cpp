#include <iostream>
#include "str.hpp"

int main() {
    // Test default constructor
    str s1;
    std::cout << "s1 length: " << s1.len() << std::endl;

    // Test char constructor
    str s2('A');
    std::cout << "s2: " << s2[0] << ", length: " << s2.len() << std::endl;

    // Test char* constructor
    str s3("Hello");
    std::cout << "s3 length: " << s3.len() << std::endl;
    for (size_t i = 0; i < s3.len(); ++i) {
        std::cout << s3[i];
    }
    std::cout << std::endl;

    // Test copy constructor
    str s4(s3);
    std::cout << "s4 length: " << s4.len() << std::endl;
    for (size_t i = 0; i < s4.len(); ++i) {
        std::cout << s4[i];
    }
    std::cout << std::endl;

    // Test copy assignment
    str s5;
    s5 = s3;
    std::cout << "s5 length: " << s5.len() << std::endl;
    for (size_t i = 0; i < s5.len(); ++i) {
        std::cout << s5[i];
    }
    std::cout << std::endl;

    // Test char* assignment
    str s6;
    s6 = "World";
    std::cout << "s6 length: " << s6.len() << std::endl;
    for (size_t i = 0; i < s6.len(); ++i) {
        std::cout << s6[i];
    }
    std::cout << std::endl;

    // Test slice
    str s7 = str("12345").slice(0, 2);
    std::cout << "s7 (slice of '12345' [0,2)): length " << s7.len() << ", value: ";
    for (size_t i = 0; i < s7.len(); ++i) {
        std::cout << s7[i];
    }
    std::cout << std::endl;

    // Test join
    std::vector<str> vec;
    vec.push_back(str('1'));
    vec.push_back(str('2'));
    vec.push_back(str('3'));
    str sep(", ");
    str joined = sep.join(vec);
    std::cout << "joined (1, 2, 3): length " << joined.len() << ", value: ";
    for (size_t i = 0; i < joined.len(); ++i) {
        std::cout << joined[i];
    }
    std::cout << std::endl;

    // Test empty join
    std::vector<str> empty_vec;
    str empty_joined = sep.join(empty_vec);
    std::cout << "empty join length: " << empty_joined.len() << std::endl;

    // Test single element join
    std::vector<str> single_vec;
    single_vec.push_back(str("single"));
    str single_joined = sep.join(single_vec);
    std::cout << "single join: length " << single_joined.len() << ", value: ";
    for (size_t i = 0; i < single_joined.len(); ++i) {
        std::cout << single_joined[i];
    }
    std::cout << std::endl;

    std::cout << "All tests completed successfully!" << std::endl;
    return 0;
}
