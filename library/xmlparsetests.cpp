#include "xmlparsetests.h"

namespace rdi
{
XmlParseTests::XmlParseTests() noexcept {}

XmlParseTests::XmlParseTests(const std::string& configPath) { load(configPath); }

void XmlParseTests::load(const std::string& configPath)
{
    pt::read_xml(configPath, tree);
    std::cout << "Opening config " << configPath << std::endl;
}

XmlParseTests::Tests XmlParseTests::leetCode(const std::string& title_problem, LeetCode difficulty) const
{
    std::cout << "Trying to load tests " << title_problem << std::endl;
    switch (difficulty)
    {
        case LeetCode::Easy:
            return loadTests("tests.leetcode.easy.t" + title_problem);
        case LeetCode::Medium:
            return loadTests("tests.leetcode.medium.t" + title_problem);
        case LeetCode::Hard:
            return loadTests("tests.leetcode.hard.t" + title_problem);
    }
    return Tests();
}

XmlParseTests::Tests XmlParseTests::leetCodeEasy(const std::string& title_problem) const
{
    return leetCode(title_problem, LeetCode::Easy);
}

XmlParseTests::Tests XmlParseTests::leetCodeMedium(const std::string& title_problem) const
{
    return leetCode(title_problem, LeetCode::Medium);
}

XmlParseTests::Tests XmlParseTests::leetCodeHard(const std::string& title_problem) const
{
    return leetCode(title_problem, LeetCode::Hard);
}

XmlParseTests::Tests XmlParseTests::loadTests(const std::string& path) const
{
    Tests tests;
    try
    {
        BOOST_FOREACH (const pt::ptree::value_type& test, tree.get_child(path))
        {
            tests.insert(test.second.data());
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::size_t number = 1;
    for (const Test& test : tests)
    {
        std::cout << "\tTest №" << number++ << ": " << test << std::endl;
    }
    return tests;
}

}  // namespace rdi
