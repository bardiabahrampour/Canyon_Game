#include "FileManager.h"

#include "Common.h"
#include <algorithm>
#include <string>

std::map<const char*, Config> conf_str_table = {
    { "screen_size", Config::screen_size },
    { "window_name", Config::window_name },
    { "cam_mov", Config::cam_mov },
};

void FileManager::GetConfigFromFile()
{
    std::ifstream tmp(config_file_name);
    std::string current_line;
    Config conf = Config::null;

    if (tmp.is_open()) {
        while (std::getline(tmp, current_line)) {

            // ignoring comments
            if (current_line.at(0) == '#')
                continue;

            bool is_reading_value = false;

            std::string tmp_conf;
            std::string tmp_value;

            for (auto c : current_line) {

                if (c == ' ')
                    continue;

                if (c == '=') {
                    is_reading_value = true;
                    continue;
                }

                if (is_reading_value) {
                    tmp_value.push_back(c);
                } else {
                    tmp_conf.push_back(c);
                }
            }

            if (auto search = conf_str_table.find(tmp_conf.c_str()); search != conf_str_table.end()) {
                conf = search->second;
            } else {

            }
            this->values[conf] = tmp_value;
            _log::info("{0},{1}",tmp_value,this->values[conf]);
        }
    } else {
        
    }
}


int FileManager::GetInt(std::string& key)
{
    return 0;
}

double FileManager::GetDouble(std::string& key)
{
    return 0;
}

Vector2 FileManager::GetVector2(std::string& key)
{
    Vector2 a = { 0, 0 };
    return a;
}

std::string FileManager::GetString(std::string& key)
{
    return nullptr;
}