#include "FileManager.h"

#include <algorithm>
#include <string>

std::map<std::string, Config> config_map = {
    { "screen_size", Config::screen_size },
    { "window_name", Config::window_name },
    { "cam_mov", Config::cam_mov },
};

void FileManager::GetConfigFromFile()
{
    std::ifstream* tmp = new std::ifstream(config_file_name);
    std::string* current_line = new std::string;
    std::pair<Config, std::string>* curren_config = new std::pair<Config, std::string>;

    if (tmp->is_open()) {
        while (std::getline(*tmp, *current_line)) {

            // ignoring comments
            if (current_line->at(0) == '#')
                continue;

            bool is_reading_value = false;

            std::string* tmp_conf = new std::string;
            std::string* tmp_value = new std::string;

            for (auto c : *current_line) {

                if (c == ' ')
                    continue;

                if (c == '=') {
                    is_reading_value = true;
                    continue;
                }

                if (is_reading_value) {
                    tmp_value->push_back(c);
                } else {
                    tmp_conf->push_back(c);
                }
            }
        }
    }

    delete tmp;
}
