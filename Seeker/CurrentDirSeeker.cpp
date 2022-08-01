#include "CurrentDirSeeker.hpp"
#include <QDir>

StringListPointer CurrentDirSeeker::takeEntryList() {
	QDir dir(".");
	const QStringList stringList = dir.entryList();
	const StringListPointer entries = new StringList;
	QStringListIterator iterator(stringList);
	while(iterator.hasNext()) {
		StringUniquePointer newString(new QString(iterator.next()));
		if(newString->endsWith(".test"))
			entries->append(newString.release());
	}
	
	return entries;

}

CurrentDirSeeker::~CurrentDirSeeker() {
}
