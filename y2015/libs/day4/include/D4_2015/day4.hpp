#ifndef DAY4_HPP
#define DAY4_HPP

#include <string>

namespace d4 {
    std::string md5(const std::string& msg);
    // from: https://www.programmingalgorithms.com/algorithm/md5/cpp/
    typedef union uwb {
        unsigned w;
        unsigned char b[4];
    } MD5union;
    typedef unsigned DigestArray[4];
    static unsigned func0(unsigned abcd[]);
    static unsigned func1(unsigned abcd[]);
    static unsigned func2(unsigned abcd[]);
    static unsigned func3(unsigned abcd[]);
    typedef unsigned(*DgstFctn)(unsigned a[]);
    static unsigned *calctable(unsigned *k);
    static unsigned rol(unsigned r, short N);
    static unsigned* MD5Hash(const std::string& msg);

    std::string getNumber(const std::string& key);
    bool goodHash(const std::string& hash);
}

#endif // !DAY4_HPP
