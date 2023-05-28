#include <fstream>
#include <sstream>

#include  "Loader.h"

template<typename T>
bool Loader::load(std::map<std::string,T> & config, const std::string & target,const std::string & fileName){
    std::ifstream file(target);
    if(!file.good()){
        std::cout<<"Error when opening "<<fileName<<" file!"<<std::endl;
        return false;
    }

    std::string line;
    std::string x;
    char eq;
    T val;
    int lineNum=0;

    while(file.good()){
        lineNum++;
        eq=' ';
        std::getline(file,line);
        if(*line.begin()=='/' || line.size()==0) continue;    //comment or empty line - skip
        std::istringstream input(line);
        input>>x>>eq>>val;
        if(x=="" || eq!='='){
            std::cout<<"Line "<<lineNum<<" in "<<fileName<<" file is in wrong format!"<<std::endl;
            return false;
        } 
        config.insert({x,val});
    }
    return true;
}

bool Loader::loadConfig(std::map<std::string,int> & config){
    if(!load<int>(config,"examples/config","config")){
        return false;
    }
    if( config.find("biggerExplosion_chance")==config.end() ||
        config.find("moreBombs_chance")==config.end() ||
        config.find("bonusHp_chance")==config.end()   ){
        std::cout<<"Missing fields in config file!"<<std::endl;
        return false;
    }
    return true;
}

bool Loader::loadControls(std::map<std::string,char> & config){
    if(!load<char>(config,"examples/controls","controls")){
        return false;
    }
    if(     config.find("player1_up")==config.end()     ||
            config.find("player1_down")==config.end()   ||
            config.find("player1_left")==config.end()   ||
            config.find("player1_right")==config.end()  ||
            config.find("player1_bomb")==config.end()   ||
            config.find("player2_up")==config.end()     ||
            config.find("player2_down")==config.end()   ||
            config.find("player2_left")==config.end()   ||
            config.find("player2_right")==config.end()  ||
            config.find("player2_bomb")==config.end()   ||
            config.find("player3_up")==config.end()     ||
            config.find("player3_down")==config.end()   ||
            config.find("player3_left")==config.end()   ||
            config.find("player3_right")==config.end()  ||
            config.find("player3_bomb")==config.end()   ||
            config.find("player4_up")==config.end()     ||
            config.find("player4_down")==config.end()   ||
            config.find("player4_left")==config.end()   ||
            config.find("player4_right")==config.end()  ||
            config.find("player4_bomb")==config.end()   ){
        std::cout<<"Missing fields in controls file!"<<std::endl;
        return false;
    }
    return true;
}

