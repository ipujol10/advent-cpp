#ifndef DAY17_2015
#define DAY17_2015

#include <string>

namespace d17 {
int ways(int* containers, int n, int goal);
int ways(int* containers, int n, int goal, int sum, int k);
int getData(const std::string& file_name, int* containers);
int getMinContainers(int* containers, int n, int goal);
int getMinContainers(int* containers, int n, int goal, int sum,
        int k, int current);
int waysMin(int* containers, int n, int goal, int min);
int waysMin(int* containers, int n, int goal, int sum, int k,
        int current, int min);
}

#endif // !DAY17_2015
