#include "xmlhelper.h"

namespace rdi
{
void XmlHelper::load(const std::string& filename)
{
    // Создаём пустой объект дерева свойств
    pt::ptree tree;

    // Парсим Xml
    pt::read_xml(filename, tree);

    // Используём вызывающую версию get, чтобы найти имя отладочного файла.
    // Если путь не может быть определен, генерируется исключение.
    m_file = tree.get<std::string>("debug.filename");

    // Используём версию get со значением по умолчанию, чтобы найти уровень отладки.
    // Обращаем внимание, что значение по умолчанию используется для определения целевого типа.
    m_level = tree.get("debug.level", 0);

    // Используем get_child, чтобы найти узел, содержащий модули, и выполнить итерацию по
    // его дочерним элементам. Если путь не может быть разрешен, get_child выдает ошибку.
    // Также сработал бы цикл C++11 for-range.
    BOOST_FOREACH (pt::ptree::value_type& v, tree.get_child("debug.modules"))
    {
        // Функция data используется для доступа к данным, хранящимся в узле.
        m_modules.insert(v.second.data());
    }
}

void XmlHelper::save(const std::string& filename)
{
    // Создаём пустой объект дерева свойств
    pt::ptree tree;

    // Помещаем простые значения в дерево. Целое число автоматически
    // преобразуется в строку. Обращаем внимание, что режим "отладки" автоматически
    // создается, если он не существует.
    tree.put("debug.filename", m_file);
    tree.put("debug.level", m_level);

    // Добавим все модули. В отличие от put, который перезаписывает существующие узлы, add
    // добавляет новый узел на самом низком уровне, поэтому узел "modules" будет иметь
    // несколько дочерних узлов "module".
    BOOST_FOREACH (const std::string& name, m_modules)
        tree.add("debug.modules.module", name);

    // Записываем дерево свойств в XML-файл
    pt::write_xml(filename, tree);
}

}  // namespace rdi
