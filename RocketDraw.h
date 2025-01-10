#ifndef _ROCKETDRAW_
#define _ROCKETDRAW_

#include <fstream>
#include <string>
#include <vector>


class RocketDraw {
private:
    std::ifstream file;
    int lineCount;

public:
    RocketDraw();

    bool openFile(const std::string& fileName);
    void closeFile();
    std::string readLine();
    void printMoveRocket(const std::string& fileName);
    void openAndDisplayFile(const std::string& fileName);
    void counter();
};


#endif // !_ROCKETDRAW_


