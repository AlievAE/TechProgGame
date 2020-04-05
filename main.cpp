#include "src/field.cpp"

int main() {
    Field Field = Sing::field;
    Field.create_unit(3, 0);
    Field.upgrade(0, 0);
    std::cout << Field.player[0]->army.size() << std::endl;
    std::cout << Field.player[1]->army.size() << std::endl;
    return 0;
}
