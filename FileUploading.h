
#ifndef AL_FILEUPLOADING_H
#define AL_FILEUPLOADING_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FileUploading{
public:
    class Characteristics{
    public:
        string name;
        int age;
        int step;
        int damage;
    };

    vector<Characteristics> FILE;

    FileUploading();

    FileUploading(string path);

    void inputFile(string path);

    int classPlanktonDefine();

    int classHerringDefine();

    int classWhaleDefine();

    int classCodDefine();

    int classSharkDefine();
};


#endif //AL_FILEUPLOADING_H
