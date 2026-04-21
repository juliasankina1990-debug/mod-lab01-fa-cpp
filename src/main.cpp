// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    const char *s1 = "qwe4  gftt e 555gr rrgr  grhh ";
    std::cout << "faStr1(\"" << s1 << "\") = " << faStr1(s1) << std::endl;

    const char *s2 = "Hello world!";
    std::cout << "faStr2(\"" << s2 << "\") = " << faStr2(s2) << std::endl;

    const char *s3 = " bad dog ";
    std::cout << "faStr3(\"" << s3 << "\") = " << faStr3(s3) << std::endl;

    const char *s4 = " six monkeys";
    std::cout << "faStr3(\"" << s4 << "\") = " << faStr3(s4) << std::endl;

    return 0;
}
