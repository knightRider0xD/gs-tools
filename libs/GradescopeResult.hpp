#ifndef GRADESCOPE_AUTOGRADER_OUTPUT_H
#define GRADESCOPE_AUTOGRADER_OUTPUT_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <limits>

namespace std {

    class GradescopeResult {

        public:

            /**
            * Generate a basic Gradescope test result, and write it to a file.
            * The test will show as passed if full marks have been achieved.
            * @param outputFile The file name to write the JSON to.
            * @param score The score for this result
            * @param max_score The maximum marks available for this result
            * @param name The name of the test that will show in Gradescope as a plain text string.
            * @param output The test output to show in Gradescope as a multiline text string.
            * @return 0 if successful
            */
            static int writeBasicTest( string outputFile, float score, float max_score, string name, string output ) {
                
                string status = "failed";
                if(score >= max_score){
                    status = "passed";
                }

                return GradescopeResult::writeResult( outputFile, score, max_score, status, name, output );

            }

            /**
            * Generate a Gradescope result to display an informational message (does not have a score), and write it to a file.
            * @param outputFile The file name to write the JSON to.
            * @param status Either "passed" or "failed". Will show accordingly in Gradescope.
            * @param name The title/heading of the message that will show in Gradescope as a plain text string.
            * @param output The full body of the message to show in Gradescope as a multiline text string.
            * @return 0 if successful
            */
            static int writeInfoMessage( string outputFile, string status, string name, string output ) {

                return GradescopeResult::writeResult( outputFile, numeric_limits<float>::quiet_NaN(), numeric_limits<float>::quiet_NaN(), status, name, output );

            }

            /**
            * Generate a Gradescope test result in JSON format and write it to a file.
            * See https://gradescope-autograders.readthedocs.io/en/latest/specs/#output-format
            * @param outputFile The file name to write the JSON to.
            * @param score The score for this result
            * @param max_score The maximum marks available for this result
            * @param status Either "passed" or "failed". Will show accordingly in Gradescope.
            * @param name The name of the test that will show in Gradescope. By default a plain text string.
            * @param output The test output to show in Gradescope. By default a multiline text string.
            * @param visibility Whether the test should be a visible or hidden test case. See https://gradescope-autograders.readthedocs.io/en/latest/specs/#controlling-test-case-visibility
            * @param name_format Whether to use plaintext or formatted output in test names (e.g. variable names in monospaced font). See https://gradescope-autograders.readthedocs.io/en/latest/specs/#output-string-formatting
            * @param output_format As above. See https://gradescope-autograders.readthedocs.io/en/latest/specs/#output-string-formatting
            * @param extra_data If you want to attach additional metadata to the test result, you can add it as a JSON formatted object string.
            * @return 0 if successful
            */
            static int writeResult( string outputFile, float score, float max_score, string status, string name, string output, string visibility = "visible", string name_format = "text", string output_format = "text", string extra_data = "{}" ) {
                
                ofstream outfile(outputFile);

                if (!outfile) {
                    cerr << "Error opening file: " << outputFile << endl;
                    return 1;
                }

                // If score is NaN, set to 0
                if(isnan(score)){
                    score = 0.0;
                }

                size_t pos;

                // Escape double quotes in name
                pos = 0;
                while ((pos = name.find("\"", pos)) != string::npos) {
                    name.replace(pos, 1, "\\\"");
                    pos += 2; // Move past the escaped double quote
                }

                // Escape double quotes in output
                pos = 0;
                while ((pos = output.find("\"", pos)) != string::npos) {
                    output.replace(pos, 1, "\\\"");
                    pos += 2; // Move past the escaped double quote
                }

                stringstream json;
                json << "{\n";
                if(!(isnan(max_score))){                                            // If max_score is NaN, skip including a score
                    json << "    \"score\": " << score << ",\n";                // Optional, but required if not on top level submission
                    json << "    \"max_score\": " << max_score << ",\n";        // Optional
                }
                json << "    \"status\": \"" << status << "\",\n";              // Optional, see \"Test case status\" below
                json << "    \"name\": \"" << name << "\",\n";                  // Optional
                json << "    \"output\": \"" << output << "\",\n";              // Optional
                json << "    \"output_format\": \"" << output_format << "\",\n";// Optional formatting for the test case output, see \"Output String Formatting\" below
                json << "    \"visibility\": \"" << visibility << "\",\n";      // Optional visibility setting
                json << "    \"extra_data\": " << extra_data << "\n";           // Optional extra data to be stored
                json << "}\n";

                outfile << json.str();
                outfile.close();

                return 0;

            }

    };

}

#endif /*GRADESCOPE_AUTOGRADER_OUTPUT_H*/