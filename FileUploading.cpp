
#include "FileUploading.h"

FileUploading::FileUploading(){
    string path = "C:/Users/tochk/Downloads/ocean/al/test.txt";
    inputFile(path);
}

FileUploading::FileUploading(string path){
    inputFile(path);
}

void FileUploading::inputFile(string path){
    ifstream fin (path);
    if (!fin) {
        cerr << "Cannot open the file!\n";
        return;
    }
    Characteristics temp;
    for (int i = 0; i < 5; i++) {
        fin >> temp.age >> temp.step >> temp.damage >>temp.name;
        FILE.push_back(temp);
    }
}

int FileUploading::classPlanktonDefine(){
    for(int i = 0; i < FILE.size(); i++)
        if(FILE[i].name == "Plankton") return i;
    return -1;
}

int FileUploading::classHerringDefine(){
    for(int i = 0; i < FILE.size(); i++)
        if(FILE[i].name == "Herring") return i;
    return -1;
}

int FileUploading::classWhaleDefine(){
    for(int i = 0; i < FILE.size(); i++)
        if(FILE[i].name == "Whale") return i;
    return -1;

}

int FileUploading::classCodDefine(){
    for(int i = 0; i < FILE.size(); i++)
        if(FILE[i].name == "Cod") return i;
    return -1;

}

int FileUploading::classSharkDefine(){
    for(int i = 0; i < FILE.size(); i++)
        if(FILE[i].name == "Shark") return i;
    return -1;

}
