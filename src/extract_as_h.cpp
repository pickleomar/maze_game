#include "raylib.h"
#include <cstring>

#include <filesystem>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
namespace fs = std::filesystem;

int main() {

  std::vector<std::string> folders;
  std::vector<std::string> filenames;
  std::string path = "./Resources";
  for (const auto &entry : fs::directory_iterator(path)) {
    folders.push_back(entry.path());
  }

  for (const std::string &folder : folders) {
    if (folder != "./Resources/audio") {
      for (const auto &file : fs::directory_iterator(folder)) {
        filenames.push_back(file.path());
      }
    }
  }

  int length;
  Image img;

  for (const std::string &filename : filenames) {
    img = LoadImage(filename.c_str());
    length = filename.length();
    ExportImageAsCode(img, filename.substr(12, length - 12 - 4)
                               .insert(0, "./src/resources/")
                               .append(".h")
                               .c_str());
    UnloadImage(img);
  }
}
