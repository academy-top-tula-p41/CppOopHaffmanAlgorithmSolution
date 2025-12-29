#include <iostream>
#include <iomanip>
#include <format>

#include "HuffmanAlgorithm.h"

void TextBinary(std::string text);


int main()
{
    std::string text = "Hello world";

    //TextBinary(text);

    HuffmanAlgorithm ha;
    Node* root = ha.NodesTreeBuilder(text);
    ha.Encode(root);

    /*for (auto pair : ha.SymbolCodes())
        std::cout << pair.first << ": " << pair.second << "\n";*/

    std::string codeString = "";

    for (auto symbol : text)
    {
        codeString += ha.SymbolCodes()[symbol];
    }

    std::cout << codeString << "\n";

    std::string textDecode = ha.Decode(root, codeString);
    std::cout << textDecode;
}

void TextBinary(std::string text)
{
    for(auto symbol : text)
    {
        std::cout << std::format("{:#b}", (int)symbol);
    }
    std::cout << "\n";
}
