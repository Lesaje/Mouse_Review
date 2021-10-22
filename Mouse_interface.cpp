#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

typedef std::vector<std::vector<int64_t>> matrix;

const int64_t MODULE = 1000000007;

struct instance_variables
{
    int64_t matrix_size;
    int64_t number_of_edges;
    int64_t path_len;
};

/*
Matrix multiplication with integer values not exceeding 1 000 000 007
*/
void matrix_multiplication(const matrix& first_matrix,
    const matrix& second_matrix, matrix* result_matrix);

matrix make_identity_matrix(const int64_t matrix_size);

/*
Raises adjacency_matrix to a power
*/
matrix binpow(int64_t power, const matrix& adjacency_matrix);

matrix make_adjacency_matrix(const int64_t number_of_edges,
    const int64_t matrix_size, std::istream& in);

instance_variables read(std::istream& in);

int64_t get_answer(const matrix& result_matrix);

const int64_t solve_task(const matrix& adjacency_matrix, const int64_t path_len);

void output(std::ostream& out, const int64_t answer);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    instance_variables input_data = read(std::cin);

    matrix adjacency_matrix = make_adjacency_matrix(input_data.number_of_edges,
        input_data.matrix_size, std::cin);

    const int64_t answer = solve_task(adjacency_matrix, input_data.path_len);

    output(std::cout, answer);
    return 0;
}
