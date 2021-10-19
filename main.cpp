#include <gtest/gtest.h>
#include "src/BigInteger.h"
#include "src/ExpressionEvaluator.h"
#include <sstream>
#include <string>

std::string ReadFromCommandLine(int argc, char** argv){
    std::stringstream result;
    for (int i = 1; i < argc; ++i) {
        result << std::string(argv[i]);
    }
    return result.str();
}

int main(int argc, char** argv) {
    enum Test {ONE, TWO, THREE};
    Test test1 = Test::ONE;
    std::string input;
    if (argc > 1){ // Suppose we have command line arguments
        input = ReadFromCommandLine(argc, argv);
    }
    else{
        std::cout << "Please enter a mathematical expression that you are willing to evaluate and press Enter.\n";
        getline(std::cin, input);
    }
    std::string_view expression(input);
    ExpressionEvaluator evaluator(expression);
    std::cout << std::boolalpha << "Check if math expression is correct: " << evaluator.IsExpressionValid();
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
}
