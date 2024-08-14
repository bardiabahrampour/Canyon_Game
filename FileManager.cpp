#include "FileManager.h"

#include <string>

void FileManager::GetConfigFromFile()
{
    std::ifstream* tmp = new std::ifstream(config_file_name);
    std::string* current_line = new std::string;
    std::pair<std::string, std::string> current_config;

    if (tmp->is_open()) {
        while (std::getline(*tmp, *current_line)) {
            //ignoring comments
            if (current_line->at(0) == '#')
                continue;
            if (current_line->at(0) == '/' && current_line->at(1) == '/')
                continue;


        }
    }

    delete tmp;
}
