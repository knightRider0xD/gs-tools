#ifndef GRADESCOPE_AUTOGRADER_OUTPUT_H
#define GRADESCOPE_AUTOGRADER_OUTPUT_H

#include <string>

class GradescopeResult {

    public:

        static int writeBasicTest( std::string outputFile = "result.json", float score, float max_score, std::string name, std::string output );
        static int writeInfoMessage( std::string outputFile = "result.json", std::string status, std::string name, std::string output );
        
        static int writeResult( std::string outputFile = "result.json", float score, float max_score, std::string status, std::string name, std::string output, std::string visibility = "visible", std::string name_format = "text", std::string output_format = "text", std::string extra_data = "{}" );

};

#endif /*GRADESCOPE_AUTOGRADER_OUTPUT_H*/