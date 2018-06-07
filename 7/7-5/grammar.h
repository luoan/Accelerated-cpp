#ifndef _GRAMMAR_H_
#define _GRAMMAR_H_



#include <list>
#include <string>
#include <map>
#include <iostream>

typedef std::list<std::string> rule;
typedef std::list<rule> rule_collection;
typedef std::map<std::string, rule_collection> grammar;

grammar read_grammar(std::istream& );
std::list<std::string> gen_sentence(const grammar& );
bool bracketed(const std::string& );
void gen_aux(const grammar&, const std::string&, std::list<std::string>& );

int nrand(int );

#endif
