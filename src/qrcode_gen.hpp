#pragma once

#include "square_image.hpp"

#include <vector>
#include <cstdint>
#include <cstdlib>
#include <string>

class QRcodeGen
{
public:
    QRcodeGen(unsigned version, unsigned ecc);

    void init(unsigned scale);
    bool generate(std::string str);
    const SquareImage& getImage();

private:
    unsigned mVersion;
    unsigned mEcc;
    unsigned mScale;
    std::string mFileName;

    std::vector<uint8_t> mQrCodeData;
    bool checkStringFits(std::string str, unsigned version, unsigned eccType);

    SquareImage mSquareImage;
};