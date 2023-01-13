#include "FileManager.h"

#include <string>

/*
    again a quick fix that
    should ABOSOLUTELY be changed
*/
std::vector<std::string> FileManager::GetInputImplFile() {

  std::vector<std::string> return_str{};

  std::string tmp_str{};

  std::ifstream tmp_file("keymaps.cfg");

  while (std::getline(tmp_file, tmp_str)) {
    return_str.push_back(tmp_str);
  }

  return return_str;
}