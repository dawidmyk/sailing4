#pragma once

#include <QString>
#include <memory>

typedef QString * StringPointer;

typedef const QString * ConstStringPointer;

typedef std::unique_ptr<QString> StringUniquePointer;
