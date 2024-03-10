#include <iostream>

namespace animals {
    std::string dog = "Bobby";
    std::string cat = "Lilly";
}

namespace outer {
    int x = 10;

    namespace inner {
        int y = 20;
    }
}

namespace metrics {
    int radius = 3;
    int width = 200;

    namespace font {
        int size = 15;
    }
}

int main() {

    using namespace metrics;
    using namespace metrics::font;

    std::cout << "Dog's name: " <<  animals::dog << std::endl;
    std::cout << "Cat's name: " <<  animals::cat << std::endl;

    std::cout << "Outer X: " << outer::x << std::endl;
    std::cout << "Inner Y: " << outer::inner::y << std::endl;

    std::cout << "Metrics radius: " << radius << std::endl;
    std::cout << "Metrics width: " << width<< std::endl;

    std::cout << "Metrics width: " << size << std::endl;


    return 0;
}
