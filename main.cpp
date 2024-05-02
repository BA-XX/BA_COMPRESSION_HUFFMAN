#include <iostream>
#include <conio.h>
#include "header.hpp"

using namespace ba;

void printStart()
{
    std::cout << R"(
  ___   _     _  _ _   _ ___ ___ __  __   _   _  _ 
 | _ ) /_\   | || | | | | __| __|  \/  | /_\ | \| |
 | _ \/ _ \  | __ | |_| | _|| _|| |\/| |/ _ \| .` |
 |___/_/ \_\_|_||_|\___/|_| |_| |_|  |_/_/ \_\_|\_|
          |___|                               @BA_XX
       << Compress text using huffman algorithme >>

    )" << std::endl;
}

int main()
{

    BA_Huffman huffman;
    string input;

    printStart();

    std::cout << "Enter text : ";
    std::getline(std::cin, input);

    huffman.setInput(input);

    huffman_result_t output = huffman.compress();

    std::cout << "-------------------- [ Result ] -------------------------" << std::endl;

    size_t origSize = huffman.getInput().size() * 8; // char -> 8 bit
    size_t newSize = output.encoded.size();

    std::cout << "Input (size : " << origSize << " bit) : " << huffman.getInput() << std::endl;
    std::cout << "Compressed text est : (size : " << newSize << " bit) : " << output.encoded << std::endl;

    std::cout << "Compression Rate : " << (1 - (float)newSize / origSize) * 100 << "%" << std::endl;
    std::cout << "Codes: " << output.codes << std::endl;

    std::cout << "Serialized Huffman Tree: " << output.serializedHuffmanTree << std::endl;

    std::cout << "-------------- Press enter to quit --------------";
    getch();
}