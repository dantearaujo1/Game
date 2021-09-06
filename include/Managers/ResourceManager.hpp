#pragma once

#include <iostream>
#include <map>

template <class T> class ResourceManager {

public:
  ResourceManager() { m_directory = ""; }
  ResourceManager(const std::string &folderPath) { m_directory = folderPath; }
  ~ResourceManager() {
    while (!m_resources.empty()){
      delete m_resources.begin()->second;
      m_resources.erase(m_resources.begin());
    }
    delete m_joker;
    m_joker = nullptr;
  }

  void loadFromFile(const std::string &name, const std::string &path) {
    if (!(m_resources.find(name) != m_resources.end())) {
      T *temp = new T();
      if (!temp->loadFromFile(m_directory + path)) {
        std::cout << "Resource not loaded!" << std::endl;
        return;
      }
      m_resources[name] = temp;
      std::cout << "Resource loaded from: " << m_directory << path << " with id: " << name << std::endl;
      temp = nullptr;
    }
    else{
      std::cout << "There is a file with that ID already" << std::endl;
    }
  }
  T *getResource(const std::string &name) {
    if (m_resources.find(name) != m_resources.end()) {
      std::cout << "Using texture id: " << name << std::endl;
      return m_resources[name];
    }
    std::cout << "Using m_joker to the texture" << std::endl;
    return m_joker;
  }
  void loadJokerfromFile(const std::string &path) {
    if (!m_joker->loadFromFile(m_directory + path)) {
      std::cout << "Joker not loaded!" << std::endl;
    }
  }
  void setDirectory(const std::string &path) { m_directory = path; }

private:
  std::map<const std::string, T *> m_resources;
  T *m_joker;
  std::string m_directory;
};
