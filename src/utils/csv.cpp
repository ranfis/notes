#include "include/csv.h"
CSV::CSV(char* file)
{
    this->file = file;
}

string CSV::read_line(uint number){
    this->ifs.clear();
    this->ifs.open(file);
    string line;
    for (uint i=0;i<number;i++)
    {
        getline(ifs,line);
    }
    this->ifs.close();
    return line;
}

string CSV::read_file(){
    this->ifs.clear();
    this->ifs.open(file);
    string line;
    string full;
    while (ifs.good())
    {
        getline (ifs,line);
        full+=line + "\n";
    }
    this->ifs.close();
    return full;
}

string CSV::read_data(uint number, uint column){
    string line = read_line(number);
    string data;
    string::iterator i;
    uint aux=0;

    i=line.begin();
    for(;;){
        if (*i==','){
            aux++;
            if(aux == column){
                return data;
            }
            data = "";
            if (i<line.end()){
                i++;
            }
        }
        else{
            data += *i;
            if (i<line.end()){
                i++;
            }
            else{
                return data;
            }
        }
    }
}

void CSV::write_line(uint cant,bool sobrescribir,char* texto, ...){
    this->ofs.clear();
    if(sobrescribir){
        this->ofs.open(file);
    }
    else{
        this->ofs.open(file,ios::app);
    }

    va_list columns;
    string line = texto;
    va_start(columns, texto);
    for(uint i = 0; i<cant-1; i++){
        line+=",";
        line+=va_arg(columns,char*);
    }
    this->ofs << line << endl;
    this->ofs.close();
    va_end(columns);
}

void CSV::clean(){
    std::ofstream ofs(file);
    ofs.close();
}

void CSV::write(char* text){
    ofs.open (file);
    ofs << text;
    ofs.close();
}
