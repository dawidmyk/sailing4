#pragma once

#include "Defines/StringPointer.hpp"
#include <QList>

class StringList : public QList<StringPointer> {
	
	public:
	
	~StringList();
	
};
