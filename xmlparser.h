#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <string>
#include <vector>
#include <boost/property_tree/detail/rapidxml.hpp>

using namespace std;


class XmlParser
{
public:
    XmlParser();
    bool parseXml(const string &input_xml);
    string createXml(std::string *input_xml);
    string readFile(const string &fileName);

private:



};

#endif // XMLPARSER_H
