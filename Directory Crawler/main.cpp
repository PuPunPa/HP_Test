#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = filesystem;

const bool subfolders = false;

ifstream::pos_type filesize(const fs::path filename)
{
    ifstream in(filename, ifstream::ate | ifstream::binary);
    return in.tellg(); 
}

void Crawl(string path){
    ofstream output("dir.json");
    output << "{\"files\":[" << endl;

    //I didn't know wether or not it should read from subdirectories too so I just toggled it 
    if(subfolders){
        for (const auto & entry : (fs::recursive_directory_iterator(path))){
            if(entry.path().extension() != ""){
                output << "    {\"name\":\"" << entry.path().filename().string() << "\",\"size\":" << filesize(entry.path()) << "},"  << endl;
            }
        }
    }
    else {
        for (const auto & entry : (fs::directory_iterator(path))){
            if(entry.path().extension() != ""){
                output << "    {\"name\":\"" << entry.path().filename().string() << "\",\"size\":" << filesize(entry.path()) << "},"  << endl;
            }
        }
    }
    
    output << "]}";
    output.close();
}


int main(int argc, char** argv){
    if(argc != 2){
        cout << "Command is missing " << 2-argc << ((2-argc > 1) ? " arguments, please try again." : " argument, please try again.");
        return 0;
    }
    Crawl(argv[1]);
    
    return 0;
}