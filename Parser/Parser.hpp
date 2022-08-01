#pragma once

#include "Defines/TokenPointer.hpp"
#include <QString>

class Parser {
	
	protected:
	bool fail;
	
	public:
	
	Parser();
	
	virtual void setSource(const QString & filename) = 0;
	
	virtual TokenPointer nextToken() = 0;
	
	virtual ~Parser();
	
};
