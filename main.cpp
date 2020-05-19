#include "src/field.cpp"

int main() {
    Field Field = Sing::field;
    Field.create_unit(3, 0);
    Field.upgrade(0, 0);

    return 0;
}
