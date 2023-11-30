#pragma once

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <set>
#include <exception>
#include <iostream>

namespace pt = boost::property_tree;

namespace rdi
{
class XmlHelper
{
public:
    std::string m_file;               // имя файла журнала
    int m_level;                      // уровень отладки
    std::set<std::string> m_modules;  // модули, в которых включено ведение журнала
    void load(const std::string& filename);
    void save(const std::string& filename);
};
}  // namespace rdi
