#pragma once

#include "raywin.h"
#include <fstream>
#include <map>
#include <raylib.h>
#include <vector>

constexpr const char* config_file_name = "config.cfg";

enum class Config {
    screen_size,
    window_name,
    cam_mov,
    null,
};

enum class Config_Error {
    property_not_found,
    config_file_not_found,
};

struct FileManager {
    /*
         CANNOT throw exceptions !
         if an error occurs it will load
         default settings and notify the user
 */
    void GetConfigFromFile();
    int GetInt(std::string& key);
    std::string GetString(std::string& key);
    double GetDouble(std::string& key);
    Vector2 GetVector2(std::string& key);

private:
    std::map<Config, std::string> values = {
        { Config::screen_size, "1920x1080" },
        { Config::window_name, "Untitled" },
        { Config::cam_mov, "0.05" },
    };
};
