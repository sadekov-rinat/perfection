#include <string>
#include <iostream>
#include "xmlparser.h"
#include "dbmanager.h"

using namespace std;

int main(int argc, char *argv[])
{
    dbmanager db("test","rinat","05203");
    XmlParser *xml_parser = new XmlParser();
    string in = xml_parser->readFile("command.txt");
    xml_parser->parseXml(in);

    db.autorization("sadekov","12345678");
    return 0;
}

