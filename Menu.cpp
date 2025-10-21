#include "Menu.h"
#include "Crypto.h"
#include "FileHandler.h"
#include <iostream>
#include <string>

void Menu::show() {
    while (1) {
        std::cout << "1. 文本加密\n2. 文本解密\n";
        std::cout << "3. 文件加密\n4. 文件解密\n5. 退出\n";
        std::cout << "请选择: ";
        
        int n;
        std::cin >> n;
        std::cin.ignore();
        
        switch (n) {
            case 1: tE(); break;
            case 2: tD(); break;
            case 3: fE(); break;
            case 4: fD(); break;
            case 5: return;
            default: std::cout << "无效选择!\n";
        }
    }
}

void Menu::tE() {
    std::string s1;
    int a;
    
    std::cout << "请输入要加密的文本: ";
    std::getline(std::cin, s1);
    std::cout << "请输入密钥: ";
    std::cin >> a;
    std::cin.ignore();
    
    std::string result = Crypto::encrypt(s1, a);
    std::cout << "加密结果: " << result << std::endl;
}

void Menu::tD() {
    std::string s2;
    int b;
    
    std::cout << "请输入要解密的文本: ";
    std::getline(std::cin, s2);
    std::cout << "请输入密钥: ";
    std::cin >> b;
    std::cin.ignore();
    
    std::string result = Crypto::decrypt(s2, b);
    std::cout << "解密结果: " << result << std::endl;
}

void Menu::fE() {
    std::string p1;
    int c;
    
    std::cout << "请输入文件路径: ";
    std::getline(std::cin, p1);
    std::cout << "请输入密钥: ";
    std::cin >> c;
    std::cin.ignore();
    
    std::string s3;
    if (FileHandler::readFile(p1, s3)) {
        std::string New = Crypto::encrypt(s3, c);
        std::string np = "encrypted_" + p1;
        if (FileHandler::writeFile(np, New)) {
            std::cout << "已保存到: " << np << std::endl;
        } else {
            std::cout << "保存失败!\n";
        }
    } else {
        std::cout << "读取文件失败!\n";
    }
}

void Menu::fD() {
    std::string p2;
    int d;
    
    std::cout << "请输入文件路径: ";
    std::getline(std::cin, p2);
    std::cout << "请输入密钥: ";
    std::cin >> d;
    std::cin.ignore();
    
    std::string s4;
    if (FileHandler::readFile(p2, s4)) {
        std::string New = Crypto::decrypt(s4, d);
        std::string np = "decrypted_" + p2;
        if (FileHandler::writeFile(np, New)) {
            std::cout << "已保存到: " << np << std::endl;
        } else {
            std::cout << "error\n";
        }
    } else {
        std::cout << "error!";
    }
}
