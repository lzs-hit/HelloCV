#include "Menu.h"
#include "Crypto.h"
#include "FileHandler.h"
#include <iostream>
#include <string>

void Menu::show() {
    while (true) {
        std::cout << "1. 文本加密\n2. 文本解密\n";
        std::cout << "3. 文件加密\n4. 文件解密\n5. 退出\n";
        std::cout << "请选择: ";
        
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        
        switch (choice) {
            case 1: textEncrypt(); break;
            case 2: textDecrypt(); break;
            case 3: fileEncrypt(); break;
            case 4: fileDecrypt(); break;
            case 5: return;
            default: std::cout << "无效选择!\n";
        }
    }
}

void Menu::textEncrypt() {
    std::string text;
    int key;
    
    std::cout << "请输入要加密的文本: ";
    std::getline(std::cin, text);
    std::cout << "请输入密钥: ";
    std::cin >> key;
    std::cin.ignore();
    
    std::string result = Crypto::encrypt(text, key);
    std::cout << "加密结果: " << result << std::endl;
}

void Menu::textDecrypt() {
    std::string text;
    int key;
    
    std::cout << "请输入要解密的文本: ";
    std::getline(std::cin, text);
    std::cout << "请输入密钥: ";
    std::cin >> key;
    std::cin.ignore();
    
    std::string result = Crypto::decrypt(text, key);
    std::cout << "解密结果: " << result << std::endl;
}

void Menu::fileEncrypt() {
    std::string path;
    int key;
    
    std::cout << "请输入文件路径: ";
    std::getline(std::cin, path);
    std::cout << "请输入密钥: ";
    std::cin >> key;
    std::cin.ignore();
    
    std::string content;
    if (FileHandler::readFile(path, content)) {
        std::string encrypted = Crypto::encrypt(content, key);
        std::string newPath = "encrypted_" + path;
        if (FileHandler::writeFile(newPath, encrypted)) {
            std::cout << "已保存到: " << newPath << std::endl;
        } else {
            std::cout << "保存失败!\n";
        }
    } else {
        std::cout << "读取文件失败!\n";
    }
}

void Menu::fileDecrypt() {
    std::string path;
    int key;
    
    std::cout << "请输入文件路径: ";
    std::getline(std::cin, path);
    std::cout << "请输入密钥: ";
    std::cin >> key;
    std::cin.ignore();
    
    std::string content;
    if (FileHandler::readFile(path, content)) {
        std::string decrypted = Crypto::decrypt(content, key);
        std::string newPath = "decrypted_" + path;
        if (FileHandler::writeFile(newPath, decrypted)) {
            std::cout << "已保存到: " << newPath << std::endl;
        } else {
            std::cout << "error\n";
        }
    } else {
        std::cout << "error!";
    }
}
