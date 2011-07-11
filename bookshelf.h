#ifndef _BOOKSHELF_
#define _BOOKSHELF_

#include <QtCore/QList>

#include "mobi.h"

class Bookshelf
{
  public:

    void scanDirectory(QString);
    Mobi * getBook(int);
    int numBooks();
    
  protected:

    QList<Mobi *> books;
    
};

extern Bookshelf * bookshelf;

#endif