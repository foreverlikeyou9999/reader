#ifndef _DICTIONARYFILTER_
#define _DICTIONARYFILTER_

#include "filter.h"
#include "dictionary.h"

class DictionaryFilter : public Filter
{
  public:
    
    DictionaryFilter(Dictionary *);
    
    virtual bool handlesTouch()
    {
        return true;
    }
    
    virtual QString name() 
    {
        return "Dictionary";
    }
    
    virtual void beforeLayout(ParagraphElement *) {}
    virtual void afterLayout(ParagraphElement *) {}    
    virtual void onPress(ParagraphElement *, Page *, qint64, qint64) {}
    virtual void onRelease(ParagraphElement *, Page *, qint64 x, qint64 y);
    virtual bool handlesMouse() { return true; }
    
  protected:

    Dictionary * dictionary;
    
};

#endif
