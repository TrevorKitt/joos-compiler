#include "scanner.h"
#include "identifierDfa.h"
#include "validNumberDfa.h"
#include "operatorDfa.h"
#include "separatorDfa.h"
#include "charStringLiteralDfa.h"
#include "keywordDfa.h"
#include "singleCommentDfa.h"
#include "multiCommentDfa.h"
#include "whitespaceAndControlDfa.h"

#include <iostream>
#include <cassert>
#include <string>

Scanner::Scanner()
{
    // Dfas must be ordered in reverse priority.
    // Dfas that are later in the list will have priority over earlier Dfas
    dfas.push_back(new WhitespaceAndControlDfa());
    dfas.push_back(new SingleCommentDfa());
    dfas.push_back(new MultiCommentDfa());
    dfas.push_back(new IdentifierDfa());
    dfas.push_back(new ValidNumberDfa());
    dfas.push_back(new OperatorDfa());
    dfas.push_back(new SeparatorDfa());
    dfas.push_back(new CharStringLiteralDfa());
    dfas.push_back(new KeywordDfa());
}

int Scanner::Scan(std::ifstream& file, std::vector<Token*> *tokens)
{
    int c = -2;
    
    int numDfas = this->dfas.size();
    int errorCount = 0;
    std::vector<int> errorFlags(numDfas, 0);
    std::pair<DFA_STATES, TOKEN_TYPE> result;
    
    //Values for the token currently being scanned
    TOKEN_TYPE type = TT_INVALID;
    std::string lexime = "";
    int tokenLine = 0; 
    int tokenCollumn = 0; 
    
    int currentLine = 0;
    int currentColumn = -1;
    
    while (file) {
        if (c == -2) {
            c = file.get();
            currentColumn++;
    
            // EOF is represented as -1
            // ASCII is from 0 to 127
            if (c < -1 || c > 127) {
                std::cerr << "Invalid character with code: " 
                          << c 
                          << "\n Input files must contain only ASCII characters";
                return -1;
            }

            // Line feed character LF
            if(c == 10) {
                currentLine++;
                currentColumn = -1;
            }
        }

        // Dfas must be ordered in reverse priority.
        // Dfas that are later in the list will have priority over earlier Dfas
        for (int i = 0; i < numDfas; i++) {
            if (errorFlags[i] == 0) {
                result = dfas[i]->transition((char)c);
                switch (result.first) {
                    case DS_ACCEPT:
                        type = result.second;
                        break;
                    case DS_ERROR:
                        errorFlags[i] = 1;
                        errorCount++;
                        break;
                    default:
                        break;
                }
            }
        }

        // Sanity Check
        assert(errorCount <= numDfas); 

        if (errorCount == numDfas) {
        
            if(type == TT_INVALID){
                std::cerr << "Invalid token with lexime: " << lexime << (char)c << "\n";
                return -2;
            }
        
            if(type != TT_COMMENT && type != TT_WHITESPACE) {
                tokens->push_back(new Token(type, lexime, std::pair <unsigned int, unsigned int>(tokenLine, tokenCollumn)));
            }

            // Reset all the things!!!
            type = TT_INVALID;
            lexime = "";
            errorCount = 0;    
            tokenLine = currentLine;
            tokenCollumn = currentColumn;

            for(int i = 0; i < numDfas; i++) {
                dfas[i]->resetDfa();
                errorFlags[i] = 0;
            }
        } else {
            lexime += (char)c;
            c = -2;
        }
    }
    
    return 0;
}