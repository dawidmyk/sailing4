#pragma once

class Token {
	
	public:
	
	virtual bool isFail() const;
	
	virtual bool isEnd() const;
	
	virtual bool isQuestion() const;
	
	virtual ~Token();

};
