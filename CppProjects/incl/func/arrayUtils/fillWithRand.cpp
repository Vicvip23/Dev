#include <ctime>
#include <cstdlib>

namespace arrayUtils {
void fillWithRand(int* arr, int len, int max = 100){

    srand(time(NULL));

    for(int i = 0; i < len; i++){

        *(arr + i) = (rand() % max + 1);

    };

}
}
