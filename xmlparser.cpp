#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>

#include "xmlparser.h"

using namespace std;
using namespace boost;
using namespace boost::property_tree;

const ptree& empty_ptree(){
    static ptree t;
    return t;
}

/**
@brief              Class for wrapping/unpacking xml command
*/
XmlParser::XmlParser() {

}

/**
@brief              Read file includes simple xml code for testing xml class
@param[in] fileName Name of file which includes xml code
@retval             Return string which includes xml code
*/
bool XmlParser::parseXml(const string &input_xml) {
    // create tree
    ptree tree;
    stringstream stream(input_xml);
    try {
        // filling tree
        read_xml(stream, tree);
        const ptree & formats = tree.get_child("packet", empty_ptree());
        // find nodes
        BOOST_FOREACH(const ptree::value_type & f, formats) {
            string at = f.first + ".<xmlattr>";
            cout << "." << f.first << endl;
            // find attributes
            const ptree & attributes = f.second.get_child("<xmlattr>", empty_ptree());
            BOOST_FOREACH(const ptree::value_type &v, attributes){
                cout << v.first.data() << ": " << v.second.data() << endl;
                //sql request

           }
        }
    }
    catch (...) {
        cout << "xml command error" << endl;
        return false;
    }
    return true;
}

/**
@brief              Get connection by name
@param[in] connName Connection name to find
@retval             Iterator to connection object or vector end
*/
string XmlParser::createXml(std::string *input_xml) {

    /*xml_document<> doc;
    // root node
    xml_node<>* root = doc.allocate_node(node_element, "packet");
    doc.append_node(root);

    // header node
    xml_node<>* child = doc.allocate_node(node_element, "header");
    child->append_attribute(doc.allocate_attribute("method", "add"));
    child->append_attribute(doc.allocate_attribute("command", "0001"));
    root->append_node(child);


    for (int i = 1; i++; i<4) {
        xml_node<>* child = doc.allocate_node(node_element, "data");
        child->append_attribute(doc.allocate_attribute("idx", "i"));
        child->append_attribute(doc.allocate_attribute("num", "4"));
        child->append_attribute(doc.allocate_attribute("email", "@mail.ru"));
        child->append_attribute(doc.allocate_attribute("fio", "Ivanov"));
        child->append_attribute(doc.allocate_attribute("group_number", "4"));
        root->append_node(child);
    }


    string xml_as_string;
    // watch for name collisions here, print() is a very common function name!
    //printf(back_inserter(xml_as_string), doc);
    // xml_as_string now contains the XML in string form, indented
    // (in all its angle bracket glory)

    std::string xml_no_indent;
    // print_no_indenting is the only flag that print() knows about
    //cout << std::back_inserter(xml_no_indent) << doc << print_no_indenting;
    // xml_no_indent now contains non-indented XML
    */
    return "true";
}

/**
@brief              Read file includes simple xml code for testing xml class
@param[in] fileName Name of file which includes xml code
@retval             Return string which includes xml code
*/
string XmlParser::readFile(const string &fileName) {
    ifstream ifs(fileName.c_str());
    ostringstream out;
    out  << ifs.rdbuf();
    cout << out.str() << endl;
    return out.str();
}
