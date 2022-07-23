#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

const int64_t MOD = 1000000007;

/*
Matrix multiplication with integer values not exceeding 1 000 000 007
*/
void matrix_multiplication(const std::vector<int64_t>& first_matrix,
    const std::vector<int64_t>& second_matrix, std::vector<int64_t>* result_matrix)
{
    const int64_t matrix_size = sqrt(result_matrix->size());
    std::vector<int64_t> tmp(matrix_size * matrix_size);

    for (int64_t i = 0; i < matrix_size; ++i)
    {
        for (int64_t k = 0; k < matrix_size; ++k)
        {
            for (int64_t j = 0; j < matrix_size; ++j) 
            {
                tmp[i * matrix_size + j] += (first_matrix[i * matrix_size + k] *
                    second_matrix[k * matrix_size + j]) % MOD;
            }
        }
    }

    for (int64_t i = 0; i < matrix_size; ++i)
    {
        for (int64_t j = 0; j < matrix_size; ++j) {
            (*result_matrix)[i * matrix_size + j] = tmp[i * matrix_size + j] % MOD;
        }
    }
    return;
}

std::vector<int64_t> make_identity_matrix(const int64_t matrix_size)
{
    std::vector<int64_t> identity_matrix(matrix_size * matrix_size);
    for (int64_t i = 0; i < matrix_size; i++) {
        identity_matrix[i * matrix_size + i] = 1;
    }
    return identity_matrix;
}

/*
Raises adjacency_matrix to a power
*/
std::vector<int64_t> binpow(int64_t power, const std::vector<int64_t>& adjacency_matrix)
{
    int64_t matrix_size = sqrt(adjacency_matrix.size());

    std::vector<int64_t> result_matrix = make_identity_matrix(matrix_size);
    std::vector<int64_t> adjacency_matrix_copy(adjacency_matrix);

    while (power)
    {
        if (power & 1)
        {
            matrix_multiplication(adjacency_matrix_copy,
                result_matrix, &result_matrix);
        }
        matrix_multiplication(adjacency_matrix_copy,
            adjacency_matrix_copy, &adjacency_matrix_copy);
        power >>= 1;
    }
    return result_matrix;
}

std::vector<int64_t> make_adjacency_matrix(const int64_t number_of_edges,
    const int64_t matrix_size, std::istream& in)
{
    int64_t h, l;
    std::vector<int64_t> adjacency_matrix(matrix_size * matrix_size);

    for (int64_t i = 0; i < number_of_edges; i++)
    {
        in >> h >> l;
        adjacency_matrix[(h - 1) * matrix_size + (l - 1)] += 1;
    }

    return adjacency_matrix;
}

std::tuple<int64_t, int64_t, int64_t> read(std::istream& in)
{
    int64_t matrix_size, number_of_edges, path_len;
    in >> matrix_size >> number_of_edges >> path_len;
    return std::make_tuple(matrix_size, number_of_edges, path_len);
}

int64_t get_answer(const std::vector<int64_t>& result_matrix) {
    int64_t answer = 0;
    const int64_t matrix_size = sqrt(result_matrix.size());

    for (int64_t i = 0; i < matrix_size; ++i) {
        answer += result_matrix[i] % MOD;
    }

    return answer;
}

void solve_task(std::istream& in)
{
    int64_t answer;
    int64_t matrix_size, number_of_edges, path_len;

    std::tie(matrix_size, number_of_edges, path_len) = read(in);

    std::vector<int64_t> adjacency_matrix = 
        make_adjacency_matrix(number_of_edges, matrix_size, in);

    std::vector<int64_t> result_matrix = binpow(path_len, adjacency_matrix);

    answer = get_answer(result_matrix);
    std::cout << answer;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve_task(std::cin);

    return 0;
}
