#include<iostream>
#include<fstream>
#include<optional>

std::string readfileasstring(const std::string& filepath, bool& outsuccess)
{
    std::ifstream stream(filepath); 
    if(stream)
    {
        std::string result;
        stream.close();
        outsuccess=true;
        return result;
    }
    outsuccess=false;
    return std::string();
}

std::optional<std::string> ReadFileAsString(const std::string& filepath)
{
    std::ifstream stream(filepath); 
    if(stream)
    {
        std::string result;
        stream.close();
        return result;
    }
    return {};
}


int main()
{
    bool fileopensuccessfully;
    std::string data = readfileasstring("data.txt",fileopensuccessfully);
    if(fileopensuccessfully)
    {

    }
    auto Data = ReadFileAsString("C:\\Users\\abc\\Documents\\GitHub\\vscodepractice\\C++\\dynamic_cast_practice.cpp");
    if(Data)
    {
        std::string& data = *Data;
        std::cout<<"File read successfully"<<std::endl;
        std::string value= Data.value_or("Default value");
        std::cout<<"Value: "<<value<<std::endl;
    }
    else{
        std::cout<<"File read failed"<<std::endl;
    }
    std::cin.get();
}