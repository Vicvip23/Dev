#include <vector>
#include <ctime>
#include <cstdlib>

int fillWithUnique(int* array, int length, int range, bool includeMax){

    srand(time(NULL));
    std::vector<int> values;

    if(length > range){
        return -1;
    };

    for(int i = 0; i < range; i++){

        if(includeMax){
            values.push_back(i + 1);
        } else {
            values.push_back(i);
        };

    };

    for(int i = 0; i < length; i++){
        
        int index;
        index = rand() % values.size();
        array[i] = values[index];
        values.erase(values.begin() + index);

    };

    return 0;

}
