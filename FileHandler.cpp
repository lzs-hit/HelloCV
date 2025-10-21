#include "FileHandler.h"
#include <fstream>
#include <sstream>

bool FileHandler::readFile(const std::string& path, std::string& content) {
    std::ifstream file(path);
    if (!file) return false;
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    content = buffer.str();
    return true;
}

bool FileHandler::writeFile(const std::string& path, const std::string& content) {
    std::ofstream file(path);
    if (!file) return false;
    
    file << content;
    return true;
}
