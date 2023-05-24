#include <fstream>
#include <sstream>

#include  "Loader.h"

void Loader::loadConfig(const std::string & configFile, std::map<std::string,int> & config){
    std::ifstream file(configFile);
    if(!file.good()){
        std::cout<<"Error when opening config file, default values will be used!"<<std::endl;
        return;
    }

    std::string line;
    std::string x;
    char garb;
    int val;

    int lineNum=1;
    std::getline(file,line);

    while(file.good()){
        lineNum++;
        garb=' ';
        std::getline(file,line);
        if(*line.begin()=='/' || line.size()==0) continue;    //comment or empty line - skip

        std::istringstream input(line);
        input>>x>>garb>>val;
        if(x=="" || garb!='='){
            std::cout<<"Line "<<lineNum<<" in config file is in wrong format, default value will be used!"<<std::endl;
            continue;    
        } 
        config.insert({x,val});
    }
    return;
}

bool Loader::loadPowerUps(){
    //TODO
    return true;
}