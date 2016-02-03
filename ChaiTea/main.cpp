//
//  main.cpp
//  ChaiTea
//
//  Created by Dennis Lysenko on 1/22/16.
//  Copyright © 2016 Dennis Lysenko. All rights reserved.
//

#include <iostream>

//    // insert code here...
//    std::cout << "Hello, World!\n";
//    
//    chaiscript::ChaiScript chai;
//    chai.eval("puts(\"bob\"")
//    
//    return 0;
//}

#include <chaiscript/chaiscript.hpp>
#include <chaiscript/chaiscript_stdlib.hpp>
#include <dirent.h>

double function(int i, double j)
{
    return i * j;
}

typedef struct Footballer {
    int Pace;
    std::string Name;
} Footballer;

int main(int argc, const char * argv[])
{
    chaiscript::ChaiScript chai(chaiscript::Std_Lib::library());
    
    chai.add(chaiscript::user_type<Footballer>(), "Footballer");
    chai.add(chaiscript::fun(&Footballer::Pace), "Pace");
    chai.add(chaiscript::fun(&Footballer::Name), "Name");
    
    Footballer bellerin;
    bellerin.Pace = 99;
    bellerin.Name = "Hector Bellerin";
    
    Footballer lahm;
    lahm.Pace = 80;
    lahm.Name = "Philipp Lahm";
    
    chai.add(chaiscript::var(bellerin), "bellerin");
    chai.add(chaiscript::var(bellerin), "lahm");
    
    Footballer betterFootballer = chai.eval_file<Footballer>("./test.chai");
    
    std::cout << "The better player is " << betterFootballer.Name << std::endl;
    
    return 0;
}
