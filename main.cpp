#include <gtest/gtest.h>
#include "src/BigInteger.h"
#include "src/ExpressionEvaluator.h"
#include <string>

int main() {
    std::cout << "Please enter any mathematical expression you wish to evaluate.\nSupported operators "
                 "include binary +, binary -, *, /, % and round parentheses.\nUnary operators are not supported... yet.\n";
    std::string input;
    std::getline(std::cin, input);
    std::cout << "Evaluation result: " << ExpressionEvaluator(input).Evaluate();
    //testing::InitGoogleTest(&argc, argv);
    // return RUN_ALL_TESTS();
}
