#pragma once

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <set>
#include <exception>
#include <iostream>

namespace rdi
{
enum class LeetCode
{
    Easy = 0,
    Medium = 1,
    Hard = 2
};

namespace pt = boost::property_tree;
class XmlParseTests
{
public:
    using Test = std::string;
    using Tests = std::set<std::string>;

public:
    XmlParseTests() noexcept;
    explicit XmlParseTests(const std::string& configPath);

public:
    void load(const std::string& configPath);

public:
    Tests leetCode(const std::string& title_problem, LeetCode difficulty) const;
    Tests leetCodeEasy(const std::string& title_problem) const;
    Tests leetCodeMedium(const std::string& title_problem) const;
    Tests leetCodeHard(const std::string& title_problem) const;

private:
    Tests loadTests(const std::string& path) const;

private:
    pt::ptree tree;
};
}  // namespace rdi
