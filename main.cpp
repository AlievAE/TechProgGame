#include "src/lancer.cpp"
#include "src/archer.cpp"
#include "src/cavalry_lancer.cpp"
#include "src/cavalry_archer.cpp"

main() {
    warrior* ALEXEI = new archer(0, 1);
    warrior* EGOR = new lancer(1, 0);
    EGOR->position = 3;
    std::cout << ALEXEI->attack(EGOR) << std::endl;
    std::cout << ALEXEI->attack(EGOR) << std::endl;
    std::cout << EGOR->dead << std::endl;
}
