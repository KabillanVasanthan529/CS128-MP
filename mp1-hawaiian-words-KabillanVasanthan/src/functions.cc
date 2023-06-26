#include "functions.hpp"
#include <string>
#include <cctype>
#include <iostream>

std::string VowelsFirst(std::string word, unsigned int i) {
    std::string new_word;
    switch(tolower(word.at(i))) {
        case ('a') : {
            if (i != word.length() - 1 && (tolower(word.at(i + 1)) == 'i' || tolower(word.at(i + 1)) == 'e')) {
                new_word += "eye";
            } else if (i != word.length() - 1 && (tolower(word.at(i + 1)) == 'o' || tolower(word.at(i + 1)) == 'u')) {
                new_word += "ow";
            } else {
                new_word += "ah";
            }
            if((i != word.length() - 1 && !((new_word == "eye" || new_word == "ow") && i == word.length() - 2)) && word.at(i + 1) != '\'' && word.at(i + 1) != ' ') 
                new_word += '-';
            break;
        }
        case ('i') : {
            if (i != word.length() - 1 && (tolower(word.at(i + 1)) == 'u')) {
                new_word += "ew";
            } else {
                new_word += "ee";
            }
            if ((i != word.length() - 1 && !(new_word == "ew" && i == word.length() - 2)) && word.at(i + 1) != '\'' && word.at(i + 1) != ' ') 
                new_word += '-';
            break;
        }
        case ('e') : {
            if (i != word.length() - 1 && (tolower(word.at(i + 1)) == 'i')) {
                new_word += "ay";
            } else if(i != word.length() - 1 && (tolower(word.at(i + 1)) == 'u')) {
                new_word += "eh-oo";
            } else {
                new_word += "eh";
            }
            if((i != word.length() - 1 && !((new_word == "ay" || new_word == "eh-oo") && i == word.length() - 2)) && word.at(i + 1) != '\'' && word.at(i + 1) != ' ') 
                new_word += '-';
            break;
        }
    }
    return new_word;
}
std::string VowelsSecond(std::string word, unsigned int i) {
    std::string new_word;
    switch(tolower(word.at(i))) {
        case ('o') : {
            if (i != word.length() - 1 && (tolower(word.at(i + 1)) == 'i')) {
                new_word += "oy";
            } else if(i != word.length() - 1 && (tolower(word.at(i + 1)) == 'w')) {
                new_word += "ow";
            } else {
                new_word += "oh";
            }
            if((i != word.length() - 1 && !((new_word == "oy" || new_word == "ow") && i == word.length() - 2)) && word.at(i + 1) != '\'' && word.at(i + 1) != ' ') {
                new_word += '-';
            }
            break;
        }
        case ('u') : {
            if (i != word.length() - 1 && (tolower(word.at(i + 1)) == 'i')) {
                new_word += "ooey";
                i++;
            } else {
                new_word += "oo";
            }
            if((i != word.length() - 1 && !(new_word == "ooey" && i == word.length() - 2)) && word.at(i + 1) != '\'' && word.at(i + 1) != ' ') {
                new_word += '-';
            }
            break;
        }
    }
    return new_word;
}
std::string Consonants(std::string word, unsigned int i) {
    std::string new_word;
    switch(tolower(word.at(i))) {
        case 'p': case 'k': case 'h': case 'l': case 'm': case 'n': case ' ': case '\'': {
            new_word += char(tolower(word.at(i))); 
            break;
        }
        case ('w'): {
            if(i != 0 && (tolower(word.at(i - 1)) == 'i' || tolower(word.at(i-1)) == 'e')) {
                new_word += char(tolower('v'));
                break;
            }
            new_word += char(tolower(word.at(i))); 
            break;
        }
        
    }
    return new_word;
}


std::string ToHawaiian(std::string word) {
    std::string new_word;
    unsigned int j = 0;
    for (unsigned int i = 0; i < word.length(); i++) {
        j = i;

        if (tolower(word.at(i)) != 'p' && tolower(word.at(i)) != 'k' && tolower(word.at(i)) != 'h' && tolower(word.at(i)) != 'l' && tolower(word.at(i)) != 'm' && tolower(word.at(i)) != 'n' && 
        tolower(word.at(i)) != 'w' && tolower(word.at(i)) != 'a' && tolower(word.at(i)) != 'i' && tolower(word.at(i)) != 'e' && tolower(word.at(i)) != 'o' && tolower(word.at(i)) != 'u' &&
        tolower(word.at(i)) != '\'' && tolower(word.at(i)) != ' ') {
            return word + " contains a character not a part of the Hawaiian language.";
        }
        
        new_word += VowelsFirst(word, i);
        new_word += VowelsSecond(word, i);
        new_word += Consonants(word, i);
        if (VowelsFirst(word,j).find("eye") != std::string::npos || VowelsFirst(word,j).find("ow") != std::string::npos || VowelsFirst(word,j).find("ay") != std::string::npos
        || VowelsFirst(word,j).find("eh-oo") != std::string::npos || VowelsFirst(word,j).find("ew") != std::string::npos || VowelsFirst(word,j).find("oy") != std::string::npos
        || VowelsFirst(word,j).find("ooey") != std::string::npos) {
            i++;
        }
        if (VowelsSecond(word,j).find("eye") != std::string::npos || VowelsSecond(word,j).find("ow") != std::string::npos || VowelsSecond(word,j).find("ay") != std::string::npos
        || VowelsSecond(word,j).find("eh-oo") != std::string::npos || VowelsSecond(word,j).find("ew") != std::string::npos || VowelsSecond(word,j).find("oy") != std::string::npos
        || VowelsSecond(word,j).find("ooey") != std::string::npos) {
            i++;
        }
    }
    return new_word;


}


















/*

std::string ToHawaiian(std::string word) {
    std::string new_word;
    for (unsigned int i = 0; i < word.length(); i++) {
        switch(tolower(word.at(i))) {
            case 'p': case 'k': case 'h': case 'l': case 'm': case 'n': case ' ': case '\'': {
                new_word += char(tolower(word.at(i))); 
                break;
            }
            case ('w'): {
                if(i != 0 && (tolower(word.at(i - 1)) == 'i' || tolower(word.at(i-1)) == 'e')) {
                    new_word += char(tolower('v'));
                    break;
                }
                new_word += char(tolower(word.at(i))); 
                break;
            }
            case ('a') : {
                if (i != word.length() - 1 && (tolower(word.at(i + 1)) == 'i' || tolower(word.at(i + 1)) == 'e')) {
                    new_word += "eye";
                    i++;
                } else if (i != word.length() - 1 && (tolower(word.at(i + 1)) == 'o' || tolower(word.at(i + 1)) == 'u')) {
                    new_word += "ow";
                    i++;
                } else {
                    new_word += "ah";
                }
                if(i != word.length() - 1 && word.at(i + 1) != '\'' && word.at(i + 1) != ' ') {
                    new_word += '-';
                }
                break;
            }
            case ('i') : {
                if (i != word.length() - 1 && (tolower(word.at(i + 1)) == 'u')) {
                    new_word += "ew";
                    i++;
                } else {
                    new_word += "ee";
                }
                if (i != word.length() - 1 && word.at(i + 1) != '\'' && word.at(i + 1) != ' ') {
                    new_word += '-';
                }
                break;
            }
            case ('e') : {
                if (i != word.length() - 1 && (tolower(word.at(i + 1)) == 'i')) {
                    new_word += "ay";
                    i++;
                } else if(i != word.length() - 1 && (tolower(word.at(i + 1)) == 'u')) {
                    new_word += "eh-oo";
                    i++;
                } else {
                    new_word += "eh";
                }
                if(i != word.length() - 1 && word.at(i + 1) != '\'' && word.at(i + 1) != ' ') {
                    new_word += '-';
                }
                break;
            }
            case ('o') : {
                if (i != word.length() - 1 && (tolower(word.at(i + 1)) == 'i')) {
                    new_word += "oy";
                    i++;
                } else if(i != word.length() - 1 && (tolower(word.at(i + 1)) == 'w')) {
                    new_word += "ow";
                    i++;
                } else {
                    new_word += "oh";
                }
                if(i != word.length() - 1 && word.at(i + 1) != '\'' && word.at(i + 1) != ' ') {
                    new_word += '-';
                }
                break;
            }
            case ('u') : {
                if (i != word.length() - 1 && (tolower(word.at(i + 1)) == 'i')) {
                    new_word += "ooey";
                    i++;
                } else {
                    new_word += "oo";
                }
                if(i != word.length() - 1 && word.at(i + 1) != '\'' && word.at(i + 1) != ' ') {
                    new_word += '-';
                }
                break;
            }
            default: {
                return word + " contains a character not a part of the Hawaiian language.";
                break;
            }
            
        }
    }
    return new_word;


    
    


}

*/

