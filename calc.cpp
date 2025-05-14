#include <iostream>
enum class Operation {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};
class Calculator {
public:
    Calculator(Operation operation) {
        this->operation = operation;
    }
    int calculate(int a, int b) {
        switch(operation) {
            case(Operation::ADD): {
                return a + b;
            } break;
            case(Operation::SUBTRACT): {
                return a - b;
            } break;
            case(Operation::MULTIPLY): {
                return a * b;
            } break;
            case(Operation::DIVIDE): {
                if (b == 0) {
                    throw std::invalid_argument("Division by zero");
                }
                return a / b;
            } break;
            default:
                throw std::invalid_argument("Invalid operation");
        }
    }
private:
    Operation operation;
};
int main() {
    Calculator calc {Operation::MULTIPLY};
    printf("%d\n", calc.calculate(3, 5));
    return 0;
}