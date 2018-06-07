#ifndef _GRAMMAR_H_
#define _GRAMMAR_H_


#include <vector>
#include <string>
#include <map>
#include <iostream>

typedef std::vector<std::string> rule;
typedef std::vector<rule> rule_collection;
typedef std::map<std::string, rule_collection> grammar;

grammar read_grammar(std::istream& );
std::vector<std::string> gen_sentence(const grammar& );
bool bracketed(const std::string& );
void gen_aux(const grammar&, const std::string&, std::vector<std::string>& );

int nrand(int );

#endif
