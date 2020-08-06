#include "../include/TriggerLateStudy.h"
#include <iostream>
#include <stdlib.h>
#include <typeinfo>

int main(int argc, char *argv[])
{
    std::cout<<"<<Run START>>"<<std::endl;
    TChain *tree1 = new TChain("physics", "physics");
    tree1->Add(argv[1]);
    TriggerLateStudy tls(tree1);
    tls.Loop();

    return 0;
}
