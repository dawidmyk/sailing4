#include "Context/Context.hpp"
#include "Defines/TokenPointer.hpp"
#include "Token/QuestionToken.hpp"
#include "Parser/JsonParser.hpp"

Context::Context(const ConstStringListPointer entryList): iterator(entryList->constBegin()), end(entryList->constEnd())
	{
	}
	
void Context::makeJsonParser() {
	parser.reset(new JsonParser);
}

bool Context::nextTest() {
	if(iterator != end) {
		parser->setSource(**iterator);
		++iterator;
		return true;
	}
	return false;
}

NextQuestionResult Context::nextQuestion(QuestionUniquePointer * const question) {
	TokenUniquePointer token(parser->nextToken());
	if(token->isQuestion()) {
		question->reset((static_cast<QuestionToken *>(token.get()))->takeQuestion());
		return NextQuestionResult::success;
	}
	if(token->isEnd())
		return NextQuestionResult::end;
	
	return NextQuestionResult::fail;
}
