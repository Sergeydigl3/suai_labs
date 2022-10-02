#include <iostream>
#include <cstring>
// #include "test.hpp"
#include "CLI/CLI11.hpp"
#include "winrar/winrar.hpp"
#include <fstream>
#include <string>

using namespace std;


#define EXEC "winrar.exe"
#define TITLE "\nFano compressor/decompressor"
#define FOOTER \
  "Created without <3 by Sergeydigl3 (Prokopchuk Sergey) at SUAI University"

class Settings {
public:
    string file_in;
    string file_out = "out.aboba";
    uint64_t chunk_size = 1024;

    bool decompress = false;
    bool debug = false;

};

int main(int argc, char const* argv[])
{
    CLI::App app(TITLE, EXEC);
    Settings config;
    app.footer(FOOTER);

    app.add_option("input", config.file_in, "Input file")->option_text("FILE");
    app.add_option("output", config.file_out, "Output file")->option_text("FILE");

    app.add_flag("-d, --dec", config.decompress, "Use decompress mode");
    app.add_flag("--debug", config.debug, "Use debug mode");
    app.add_option("-c, --chunk", config.chunk_size,
        "Define chunk size (default: 1024)")->option_text("SIZE");


    // parse CLI arguments
    CLI11_PARSE(app, argc, argv);

    // check if no files or interactive mode specified
    if (config.file_in.empty()) {
        cout << "No file specified" << endl;
        cout << "Use -h or --help to see usage" << endl;
        return 0;
    }
    winrar zip7(config.file_in, config.chunk_size, config.debug);
    if (config.decompress) {
        zip7.decompress(config.file_out);
    }
    else {
        zip7.compress(config.file_out);
    }
    return 0;
}
