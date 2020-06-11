#include "Cube.h"

Cube::Cube() 
{
    cube = new unsigned char* [sizeof(unsigned char*) * 6];
    for (int i = 0; i < 6; i++) {
        cube[i] = new unsigned char[sizeof(unsigned char) * 9];
        for (int j = 0; j < 9; j++) {
            if (i == 0) {
                cube[i][j] = 'y';
            }
            else if (i == 1) {
                cube[i][j] = 'r';
            }
            else if (i == 2) {
                cube[i][j] = 'g';
            }
            else if (i == 3) {
                cube[i][j] = 'o';
            }
            else if (i == 4) {
                cube[i][j] = 'w';
            }
            else {
                cube[i][j] = 'b';
            }
        }
    }
    str = "";
}

void Cube::save() 
{
    std::ofstream fout;
    fout.open("rubikout.txt");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j += 3) {
            if (i == 0 || i == 4 || i == 5) {
                fout << "        ";
            }
            if (i == 1) {
                fout << cube[i][j] << " " << cube[i][j + 1] << " " << cube[i][j + 2] << " | " << cube[i + 1][j] << " " << cube[i + 1][j + 1] << " " << cube[i + 1][j + 2] << " | " << cube[i + 2][j] << " " << cube[i + 2][j + 1] << " " << cube[i + 2][j + 2] << "\n" << cube[i][j + 3] << " " << cube[i][j + 4] << " " << cube[i][j + 5] << " | " << cube[i + 1][j + 3] << " " << cube[i + 1][j + 4] << " " << cube[i + 1][j + 5] << " | " << cube[i + 2][j + 3] << " " << cube[i + 2][j + 4] << " " << cube[i + 2][j + 5] << "\n" << cube[i][j + 6] << " " << cube[i][j + 7] << " " << cube[i][j + 8] << " | " << cube[i + 1][j + 6] << " " << cube[i + 1][j + 7] << " " << cube[i + 1][j + 8] << " | " << cube[i + 2][j + 6] << " " << cube[i + 2][j + 7] << " " << cube[i + 2][j + 8] << "\n";
                i += 2;
                break;
            }
            else {
                fout << cube[i][j] << " " << cube[i][j + 1] << " " << cube[i][j + 2] << "\n";
            }
        }
        if (i == 0 || i == 3 || i == 4) {
            fout << "        - - -\n";
        }
    }
    fout.close();
}

void Cube::read() 
{
    std::ifstream fin;
    fin.open("rubik.txt");
    unsigned char c;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            fin >> c;
            if (c == '-' || c == '|') {
                j--;
            }
            else if (i == 0 || i == 4 || i == 5) {
                cube[i][j] = c;
            }
            else if (i == 1) {
                cube[i][j] = c;
                fin >> c;
                cube[i][j + 1] = c;
                fin >> c;
                cube[i][j + 2] = c;
                fin >> c;
                fin >> c;
                cube[i + 1][j] = c;
                fin >> c;
                cube[i + 1][j + 1] = c;
                fin >> c;
                cube[i + 1][j + 2] = c;
                fin >> c;
                fin >> c;
                cube[i + 2][j] = c;
                fin >> c;
                cube[i + 2][j + 1] = c;
                fin >> c;
                cube[i + 2][j + 2] = c;
                fin >> c;
                cube[i][j + 3] = c;
                fin >> c;
                cube[i][j + 4] = c;
                fin >> c;
                cube[i][j + 5] = c;
                fin >> c;
                fin >> c;
                cube[i + 1][j + 3] = c;
                fin >> c;
                cube[i + 1][j + 4] = c;
                fin >> c;
                cube[i + 1][j + 5] = c;
                fin >> c;
                fin >> c;
                cube[i + 2][j + 3] = c;
                fin >> c;
                cube[i + 2][j + 4] = c;
                fin >> c;
                cube[i + 2][j + 5] = c;
                fin >> c;
                cube[i][j + 6] = c;
                fin >> c;
                cube[i][j + 7] = c;
                fin >> c;
                cube[i][j + 8] = c;
                fin >> c;
                fin >> c;
                cube[i + 1][j + 6] = c;
                fin >> c;
                cube[i + 1][j + 7] = c;
                fin >> c;
                cube[i + 1][j + 8] = c;
                fin >> c;
                fin >> c;
                cube[i + 2][j + 6] = c;
                fin >> c;
                cube[i + 2][j + 7] = c;
                fin >> c;
                cube[i + 2][j + 8] = c;
                i += 2;
                break;
            }
        }
    }
    fin.close();
}

bool Cube::check() 
{
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            if (cube[i][j] != 'r' && cube[i][j] != 'o' && cube[i][j] != 'g' && cube[i][j] != 'b' && cube[i][j] != 'y' && cube[i][j] != 'w') {
                return false;
            }
        }
    }
    int* mas = new int[6];
    for (int i = 0; i < 6; i++) {
        mas[i] = 0;
    }
    bool flag = true;
    std::vector<std::pair<unsigned char, unsigned char>> reb;
    flag = checkreb(reb, cube[0][7], cube[2][1], flag, mas);
    flag = checkreb(reb, cube[0][5], cube[3][1], flag, mas);
    flag = checkreb(reb, cube[0][1], cube[5][7], flag, mas);
    flag = checkreb(reb, cube[0][3], cube[1][1], flag, mas);
    flag = checkreb(reb, cube[1][5], cube[2][3], flag, mas);
    flag = checkreb(reb, cube[2][5], cube[3][3], flag, mas);
    flag = checkreb(reb, cube[3][5], cube[5][5], flag, mas);
    flag = checkreb(reb, cube[5][3], cube[1][3], flag, mas);
    flag = checkreb(reb, cube[4][1], cube[2][7], flag, mas);
    flag = checkreb(reb, cube[4][3], cube[1][7], flag, mas);
    flag = checkreb(reb, cube[4][5], cube[3][7], flag, mas);
    flag = checkreb(reb, cube[4][7], cube[5][1], flag, mas);
    std::vector<std::pair<unsigned char, std::pair<unsigned char, unsigned char>>> cor;
    flag = checkcor(cor, cube[0][6], cube[1][2], cube[2][0], flag, mas);
    flag = checkcor(cor, cube[0][8], cube[2][2], cube[3][0], flag, mas);
    flag = checkcor(cor, cube[1][8], cube[2][6], cube[4][0], flag, mas);
    flag = checkcor(cor, cube[2][8], cube[3][6], cube[4][2], flag, mas);
    flag = checkcor(cor, cube[0][2], cube[3][2], cube[5][8], flag, mas);
    flag = checkcor(cor, cube[0][0], cube[1][0], cube[5][6], flag, mas);
    flag = checkcor(cor, cube[1][6], cube[4][6], cube[5][0], flag, mas);
    flag = checkcor(cor, cube[3][8], cube[4][8], cube[5][2], flag, mas);
    std::vector<unsigned char> cen;
    flag = checkcen(cen, cube[0][4], flag, mas);
    flag = checkcen(cen, cube[1][4], flag, mas);
    flag = checkcen(cen, cube[2][4], flag, mas);
    flag = checkcen(cen, cube[3][4], flag, mas);
    flag = checkcen(cen, cube[4][4], flag, mas);
    flag = checkcen(cen, cube[5][4], flag, mas);
    if (flag == false) {
        return flag;
    }
    else {
        for (int i = 0; i < 6; i++) {
            if (mas[i] > 9) {
                return false;
            }
        }
        return flag;
    }
}

void Cube::myspin() 
{
    std::cout << "Choose a color from the list (R, B, O, G, W, Y), only BIG characters "
        "and "
        "choose the direction of rotation (R, L)." << std::endl;
    std::cout << "For example: RR, BL, OR, GR, YL, WL" << std::endl;
    std::cout << "if you're done, enter only it '.'" << std::endl;
    char c, d;
    while (true) {
        std::cin >> c;
        if (c == '.') {
            break;
        }
        else {
            std::cin >> d;
            if (c == 'R') {
                if (d == 'R') {
                    RR();
                }
                else if (d == 'L') {
                    RL();
                }
            }
            else if (c == 'B') {
                if (d == 'R') {
                    BR();
                }
                else if (d == 'L') {
                    BL();
                }
            }
            else if (c == 'G') {
                if (d == 'R') {
                    GR();
                }
                else if (d == 'L') {
                    GL();
                }
            }
            else if (c == 'O') {
                if (d == 'R') {
                    OR();
                }
                else if (d == 'L') {
                    OL();
                }
            }
            else if (c == 'Y') {
                if (d == 'R') {
                    YR();
                }
                else if (d == 'L') {
                    YL();
                }
            }
            else if (c == 'W') {
                if (d == 'R') {
                    WR();
                }
                else if (d == 'L') {
                    WL();
                }
            }
            else {
                std::cout << "Bad color." << std::endl;
            }
            if (d != 'R' && d != 'L') {
                std::cout << "Bad rotation." << std::endl;
            }

        }
        //show();
    }
}

void Cube::show() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j += 3) {
            if (i == 0 || i == 4 || i == 5) {
                std::cout << "        ";
            }
            if (i == 1) {
                std::cout << cube[i][j] << " " << cube[i][j + 1] << " " << cube[i][j +
                    2]
                    << " | " << cube[i + 1][j] << " " << cube[i + 1][j + 1] << " " << cube[i + 1][j + 2] << " | " << cube[i + 2][j] << " " << cube[i + 2][j + 1] << " " << cube[i + 2][j + 2] << "\n" << cube[i][j + 3] << " " << cube[i][j + 4] << " " << cube[i][j + 5] << " | " << cube[i + 1][j + 3] << " " << cube[i + 1][j + 4] << " " << cube[i + 1][j + 5] << " | " << cube[i + 2][j + 3] << " " << cube[i + 2][j + 4] << " " << cube[i + 2][j + 5] << "\n" << cube[i][j + 6] << " " << cube[i][j + 7] << " " << cube[i][j + 8] << " | " << cube[i + 1][j + 6] << " " << cube[i + 1][j + 7] << " " << cube[i + 1][j + 8] << " | " << cube[i + 2][j + 6] << " " << cube[i + 2][j + 7] << " " << cube[i + 2][j + 8] << "\n";
                i += 2;
                break;
            }
            else {
                std::cout << cube[i][j] << " " << cube[i][j + 1] << " " << cube[i][j +
                    2]
                    << "\n";
            }
        }
        if (i == 0 || i == 3 || i == 4) {
            std::cout << "        - - -\n";
        }
    }
}

void Cube::scrol() {
    srand(time(0));
    int count = rand() % 1000 + 200;
    //std::cout << count << "\n";
    for (int i = 0; i < count; i++) {
        int now = rand() % 12;
        //std::cout << now << " ";
        if (now == 0) {
            YR();
        }
        else if (now == 1) {
            YL();
        }
        else if (now == 2) {
            RR();
        }
        else if (now == 3) {
            RL();
        }
        else if (now == 4) {
            GR();
        }
        else if (now == 5) {
            GL();
        }
        else if (now == 6) {
            OR();
        }
        else if (now == 7) {
            OL();
        }
        else if (now == 8) {
            WR();
        }
        else if (now == 9) {
            WL();
        }
        else if (now == 10) {
            BR();
        }
        else if (now == 11) {
            BL();
        }
    }
}

void Cube::setString() 
{
    str = "";
}

void Cube::getString() 
{
    str += ".";
    std::cout << str.length() / 3 << std::endl << str;
}

bool Cube::find(bool kek, int count) 
{
    unsigned char** lol = new unsigned char* [sizeof(unsigned char*) * 6];
    for (int i = 0; i < 6; i++) {
        lol[i] = new unsigned char[sizeof(unsigned char) * 9];
        for (int j = 0; j < 9; j++) {
            lol[i][j] = cube[i][j];
        }
    }
    krest();
    edgekrest();
    firstsloi();
    secondsloi();
    bool flag = ykrest();
    if (flag == true) {
        flag = ycor();
        if (flag == true) {
            lastcor();
            while (cube[2][0] != 'g') {
                str += "YR ";
                YR();
            }
            flag = lastedge();
        }
    }
    if (kek) {
        littlecheck(count);
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cube[i][j] = lol[i][j];
        }
    }
    //show();
    for (int i = 0; i < 6; i++) {
        delete[]lol[i];
    }
    delete[]lol;
    return flag;
}

Cube::~Cube() 
{
    for (int i = 0; i < 6; i++) 
    {
        delete[]cube[i];
    }
    delete[]cube;
}

void Cube::Right(int turn) 
{
    unsigned char c;
    c = cube[turn][0];
    cube[turn][0] = cube[turn][6];
    cube[turn][6] = cube[turn][8];
    cube[turn][8] = cube[turn][2];
    cube[turn][2] = c;
    c = cube[turn][1];
    cube[turn][1] = cube[turn][3];
    cube[turn][3] = cube[turn][7];
    cube[turn][7] = cube[turn][5];
    cube[turn][5] = c;
}

void Cube::Left(int turn) 
{
    unsigned char c;
    c = cube[turn][0];
    cube[turn][0] = cube[turn][2];
    cube[turn][2] = cube[turn][8];
    cube[turn][8] = cube[turn][6];
    cube[turn][6] = c;
    c = cube[turn][1];
    cube[turn][1] = cube[turn][5];
    cube[turn][5] = cube[turn][7];
    cube[turn][7] = cube[turn][3];
    cube[turn][3] = c;
}

void Cube::YR() 
{
    unsigned char c;
    Right(0);
    c = cube[5][6];
    cube[5][6] = cube[1][2];
    cube[1][2] = cube[2][2];
    cube[2][2] = cube[3][2];
    cube[3][2] = c;
    c = cube[5][8];
    cube[5][8] = cube[1][0];
    cube[1][0] = cube[2][0];
    cube[2][0] = cube[3][0];
    cube[3][0] = c;
    c = cube[5][7];
    cube[5][7] = cube[1][1];
    cube[1][1] = cube[2][1];
    cube[2][1] = cube[3][1];
    cube[3][1] = c;
}

void Cube::YL() 
{
    unsigned char c;
    Left(0);
    c = cube[5][6];
    cube[5][6] = cube[3][2];
    cube[3][2] = cube[2][2];
    cube[2][2] = cube[1][2];
    cube[1][2] = c;
    c = cube[5][8];
    cube[5][8] = cube[3][0];
    cube[3][0] = cube[2][0];
    cube[2][0] = cube[1][0];
    cube[1][0] = c;
    c = cube[5][7];
    cube[5][7] = cube[3][1];
    cube[3][1] = cube[2][1];
    cube[2][1] = cube[1][1];
    cube[1][1] = c;
}

void Cube::RR() 
{
    unsigned char c;
    Right(1);
    c = cube[0][0];
    cube[0][0] = cube[5][0];
    cube[5][0] = cube[4][0];
    cube[4][0] = cube[2][0];
    cube[2][0] = c;
    c = cube[0][6];
    cube[0][6] = cube[5][6];
    cube[5][6] = cube[4][6];
    cube[4][6] = cube[2][6];
    cube[2][6] = c;
    c = cube[0][3];
    cube[0][3] = cube[5][3];
    cube[5][3] = cube[4][3];
    cube[4][3] = cube[2][3];
    cube[2][3] = c;
}

void Cube::RL() 
{
    unsigned char c;
    Left(1);
    c = cube[0][0];
    cube[0][0] = cube[2][0];
    cube[2][0] = cube[4][0];
    cube[4][0] = cube[5][0];
    cube[5][0] = c;
    c = cube[0][6];
    cube[0][6] = cube[2][6];
    cube[2][6] = cube[4][6];
    cube[4][6] = cube[5][6];
    cube[5][6] = c;
    c = cube[0][3];
    cube[0][3] = cube[2][3];
    cube[2][3] = cube[4][3];
    cube[4][3] = cube[5][3];
    cube[5][3] = c;
}

void Cube::GR() 
{
    unsigned char c;
    Right(2);
    c = cube[0][6];
    cube[0][6] = cube[1][8];
    cube[1][8] = cube[4][2];
    cube[4][2] = cube[3][0];
    cube[3][0] = c;
    c = cube[0][8];
    cube[0][8] = cube[1][2];
    cube[1][2] = cube[4][0];
    cube[4][0] = cube[3][6];
    cube[3][6] = c;
    c = cube[0][7];
    cube[0][7] = cube[1][5];
    cube[1][5] = cube[4][1];
    cube[4][1] = cube[3][3];
    cube[3][3] = c;
}

void Cube::GL() 
{
    unsigned char c;
    Left(2);
    c = cube[0][6];
    cube[0][6] = cube[3][0];
    cube[3][0] = cube[4][2];
    cube[4][2] = cube[1][8];
    cube[1][8] = c;
    c = cube[0][8];
    cube[0][8] = cube[3][6];
    cube[3][6] = cube[4][0];
    cube[4][0] = cube[1][2];
    cube[1][2] = c;
    c = cube[0][7];
    cube[0][7] = cube[3][3];
    cube[3][3] = cube[4][1];
    cube[4][1] = cube[1][5];
    cube[1][5] = c;
}

void Cube::OR() 
{
    unsigned char c;
    Right(3);
    c = cube[0][2];
    cube[0][2] = cube[2][2];
    cube[2][2] = cube[4][2];
    cube[4][2] = cube[5][2];
    cube[5][2] = c;
    c = cube[0][8];
    cube[0][8] = cube[2][8];
    cube[2][8] = cube[4][8];
    cube[4][8] = cube[5][8];
    cube[5][8] = c;
    c = cube[0][5];
    cube[0][5] = cube[2][5];
    cube[2][5] = cube[4][5];
    cube[4][5] = cube[5][5];
    cube[5][5] = c;
}

void Cube::OL() {
    unsigned char c;
    Left(3);
    c = cube[0][2];
    cube[0][2] = cube[5][2];
    cube[5][2] = cube[4][2];
    cube[4][2] = cube[2][2];
    cube[2][2] = c;
    c = cube[0][8];
    cube[0][8] = cube[5][8];
    cube[5][8] = cube[4][8];
    cube[4][8] = cube[2][8];
    cube[2][8] = c;
    c = cube[0][5];
    cube[0][5] = cube[5][5];
    cube[5][5] = cube[4][5];
    cube[4][5] = cube[2][5];
    cube[2][5] = c;
}

void Cube::WR() {
    unsigned char c;
    Right(4);
    c = cube[5][0];
    cube[5][0] = cube[3][8];
    cube[3][8] = cube[2][8];
    cube[2][8] = cube[1][8];
    cube[1][8] = c;
    c = cube[5][2];
    cube[5][2] = cube[3][6];
    cube[3][6] = cube[2][6];
    cube[2][6] = cube[1][6];
    cube[1][6] = c;
    c = cube[5][1];
    cube[5][1] = cube[3][7];
    cube[3][7] = cube[2][7];
    cube[2][7] = cube[1][7];
    cube[1][7] = c;
}

void Cube::WL() {
    unsigned char c;
    Left(4);
    c = cube[5][0];
    cube[5][0] = cube[1][8];
    cube[1][8] = cube[2][8];
    cube[2][8] = cube[3][8];
    cube[3][8] = c;
    c = cube[5][2];
    cube[5][2] = cube[1][6];
    cube[1][6] = cube[2][6];
    cube[2][6] = cube[3][6];
    cube[3][6] = c;
    c = cube[5][1];
    cube[5][1] = cube[1][7];
    cube[1][7] = cube[2][7];
    cube[2][7] = cube[3][7];
    cube[3][7] = c;
}

void Cube::BR() {
    unsigned char c;
    Right(5);
    c = cube[0][0];
    cube[0][0] = cube[3][2];
    cube[3][2] = cube[4][8];
    cube[4][8] = cube[1][6];
    cube[1][6] = c;
    c = cube[0][2];
    cube[0][2] = cube[3][8];
    cube[3][8] = cube[4][6];
    cube[4][6] = cube[1][0];
    cube[1][0] = c;
    c = cube[0][1];
    cube[0][1] = cube[3][5];
    cube[3][5] = cube[4][7];
    cube[4][7] = cube[1][3];
    cube[1][3] = c;
}

void Cube::BL() {
    unsigned char c;
    Left(5);
    c = cube[0][0];
    cube[0][0] = cube[1][6];
    cube[1][6] = cube[4][8];
    cube[4][8] = cube[3][2];
    cube[3][2] = c;
    c = cube[0][2];
    cube[0][2] = cube[1][0];
    cube[1][0] = cube[4][6];
    cube[4][6] = cube[3][8];
    cube[3][8] = c;
    c = cube[0][1];
    cube[0][1] = cube[1][3];
    cube[1][3] = cube[4][7];
    cube[4][7] = cube[3][5];
    cube[3][5] = c;
}

void Cube::checkmas(int* mas, unsigned char c) {
    if (c == 'y') {
        mas[0]++;
    }
    else if (c == 'r') {
        mas[1]++;
    }
    else if (c == 'g') {
        mas[2]++;
    }
    else if (c == 'o') {
        mas[3]++;
    }
    else if (c == 'w') {
        mas[4]++;
    }
    else if (c == 'b') {
        mas[5]++;
    }
}

bool Cube::checkcol(unsigned char a, unsigned char b) {
    if ((a == 'w' && b == 'y') || (a == 'y' && b == 'w') || (a == 'b' && b == 'g') || (a == 'g' && b == 'b') || (a == 'r' && b == 'o') || (a == 'o' && b == 'r') || a == b) {
        return true;
    }
    return false;
}

bool Cube::checkcen(std::vector<unsigned char>& cen, unsigned char a, bool flag, int* mas) {
    if (flag == true) {
        for (unsigned int i = 0; i < cen.size(); i++) {
            if (cen[i] == a) {
                return false;
            }
        }
        checkmas(mas, a);
        cen.push_back(a);
        return true;
    }
    else {
        return false;
    }
}

bool Cube::checkreb(std::vector<std::pair<unsigned char, unsigned char>>& reb, unsigned char
    a, unsigned char b, bool flag, int* mas) {
    if (flag == true) {
        for (unsigned int i = 0; i < reb.size(); i++) {
            if ((reb[i].first == a && reb[i].second == b) || (reb[i].first == b && reb[i].second == a) || checkcol(a, b)) {
                return false;
            }
        }
        checkmas(mas, a);
        checkmas(mas, b);
        reb.push_back({ a, b });
        return true;
    }
    else {
        return false;
    }
}

bool Cube::checkcor(std::vector<std::pair<unsigned char, std::pair<unsigned char, unsigned
    char>>>&
    cor,
    unsigned char a, unsigned char b, unsigned char c, bool flag, int* mas) {
    if (flag == true) {
        for (unsigned int i = 0; i < cor.size(); i++) {
            std::pair<unsigned char, unsigned char> now = cor[i].second;
            unsigned char first = cor[i].first, second = now.first, third = now.second;
            if ((first == a && second == b && third == c) || (first == a && second == c && third == b) || (first == b && second == a && third == c) || (first == b && second == c && third == a) || (first == c && second == a && third == b) || (first == c && second == b && third == a) || checkcol(a, b) || checkcol(a, c) || checkcol(b, c)) {
                return false;
            }
        }
        checkmas(mas, a);
        checkmas(mas, b);
        checkmas(mas, c);
        cor.push_back({ a, {b, c} });
        return true;
    }
    else {
        return false;
    }
}

void Cube::goodw(int a) {
    while (cube[4][a] == 'w') {
        str += "WR ";
        WR();
    }
}

void Cube::findkrest() {
    for (int i = 0; i < 6; i++) {
        if (i != 4) {
            for (int j = 1; j < 9; j += 2) {
                if (cube[i][j] == 'w') {
                    if (i == 0) {
                        if (j == 1) {
                            goodw(7);
                            str += "BR BR ";
                            BR();
                            BR();
                        }
                        else if (j == 3) {
                            goodw(3);
                            str += "RR RR ";
                            RR();
                            RR();
                        }
                        else if (j == 5) {
                            goodw(5);
                            str += "OR OR ";
                            OR();
                            OR();
                        }
                        else if (j == 7) {
                            goodw(1);
                            str += "GR GR ";
                            GR();
                            GR();
                        }
                    }
                    else if (i == 1) {
                        if (j == 1) {
                            goodw(3);
                            str += "RR WR GL ";
                            RR();
                            WR();
                            GL();
                        }
                        else if (j == 3) {
                            goodw(7);
                            str += "BR ";
                            BR();
                        }
                        else if (j == 5) {
                            goodw(1);
                            str += "GL ";
                            GL();
                        }
                        else if (j == 7) {
                            str += "RL WR GL ";
                            RL();
                            WR();
                            GL();
                        }
                    }
                    else if (i == 2) {
                        if (j == 1) {
                            goodw(1);
                            str += "GR WR OL ";
                            GR();
                            WR();
                            OL();
                        }
                        else if (j == 3) {
                            goodw(3);
                            str += "RR ";
                            RR();
                        }
                        else if (j == 5) {
                            goodw(5);
                            str += "OR ";
                            OL();
                        }
                        else if (j == 7) {
                            str += "GL WR OL ";
                            GL();
                            WR();
                            OL();
                        }
                    }
                    else if (i == 3) {
                        if (j == 1) {
                            goodw(5);
                            str += "OR WR BL ";
                            OR();
                            WR();
                            BL();
                        }
                        else if (j == 3) {
                            goodw(1);
                            str += "GR ";
                            GR();
                        }
                        else if (j == 5) {
                            goodw(7);
                            str += "BL ";
                            BL();
                        }
                        else if (j == 7) {
                            str += "OL WR BL ";
                            OL();
                            WR();
                            BL();
                        }
                    }
                    else if (i == 5) {
                        if (j == 1) {
                            str += "BR WL OR ";
                            BR();
                            WL();
                            OR();
                        }
                        else if (j == 3) {
                            goodw(3);
                            str += "BL ";
                            RL();
                        }
                        else if (j == 5) {
                            goodw(5);
                            str += "OR ";
                            OR();
                        }
                        else if (j == 7) {
                            goodw(7);
                            str += "BL WL OR ";
                            BL();
                            WL();
                            OR();
                        }
                    }
                }
            }
        }
    }
}

void Cube::krest() {
    while (true) {
        if (cube[4][1] == 'w' && cube[4][3] == 'w' && cube[4][5] == 'w' && cube[4][7] == 'w') {
            break;
        }
        else {
            findkrest();
        }
    }
}

int Cube::count_edge_krest() {
    int count = 0;
    if (cube[2][4] == cube[2][7]) {
        count++;
    }
    if (cube[1][4] == cube[1][7]) {
        count++;
    }
    if (cube[3][4] == cube[3][7]) {
        count++;
    }
    if (cube[5][4] == cube[5][1]) {
        count++;
    }
    return count;
}

void Cube::edgekrest() {
    int count = count_edge_krest();
    while (count < 2) {
        str += "WR ";
        WR();
        count = count_edge_krest();
    }
    if (count == 2) {
        if (cube[2][4] == cube[2][7] && cube[5][4] == cube[5][1]) {
            str += "OR WR WR OL WL WL OR ";
            OR();
            WR();
            WR();
            OL();
            WL();
            WL();
            OR();
        }
        else if (cube[1][4] == cube[1][7] && cube[3][4] == cube[3][7]) {
            str += "GR WR WR GL WL WL GR ";
            GR();
            WR();
            WR();
            GL();
            WL();
            WL();
            GR();
        }
        else if (cube[3][4] == cube[3][7] && cube[5][4] == cube[5][1]) {
            str += "GR WR GL WL GR ";
            GR();
            WR();
            GL();
            WL();
            GR();
        }
        else if (cube[3][4] == cube[3][7] && cube[2][4] == cube[2][7]) {
            str += "RR WR RL WL RR ";
            RR();
            WR();
            RL();
            WL();
            RR();
        }
        else if (cube[1][4] == cube[1][7] && cube[2][4] == cube[2][7]) {
            str += "BR WR BL WL BR ";
            BR();
            WR();
            BL();
            WL();
            BR();
        }
        else if (cube[1][4] == cube[1][7] && cube[5][4] == cube[5][1]) {
            str += "OR WR OL WL OR ";
            OR();
            WR();
            OL();
            WL();
            OR();
        }
    }
}

void Cube::cornerwhile(int var) {
    if (var == 0) {
        while (cube[4][0] != 'w' || cube[2][6] != 'g') {
            str += "GR YR GL YL ";
            GR();
            YR();
            GL();
            YL();
        }
    }
    else if (var == 2) {
        while (cube[4][2] != 'w' || cube[3][6] != 'o') {
            str += "OR YR OL YL ";
            OR();
            YR();
            OL();
            YL();
        }
    }
    else if (var == 6) {
        while (cube[4][6] != 'w' || cube[1][6] != 'r') {
            str += "RR YR RL YL ";
            RR();
            YR();
            RL();
            YL();
        }
    }
    else {
        while (cube[4][8] != 'w' || cube[5][2] != 'b') {
            str += "BR YR BL YL ";
            BR();
            YR();
            BL();
            YL();
        }
    }
}

void Cube::R6perebor() {
    str += "RR YR RL YL ";
    RR();
    YR();
    RL();
    YL();
}

void Cube::G6perebor() {
    str += "GR YR GL YL ";
    GR();
    YR();
    GL();
    YL();
}

void Cube::O6perebor() {
    str += "OR YR OL YL ";
    OR();
    YR();
    OL();
    YL();
}

void Cube::B6perebor() {
    str += "BR YR BL YL ";
    BR();
    YR();
    BL();
    YL();
}

void Cube::find_corner() {
    for (int i = 0; i < 6; i++) {
        if (i != 4) {
            for (int j = 0; j < 9; j += 2) {
                if (cube[i][j] == 'w') {
                    if (i == 0) {
                        if (j == 0) {
                            if (cube[1][0] == 'b') {
                                cornerwhile(6);
                            }
                            else if (cube[1][0] == 'r') {
                                str += "YL ";
                                YL();
                                cornerwhile(0);
                            }
                            else if (cube[1][0] == 'o') {
                                str += "YR ";
                                YR();
                                cornerwhile(8);
                            }
                            else {
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(2);
                            }
                        }
                        else if (j == 2) {
                            if (cube[3][2] == 'b') {
                                cornerwhile(8);
                            }
                            else if (cube[3][2] == 'o') {
                                str += "YR ";
                                YR();
                                cornerwhile(2);
                            }
                            else if (cube[3][2] == 'r') {
                                str += "YL ";
                                YL();
                                cornerwhile(6);
                            }
                            else {
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(0);
                            }
                        }
                        else if (j == 6) {
                            if (cube[2][0] == 'r') {
                                cornerwhile(0);
                            }
                            else if (cube[2][0] == 'g') {
                                str += "YL ";
                                YL();
                                cornerwhile(2);
                            }
                            else if (cube[2][0] == 'b') {
                                str += "YR ";
                                YR();
                                cornerwhile(6);
                            }
                            else {
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(8);
                            }
                        }
                        else if (j == 8) {
                            if (cube[2][2] == 'o') {
                                cornerwhile(2);
                            }
                            else if (cube[2][2] == 'g') {
                                str += "YR ";
                                YR();
                                cornerwhile(0);
                            }
                            else if (cube[2][2] == 'b') {
                                str += "YL ";
                                YL();
                                cornerwhile(8);
                            }
                            else {
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(6);
                            }
                        }
                    }
                    else if (i == 1) {
                        if (j == 0) {
                            if (cube[0][0] == 'r') {
                                cornerwhile(6);
                            }
                            else if (cube[0][0] == 'b') {
                                str += "YR ";
                                YR();
                                cornerwhile(8);
                            }
                            else if (cube[0][0] == 'g') {
                                str += "YL ";
                                YL();
                                cornerwhile(0);
                            }
                            else {
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(2);
                            }
                        }
                        else if (j == 2) {
                            if (cube[0][6] == 'r') {
                                cornerwhile(0);
                            }
                            else if (cube[0][6] == 'g') {
                                str += "YL ";
                                YL();
                                cornerwhile(2);
                            }
                            else if (cube[0][6] == 'b') {
                                str += "YR ";
                                YR();
                                cornerwhile(6);
                            }
                            else {
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(8);
                            }
                        }
                        else if (j == 6) {
                            if (cube[4][6] == 'b') {
                                cornerwhile(6);
                            }
                            else if (cube[4][6] == 'r') {
                                R6perebor();
                                str += "YL ";
                                YL();
                                cornerwhile(0);
                            }
                            else if (cube[4][6] == 'o') {
                                R6perebor();
                                str += "YR ";
                                YR();
                                cornerwhile(8);
                            }
                            else {
                                R6perebor();
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(2);
                            }
                        }
                        else if (j == 8) {
                            if (cube[2][6] == 'r') {
                                cornerwhile(0);
                            }
                            else if (cube[2][6] == 'g') {
                                G6perebor();
                                str += "YL ";
                                YL();
                                cornerwhile(2);
                            }
                            else if (cube[2][6] == 'b') {
                                G6perebor();
                                str += "YR ";
                                YR();
                                cornerwhile(6);
                            }
                            else {
                                G6perebor();
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(8);
                            }
                        }
                    }
                    else if (i == 2) {
                        if (j == 0) {
                            if (cube[0][6] == 'g') {
                                cornerwhile(0);
                            }
                            else if (cube[0][6] == 'r') {
                                str += "YR ";
                                YR();
                                cornerwhile(6);
                            }
                            else if (cube[0][6] == 'o') {
                                str += "YL ";
                                YL();
                                cornerwhile(2);
                            }
                            else {
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(8);
                            }
                        }
                        else if (j == 2) {
                            if (cube[0][8] == 'g') {
                                cornerwhile(2);
                            }
                            else if (cube[0][8] == 'r') {
                                str += "YR ";
                                YR();
                                cornerwhile(0);
                            }
                            else if (cube[0][8] == 'o') {
                                str += "YL ";
                                YL();
                                cornerwhile(8);
                            }
                            else {
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(6);
                            }
                        }
                        else if (j == 6) {
                            if (cube[4][0] == 'r') {
                                cornerwhile(0);
                            }
                            else if (cube[4][0] == 'g') {
                                G6perebor();
                                str += "YL ";
                                YL();
                                cornerwhile(2);
                            }
                            else if (cube[4][0] == 'b') {
                                G6perebor();
                                str += "YR ";
                                YR();
                                cornerwhile(6);
                            }
                            else {
                                G6perebor();
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(8);
                            }
                        }
                        else if (j == 8) {
                            if (cube[4][2] == 'o') {
                                cornerwhile(2);
                            }
                            else if (cube[4][2] == 'g') {
                                O6perebor();
                                str += "YR ";
                                YR();
                                cornerwhile(0);
                            }
                            else if (cube[4][2] == 'b') {
                                O6perebor();
                                str += "YL ";
                                YL();
                                cornerwhile(8);
                            }
                            else {
                                O6perebor();
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(6);
                            }
                        }
                    }
                    else if (i == 3) {
                        if (j == 0) {
                            if (cube[2][2] == 'g') {
                                cornerwhile(2);
                            }
                            else if (cube[2][2] == 'r') {
                                str += "YR ";
                                YR();
                                cornerwhile(0);
                            }
                            else if (cube[2][2] == 'o') {
                                str += "YL ";
                                YL();
                                cornerwhile(8);
                            }
                            else {
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(6);
                            }
                        }
                        else if (j == 2) {
                            if (cube[0][2] == 'o') {
                                cornerwhile(8);
                            }
                            else if (cube[0][2] == 'g') {
                                str += "YR ";
                                YR();
                                cornerwhile(2);
                            }
                            else if (cube[0][2] == 'b') {
                                str += "YL ";
                                YL();
                                cornerwhile(6);
                            }
                            else {
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(0);
                            }
                        }
                        else if (j == 6) {
                            if (cube[2][8] == 'o') {
                                cornerwhile(2);
                            }
                            else if (cube[2][8] == 'g') {
                                O6perebor();
                                str += "YR ";
                                YR();
                                cornerwhile(0);
                            }
                            else if (cube[2][8] == 'b') {
                                O6perebor();
                                str += "YL ";
                                YL();
                                cornerwhile(8);
                            }
                            else {
                                O6perebor();
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(6);
                            }
                        }
                        else if (j == 8) {
                            if (cube[4][8] == 'b') {
                                cornerwhile(8);
                            }
                            else if (cube[4][8] == 'o') {
                                B6perebor();
                                str += "YR ";
                                YR();
                                cornerwhile(2);
                            }
                            else if (cube[4][8] == 'r') {
                                B6perebor();
                                str += "YL ";
                                YL();
                                cornerwhile(6);
                            }
                            else {
                                B6perebor();
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(0);
                            }
                        }
                    }
                    else if (i == 5) {
                        if (j == 0) {
                            if (cube[4][6] == 'r') {
                                cornerwhile(6);
                            }
                            else if (cube[4][6] == 'g') {
                                R6perebor();
                                str += "YL ";
                                YL();
                                cornerwhile(0);
                            }
                            else if (cube[4][6] == 'b') {
                                R6perebor();
                                str += "YR ";
                                YR();
                                cornerwhile(8);
                            }
                            else {
                                R6perebor();
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(2);
                            }
                        }
                        else if (j == 2) {
                            if (cube[4][8] == 'o') {
                                cornerwhile(8);
                            }
                            else if (cube[4][8] == 'b') {
                                B6perebor();
                                str += "YL ";
                                YL();
                                cornerwhile(6);
                            }
                            else if (cube[4][8] == 'g') {
                                B6perebor();
                                str += "YR ";
                                YR();
                                cornerwhile(2);
                            }
                            else {
                                B6perebor();
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(0);
                            }
                        }
                        else if (j == 6) {
                            if (cube[1][0] == 'r') {
                                cornerwhile(6);
                            }
                            else if (cube[1][0] == 'b') {
                                str += "YR ";
                                YR();
                                cornerwhile(8);
                            }
                            else if (cube[1][0] == 'g') {
                                str += "YL ";
                                YL();
                                cornerwhile(0);
                            }
                            else {
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(2);
                            }
                        }
                        else if (j == 8) {
                            if (cube[3][2] == 'o') {
                                cornerwhile(8);
                            }
                            else if (cube[3][2] == 'b') {
                                str += "YL ";
                                YL();
                                cornerwhile(6);
                            }
                            else if (cube[3][2] == 'g') {
                                str += "YR ";
                                YR();
                                cornerwhile(2);
                            }
                            else {
                                str += "YR YR ";
                                YR();
                                YR();
                                cornerwhile(0);
                            }
                        }
                    }
                }
            }
        }
    }
    if (cube[1][6] != 'r') {
        str += "RR YR RL YL ";
        RR();
        YR();
        RL();
        YL();
    }
    else if (cube[2][6] != 'g') {
        str += "GR YR GL YL ";
        GR();
        YR();
        GL();
        YL();
    }
    else if (cube[3][6] != 'o') {
        str += "OR YR OL YL ";
        OR();
        YR();
        OL();
        YL();
    }
    else if (cube[5][2] != 'b') {
        str += "BR YR BL YL ";
        BR();
        YR();
        BL();
        YL();
    }
}

void Cube::Bedge() {
    if (cube[0][1] == 'o') {
        str += "YL OL YR OR YR BR YL BL ";
        YL();
        OL();
        YR();
        OR();
        YR();
        BR();
        YL();
        BL();
    }
    else {
        str += "YR RR YL RL YL BL YR BR ";
        YR();
        RR();
        YL();
        RL();
        YL();
        BL();
        YR();
        BR();
    }
}

void Cube::Redge() {
    if (cube[0][3] == 'b') {
        str += "YL BL YR BR YR RR YL RL ";
        YL();
        BL();
        YR();
        BR();
        YR();
        RR();
        YL();
        RL();
    }
    else {
        str += "YR GR YL GL YL RL YR RR ";
        YR();
        GR();
        YL();
        GL();
        YL();
        RL();
        YR();
        RR();
    }
}

void Cube::Gedge() {
    if (cube[0][7] == 'r') {
        str += "YL RL YR RR YR GR YL GL ";
        YL();
        RL();
        YR();
        RR();
        YR();
        GR();
        YL();
        GL();
    }
    else {
        str += "YR OR YL OL YL GL YR GR ";
        YR();
        OR();
        YL();
        OL();
        YL();
        GL();
        YR();
        GR();
    }
}

void Cube::Oedge() {
    if (cube[0][5] == 'g') {
        str += "YL GL YR GR YR OR YL OL ";
        YL();
        GL();
        YR();
        GR();
        YR();
        OR();
        YL();
        OL();
    }
    else {
        str += "YR BR YL BL YL OL YR OR ";
        YR();
        BR();
        YL();
        BL();
        YL();
        OL();
        YR();
        OR();
    }
}

void Cube::find_edge() {
    for (int j = 1; j < 9; j += 2) {
        if (cube[0][1] != 'y' && cube[5][7] != 'y') {
            if (cube[5][7] == 'g') {
                str += "YR YR ";
                YR();
                YR();
                Gedge();
            }
            else if (cube[5][7] == 'r') {
                str += "YL ";
                YL();
                Redge();
            }
            else if (cube[5][7] == 'o') {
                str += "YR ";
                YR();
                Oedge();
            }
            else {
                Bedge();
            }
        }
        else if (cube[0][5] != 'y' && cube[3][1] != 'y') {
            if (cube[3][1] == 'g') {
                str += "YR ";
                YR();
                Gedge();
            }
            else if (cube[3][1] == 'r') {
                str += "YR YR ";
                YR();
                YR();
                Redge();
            }
            else if (cube[3][1] == 'o') {
                Oedge();
            }
            else {
                str += "YL ";
                YL();
                Bedge();
            }
        }
        else if (cube[0][3] != 'y' && cube[1][1] != 'y') {
            if (cube[1][1] == 'g') {
                str += "YL ";
                YL();
                Gedge();
            }
            else if (cube[1][1] == 'r') {
                Redge();
            }
            else if (cube[1][1] == 'o') {
                str += "YR YR ";
                YR();
                YR();
                Oedge();
            }
            else {
                str += "YR ";
                YR();
                Bedge();
            }
        }
        else if (cube[0][7] != 'y' && cube[2][1] != 'y') {
            if (cube[2][1] == 'g') {
                Gedge();
            }
            else if (cube[2][1] == 'r') {
                str += "YR ";
                YR();
                Redge();
            }
            else if (cube[2][1] == 'o') {
                str += "YL ";
                YL();
                Oedge();
            }
            else {
                str += "YR YR ";
                YR();
                YR();
                Bedge();
            }
        }
    }
    if ((cube[1][5] != 'r' || cube[2][3] != 'g') && cube[1][5] != 'y' && cube[2][3] != 'y') {
        str += "GR YL GL YL RL YR RR ";
        GR();
        YL();
        GL();
        YL();
        RL();
        YR();
        RR();
    }
    else if ((cube[2][5] != 'g' || cube[3][3] != 'o') && cube[2][5] != 'y' && cube[3][3] != 'y') {
        str += "OR YL OL YL GL YR GR ";
        OR();
        YL();
        OL();
        YL();
        GL();
        YR();
        GR();
    }
    else if ((cube[3][5] != 'o' || cube[5][5] != 'b') && cube[3][5] != 'y' && cube[5][5] != 'y') {
        str += "BR YL BL YL OL YR OR ";
        BR();
        YL();
        BL();
        YL();
        OL();
        YR();
        OR();
    }
    else if ((cube[5][3] != 'b' || cube[1][3] != 'r') && cube[5][3] != 'y' && cube[1][3] != 'y') {
        str += "RR YL RL YL BL YR BR ";
        RR();
        YL();
        RL();
        YL();
        BL();
        YR();
        BR();
    }
}

void Cube::firstsloi() {
    while (true) {
        if (cube[4][0] == 'w' && cube[4][2] == 'w' && cube[4][6] == 'w' && cube[4][8] == 'w' && cube[1][6] == 'r' && cube[1][8] == 'r' && cube[2][6] == 'g' && cube[2][8] == 'g' && cube[3][6] == 'o' && cube[3][8] == 'o' && cube[5][0] == 'b' && cube[5][2] == 'b') {
            break;
        }
        else {
            find_corner();
        }
    }
}

void Cube::secondsloi() {
    while (true) {
        if (cube[2][3] == 'g' && cube[2][5] == 'g' && cube[1][3] == 'r' && cube[1][5] == 'r' && cube[3][3] == 'o' && cube[3][5] == 'o' && cube[5][3] == 'b' && cube[5][5] == 'b') {
            break;
        }
        else {
            find_edge();
        }
    }
}

void Cube::ykrestG(int count) {
    for (int i = 0; i < count; i++) {
        str += "GR OR YR OL YL GL ";
        GR();
        OR();
        YR();
        OL();
        YL();
        GL();
    }
}

void Cube::ykrestR(int count) {
    for (int i = 0; i < count; i++) {
        str += "RR GR YR GL YL RL ";
        RR();
        GR();
        YR();
        GL();
        YL();
        RL();
    }
}

bool Cube::ykrest() {
    if (cube[0][1] != 'y' && cube[0][3] != 'y' && cube[0][5] != 'y' && cube[0][7] != 'y') {
        ykrestR(2);
        ykrestG(1);
    }
    else if (cube[0][1] == 'y' && cube[0][3] == 'y' && cube[0][5] != 'y' && cube[0][7] != 'y') {
        str += "YR ";
        YR();
        ykrestR(2);
    }
    else if (cube[0][1] == 'y' && cube[0][3] != 'y' && cube[0][5] == 'y' && cube[0][7] != 'y') {
        ykrestR(2);
    }
    else if (cube[0][1] != 'y' && cube[0][3] != 'y' && cube[0][5] == 'y' && cube[0][7] == 'y') {
        str += "YL ";
        YL();
        ykrestR(2);
    }
    else if (cube[0][1] != 'y' && cube[0][3] == 'y' && cube[0][5] != 'y' && cube[0][7] == 'y') {
        str += "YR YR ";
        YR();
        YR();
        ykrestR(2);
    }
    else if (cube[0][1] == 'y' && cube[0][3] != 'y' && cube[0][5] != 'y' && cube[0][7] == 'y') {
        ykrestR(1);
    }
    else if (cube[0][1] != 'y' && cube[0][3] == 'y' && cube[0][5] == 'y' && cube[0][7] != 'y') {
        str += "YR ";
        YR();
        ykrestR(1);
    }
    else if (cube[0][1] == 'y' && cube[0][3] == 'y' && cube[0][5] == 'y' && cube[0][7] == 'y') {

    }
    else {
        return false;
    }
    return true;
}

void Cube::vertolet() {
    str += "OR YL YL OL OL YL OR OR YL OL OL YL YL OR ";
    OR();
    YL();
    YL();
    OL();
    OL();
    YL();
    OR();
    OR();
    YL();
    OL();
    OL();
    YL();
    YL();
    OR();
}

void Cube::ushki() {
    str += "GR OR BL OL GL OR BR OL ";
    GR();
    OR();
    BL();
    OL();
    GL();
    OR();
    BR();
    OL();
}

void Cube::nos() {
    str += "OL GL RL GR OR GL RR GR ";
    OL();
    GL();
    RL();
    GR();
    OR();
    GL();
    RR();
    GR();
}

void Cube::glazki() {
    str += "OR OR WR OL YR YR OR WL OL YR YR OL ";
    OR();
    OR();
    WR();
    OL();
    YR();
    YR();
    OR();
    WL();
    OL();
    YR();
    YR();
    OL();
}

void Cube::triplpifpaf() {
    str += "GR ";
    GR();
    for (int i = 0; i < 3; i++) {
        str += "OR YR OL YL ";
        OR();
        YR();
        OL();
        YL();
    }
    GL();
    str += "GL ";
}

void Cube::Rriba() {
    str += "OR YR OL YR OR YR YR OL ";
    OR();
    YR();
    OL();
    YR();
    OR();
    YR();
    YR();
    OL();
}

void Cube::Lriba() {
    str += "RL YL RR YL RL YL YL RR ";
    RL();
    YL();
    RR();
    YL();
    RL();
    YL();
    YL();
    RR();
}

bool Cube::ycor() {
    if (cube[1][0] == 'y' && cube[1][2] == 'y' && cube[2][2] == 'y' && cube[5][8] == 'y') {
        vertolet();
    }
    else if (cube[3][0] == 'y' && cube[1][2] == 'y' && cube[5][6] == 'y' && cube[5][8] == 'y') {
        str += "YL ";
        YL();
        vertolet();
    }
    else if (cube[1][0] == 'y' && cube[2][0] == 'y' && cube[2][2] == 'y' && cube[3][2] == 'y') {
        str += "YR ";
        YR();
        vertolet();
    }
    else if (cube[3][0] == 'y' && cube[3][2] == 'y' && cube[2][0] == 'y' && cube[5][6] == 'y') {
        str += "YR YR ";
        YR();
        YR();
        vertolet();
    }
    else if (cube[1][2] == 'y' && cube[3][0] == 'y' && cube[0][0] == 'y' && cube[0][2] == 'y') {
        ushki();
    }
    else if (cube[2][2] == 'y' && cube[5][8] == 'y' && cube[0][0] == 'y' && cube[0][6] == 'y') {
        str += "YR ";
        YR();
        ushki();
    }
    else if (cube[5][6] == 'y' && cube[2][0] == 'y' && cube[0][8] == 'y' && cube[0][2] == 'y') {
        str += "YL ";
        YL();
        ushki();
    }
    else if (cube[3][2] == 'y' && cube[1][0] == 'y' && cube[0][8] == 'y' && cube[0][6] == 'y') {
        str += "YR YR ";
        YR();
        YR();
        ushki();
    }
    else if (cube[5][8] == 'y' && cube[1][2] == 'y' && cube[0][0] == 'y' && cube[0][8] == 'y') {
        nos();
    }
    else if (cube[1][0] == 'y' && cube[2][2] == 'y' && cube[0][2] == 'y' && cube[0][6] == 'y') {
        str += "YR ";
        YR();
        nos();
    }
    else if (cube[5][6] == 'y' && cube[3][0] == 'y' && cube[0][2] == 'y' && cube[0][6] == 'y') {
        str += "YL ";
        YL();
        nos();
    }
    else if (cube[2][0] == 'y' && cube[3][2] == 'y' && cube[0][0] == 'y' && cube[0][8] == 'y') {
        str += "YR YR ";
        YR();
        YR();
        nos();
    }
    else if (cube[2][0] == 'y' && cube[2][2] == 'y' && cube[0][0] == 'y' && cube[0][2] == 'y') {
        glazki();
    }
    else if (cube[3][0] == 'y' && cube[3][2] == 'y' && cube[0][0] == 'y' && cube[0][6] == 'y') {
        str += "YR ";
        YR();
        glazki();
    }
    else if (cube[1][0] == 'y' && cube[1][2] == 'y' && cube[0][8] == 'y' && cube[0][2] == 'y') {
        str += "YL ";
        YL();
        glazki();
    }
    else if (cube[5][6] == 'y' && cube[5][8] == 'y' && cube[0][6] == 'y' && cube[0][8] == 'y') {
        str += "YR YR ";
        YR();
        YR();
        glazki();
    }
    else if (cube[5][6] == 'y' && cube[5][8] == 'y' && cube[2][0] == 'y' && cube[2][2] == 'y') {
        triplpifpaf();
    }
    else if (cube[1][0] == 'y' && cube[1][2] == 'y' && cube[3][0] == 'y' && cube[3][2] == 'y') {
        str += "YR ";
        YR();
        triplpifpaf();
    }
    else if (cube[0][6] == 'y' && cube[2][2] == 'y' && cube[3][2] == 'y' && cube[5][6] == 'y') {
        Rriba();
    }
    else if (cube[0][8] == 'y' && cube[1][2] == 'y' && cube[3][2] == 'y' && cube[5][6] == 'y') {
        str += "YR ";
        YR();
        Rriba();
    }
    else if (cube[0][0] == 'y' && cube[2][2] == 'y' && cube[3][2] == 'y' && cube[1][2] == 'y') {
        str += "YL ";
        YL();
        Rriba();
    }
    else if (cube[0][2] == 'y' && cube[2][2] == 'y' && cube[1][2] == 'y' && cube[5][6] == 'y') {
        str += "YR YR ";
        YR();
        YR();
        Rriba();
    }
    else if (cube[0][8] == 'y' && cube[2][0] == 'y' && cube[1][0] == 'y' && cube[5][8] == 'y') {
        Lriba();
    }
    else if (cube[0][2] == 'y' && cube[2][0] == 'y' && cube[1][0] == 'y' && cube[3][0] == 'y') {
        str += "YR ";
        YR();
        Lriba();
    }
    else if (cube[0][6] == 'y' && cube[3][0] == 'y' && cube[1][0] == 'y' && cube[5][8] == 'y') {
        str += "YL ";
        YL();
        Lriba();
    }
    else if (cube[0][0] == 'y' && cube[2][0] == 'y' && cube[3][0] == 'y' && cube[5][8] == 'y') {
        str += "YR YR ";
        YR();
        YR();
        Lriba();
    }
    else if (cube[0][6] == 'y' && cube[0][2] == 'y' && cube[0][0] == 'y' && cube[0][8] == 'y') {

    }
    else {
        return false;
    }
    return true;
}

void Cube::havepair() {
    str += "GR YR GL YL GL RR GR GR YL GL YL GR YR GL RL ";
    GR();
    YR();
    GL();
    YL();
    GL();
    RR();
    GR();
    GR();
    YL();
    GL();
    YL();
    GR();
    YR();
    GL();
    RL();
}

void Cube::notpair() {
    str += "RR GR YL GL YL GR YR GL RL GR YR GL YL GL RR GR RL ";
    RR();
    GR();
    YL();
    GL();
    YL();
    GR();
    YR();
    GL();
    RL();
    GR();
    YR();
    GL();
    YL();
    GL();
    RR();
    GR();
    RL();
}

void Cube::lastcor() {
    if (cube[5][6] == cube[5][8] && cube[1][0] != cube[1][2]) {
        havepair();
    }
    else if (cube[1][0] == cube[1][2] && cube[2][0] != cube[2][2]) {
        str += "YR ";
        YR();
        havepair();
    }
    else if (cube[3][0] == cube[3][2] && cube[2][0] != cube[2][2]) {
        str += "YL ";
        YL();
        havepair();
    }
    else if (cube[2][0] == cube[2][2] && cube[1][0] != cube[1][2]) {
        str += "YR YR ";
        YR();
        YR();
        havepair();
    }
    else if (cube[1][0] == cube[1][2] && cube[3][0] == cube[3][2]) {

    }
    else {
        notpair();
    }
}

void Cube::lastgl() {
    str += "RL YR RL YL RL YL RL YR RR YR RR RR ";
    RL();
    YR();
    RL();
    YL();
    RL();
    YL();
    RL();
    YR();
    RR();
    YR();
    RR();
    RR();
}

void Cube::lastgr() {
    str += "OR YL OR YR OR YR OR YL OL YL OL OL ";
    OR();
    YL();
    OR();
    YR();
    OR();
    YR();
    OR();
    YL();
    OL();
    YL();
    OL();
    OL();
}

void Cube::lastol() {
    str += "GL YR GL YL GL YL GL YR GR YR GR GR ";
    GL();
    YR();
    GL();
    YL();
    GL();
    YL();
    GL();
    YR();
    GR();
    YR();
    GR();
    GR();
}

void Cube::lastor() {
    str += "BR YL BR YR BR YR BR YL BL YL BL BL ";
    BR();
    YL();
    BR();
    YR();
    BR();
    YR();
    BR();
    YL();
    BL();
    YL();
    BL();
    BL();
}

void Cube::lastbl() {
    str += "OL YR OL YL OL YL OL YR OR YR OR OR ";
    OL();
    YR();
    OL();
    YL();
    OL();
    YL();
    OL();
    YR();
    OR();
    YR();
    OR();
    OR();
}

void Cube::lastbr() {
    str += "RR YL RR YR RR YR RR YL RL YL RL RL ";
    RR();
    YL();
    RR();
    YR();
    RR();
    YR();
    RR();
    YL();
    RL();
    YL();
    RL();
    RL();
}

void Cube::lastrl() {
    str += "BL YR BL YL BL YL BL YR BR YR BR BR ";
    BL();
    YR();
    BL();
    YL();
    BL();
    YL();
    BL();
    YR();
    BR();
    YR();
    BR();
    BR();
}

void Cube::lastrr() {
    str += "GR YL GR YR GR YR GR YL GL YL GL GL ";
    GR();
    YL();
    GR();
    YR();
    GR();
    YR();
    GR();
    YL();
    GL();
    YL();
    GL();
    GL();
}

bool Cube::lastedge() {
    if (cube[2][1] == 'r' && cube[1][1] == 'o' && cube[3][1] == 'g' && cube[5][7] == 'b') {
        lastgl();
    }
    else if (cube[2][1] == 'o' && cube[1][1] == 'g' && cube[3][1] == 'r' && cube[5][7] == 'b') {
        lastgr();
    }
    else if (cube[2][1] == 'b' && cube[1][1] == 'r' && cube[3][1] == 'g' && cube[5][7] == 'o') {
        lastol();
    }
    else if (cube[2][1] == 'o' && cube[1][1] == 'r' && cube[3][1] == 'b' && cube[5][7] == 'g') {
        lastor();
    }
    else if (cube[2][1] == 'g' && cube[1][1] == 'o' && cube[3][1] == 'b' && cube[5][7] == 'r') {
        lastbr();
    }
    else if (cube[2][1] == 'g' && cube[1][1] == 'b' && cube[3][1] == 'r' && cube[5][7] == 'o') {
        lastbl();
    }
    else if (cube[2][1] == 'r' && cube[1][1] == 'b' && cube[3][1] == 'o' && cube[5][7] == 'g') {
        lastrl();
    }
    else if (cube[2][1] == 'b' && cube[1][1] == 'g' && cube[3][1] == 'o' && cube[5][7] == 'r') {
        lastrr();
    }
    else if (cube[1][1] == 'o' && cube[2][1] == 'b' && cube[3][1] == 'r' && cube[5][7] == 'g') {
        lastol();
        lastgl();
    }
    else if (cube[1][1] == 'g' && cube[2][1] == 'r' && cube[3][1] == 'b' && cube[5][7] == 'o') {
        lastor();
        lastgr();
    }
    else if (cube[1][1] == 'b' && cube[2][1] == 'o' && cube[3][1] == 'g' && cube[5][7] == 'r') {
        lastol();
        lastbl();
    }
    else if (cube[1][1] == 'r' && cube[2][1] == 'g' && cube[3][1] == 'o' && cube[5][7] == 'b') {

    }
    else {
        return false;
    }
    return true;
}

void Cube::littlecheck(int& count) {
    for (int j = 0; j < 9; j++) {
        if (cube[0][j] != 'y' || cube[1][j] != 'r' || cube[2][j] != 'g' || cube[3][j] != 'o' || cube[4][j] != 'w' || cube[5][j] != 'b') {
            count++;
            break;
        }
    }
}