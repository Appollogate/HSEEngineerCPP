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
    ExpressionEvaluator eval("7 * 1 - 13");
    BigInteger res = eval.Evaluate();
    std::cout << res;
    //testing::InitGoogleTest(&argc, argv);
    // return RUN_ALL_TESTS();
}
