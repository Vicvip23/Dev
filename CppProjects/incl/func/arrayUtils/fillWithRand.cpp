#include <ctime>
#include <cstdlib>

namespace arrayUtils {
void fillWithRand(int* arr, int len){

    srand(time(NULL));

    for(int i = 0; i < len; i++){

        *(arr + i) = (rand() % 100 + 1);

    };

}
}
