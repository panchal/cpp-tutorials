#ifndef XMLPROCESSOR_SMART_H
#define XMLPROCESSOR_SMART_H

#include "xmlstubs.h"

#include <memory>
#include <boost/shared_ptr.hpp>

// Implementation option #1 with auto_ptr
//
//	Here we deny copy operations, which is probably appropriate
//	for an XML processor object.  We've achieved exception safety
//	and automatic cleanup.
//	Note use of a std::string for the message.

class XMLProcessorAuto {
public:
	XMLProcessorAuto();
	~XMLProcessorAuto();
private:
	XMLProcessorAuto( const XMLProcessorAuto & );
	XMLProcessorAuto &operator =( const XMLProcessorAuto & );
    std::auto_ptr<DOMParser> parser;
    std::auto_ptr<ErrorHandler> errHandler; 
    std::auto_ptr<DOMDocument> doc;
    std::auto_ptr<DOMElement> element;
    std::string xmlMsg; 
};

XMLProcessorAuto::XMLProcessorAuto()
	: parser( new DOMParser ),
	errHandler( new ErrorHandler ),
	doc( new DOMDocument ),
	element( 0 )
	{}

XMLProcessorAuto::~XMLProcessorAuto()
    {}

// Implementation option #2 with tr1::shared_ptr
//
//	Here we allow copy operations, which are automatically
//	generated by the compiler to share the components.  An
//	alternative would be to deny copy operations, or implement
//	them to make a copy of non-shared components.

class XMLProcessorShared {
public:
	XMLProcessorShared();
	~XMLProcessorShared();
private:
    boost::shared_ptr<DOMParser> parser;
    boost::shared_ptr<ErrorHandler> errHandler; 
    boost::shared_ptr<DOMDocument> doc;
    boost::shared_ptr<DOMElement> element;
    std::string xmlMsg; 
};

XMLProcessorShared::XMLProcessorShared()
	: parser( new DOMParser ),
	errHandler( new ErrorHandler ),
	doc( new DOMDocument )
	{}

XMLProcessorShared::~XMLProcessorShared()
    {}

#endif
