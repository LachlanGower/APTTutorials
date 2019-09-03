#include "functionception.h"

FunctionCeption::FunctionCeption(){

}
//How to lambda 101
std::string FunctionCeption::funkyTown(std::string x){
    auto function1 = [](std::string& x){
        x += "f";
        auto function2 = [](std::string& x){
            x += "u";
            auto function3 = [](std::string& x){
                x += "n";
                auto function4 = [](std::string& x){
                    x += "k";
                    auto function5 = [](std::string& x){
                        x += "y";
                        auto function6 = [](std::string& x){
                            x += "t";
                            auto function7 = [](std::string& x){
                                x += "o";
                                auto function8 = [](std::string& x){
                                    x += "w";
                                    auto function9 = [&x](){
                                        x += "n";
                                    };
                                    function9();
                                };
                                function8(x);
                            };
                            function7(x);
                        };
                        function6(x);
                    };
                    function5(x);
                };
                function4(x);
            };
            function3(x);
        };
        function2(x);
    };
    function1(x);
    return x;
}