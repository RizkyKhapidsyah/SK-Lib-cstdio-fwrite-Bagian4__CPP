#pragma warning(disable:4996)

#include <cstdio>
#include <vector>
#include <array>
#include <conio.h>

/*
    Source by CPPReference (https://en.cppreference.com)
    Modified For Learn by RK
    I.D.E : VS2022
*/

int main() {
    // tulis buffer ke file
    if (std::FILE* f1 = std::fopen("file.bin", "wb")) {
        std::array<int, 3> v = { 42, -1, 7 }; // penyimpanan yang mendasari std::array adalah array
        std::fwrite(v.data(), sizeof v[0], v.size(), f1);
        std::fclose(f1);
    }

    // membaca data yang sama dan mencetaknya ke output standar
    if (std::FILE* f2 = std::fopen("file.bin", "rb")) {
        std::vector<int> rbuf(10); // penyimpanan yang mendasari std::vector juga sebuah array
        std::size_t sz = std::fread(rbuf.data(), sizeof rbuf[0], rbuf.size(), f2);
        std::fclose(f2);

        for (std::size_t n = 0; n < sz; ++n) {
            std::printf("%d\n", rbuf[n]);
        }
    }

    _getch();
    return 0;
}