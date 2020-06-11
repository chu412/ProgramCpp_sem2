#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

class Cube 
{
public:
    Cube();
    void save();
    void read();
    bool check();
    void myspin();
    void show();
    void scrol();
    void setString();
    void getString();
    bool find(bool kek, int count);
    ~Cube();

private:
    std::string str;
    unsigned char** cube;
    void Right(int turn);
    void Left(int turn);
    void YR();
    void YL();
    void RR();
    void RL();
    void GR();
    void GL();
    void OR();
    void OL();
    void WR();
    void WL();
    void BR();
    void BL();
    void checkmas(int* mas, unsigned char c);
    bool checkcol(unsigned char a, unsigned char b);
    bool checkcen(std::vector<unsigned char>& cen, unsigned char a, bool flag, int* mas);
    bool checkreb(std::vector<std::pair<unsigned char, unsigned char>>& reb, unsigned char a, unsigned char b, bool flag, int* mas);
    bool checkcor(std::vector<std::pair<unsigned char, std::pair<unsigned char, unsigned char>>>& cor, unsigned char a, unsigned char b, unsigned char c, bool flag, int* mas);
    void goodw(int a);
    void findkrest();
    void krest();
    int count_edge_krest();
    void edgekrest();
    void cornerwhile(int var);
    void R6perebor();
    void G6perebor();
    void O6perebor();
    void B6perebor();
    void find_corner();
    void Bedge();
    void Redge();
    void Gedge();
    void Oedge();
    void find_edge();
    void firstsloi();
    void secondsloi();
    void ykrestG(int count);
    void ykrestR(int count);
    bool ykrest();
    void vertolet();
    void ushki();
    void nos();
    void glazki();
    void triplpifpaf();
    void Rriba();
    void Lriba();
    bool ycor();
    void havepair();
    void notpair();
    void lastcor();
    void lastgl();
    void lastgr();
    void lastol();
    void lastor();
    void lastbl();
    void lastbr();
    void lastrl();
    void lastrr();
    bool lastedge();
    void littlecheck(int& count);
};