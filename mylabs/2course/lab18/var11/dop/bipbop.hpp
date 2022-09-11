#pragma once

#include <cstdlib>
#include "includes/json.hpp"

using namespace std;

struct BitMapFileHeader {
    uint16_t Type;             //  2  0   Сигнатура "BM"
    uint32_t Size;             //  4  2   Размер файла
    uint16_t Reserved1;        //  2  6   Зарезервировано
    uint16_t Reserved2;        //  2  8   Зарезервировано
    uint32_t OffsetBits;       //  4  10  Смещение изображения от начала файла
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(BitMapFileHeader, Type, Size, Reserved1, Reserved2, OffsetBits)

struct BitMapInfoHeader {
    uint32_t Size;             //  4  14  Длина заголовка
    uint32_t Width;            //  4  18  Ширина изображения, точки
    uint32_t Height;           //  4  22  Высота изображения, точки
    uint16_t Planes;           //  2  26  Число плоскостей
    uint16_t BitCount;         //  2  28  Глубина цвета, бит на точку
    uint32_t Compression;      //  4  30  Тип компрессии
    uint32_t SizeImage;        //  4  34  Размер изображения, байт
    uint32_t XpelsPerMeter;    //  4  38  Горизонтальное разрешение, точки на метр
    uint32_t YpelsPerMeter;    //  4  42  Вертикальное разрешение, точки на метр
    uint32_t ColorsUsed;       //  4  46  Число используемых цветов
    uint32_t ColorsImportant;  //  4  50  Число основных цветов
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(BitMapInfoHeader, Size, Width, Height, Planes, BitCount, Compression, SizeImage, XpelsPerMeter, YpelsPerMeter, ColorsUsed, ColorsImportant)

struct BGRA {
    uint8_t Blue;
    uint8_t Green;
    uint8_t Red;
    uint8_t Alpha;

    BGRA(uint32_t i) {
        Blue = (i >> 24) & 0xFF;
        Green = (i >> 16) & 0xFF;
        Red = (i >> 8) & 0xFF;
        Alpha = (i >> 0) & 0xFF;
    }
};

uint32_t get(FILE* f, uint8_t bytes) {
    uint32_t temp = 0;
    for (int i = 0; i < bytes; i++)
        temp |= getc(f) << (8 * i); // little-endian
    return temp;
}

