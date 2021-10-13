#include <iostream>
#include <vector>

const int64_t MOD = 1000000007;

/*
matrix multiplication C=A*B for square matrices with dimensionality = N
and with values for integers not exceeding 1 000 000 007
*/
void mat_mul(const int64_t N, std::vector<int64_t>* A,
    std::vector<int64_t>* B, std::vector<int64_t>* C,
    std::vector<int64_t>* tmp);

/*
Raises a matrix adj to a power k, saving result in res
*/
void binpow(const int64_t N, int64_t k, std::vector<int64_t>* adj,
    std::vector<int64_t>* res, std::vector<int64_t>* tmp);

void make_identity_matrix(const int64_t N, std::vector<int64_t>* matrix);

void input(const int64_t N, const int64_t M,
    std::vector<int64_t>* matrix, std::istream& in);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int64_t matrix_dimensionality, number_of_edges, path_length, answer = 0;

    std::cin >> matrix_dimensionality;
    std::cin >> number_of_edges;
    std::cin >> path_length;

    std::vector<int64_t> adj(matrix_dimensionality * matrix_dimensionality);
    std::vector<int64_t> res(matrix_dimensionality * matrix_dimensionality);
    std::vector<int64_t> tmp(matrix_dimensionality * matrix_dimensionality);

    input(matrix_dimensionality, number_of_edges, &adj, std::cin);
    make_identity_matrix(matrix_dimensionality, &res);
    binpow(matrix_dimensionality, path_length, &adj, &res, &tmp);

    for (int64_t j = 0; j < matrix_dimensionality; j++) {
        answer += res[j];
    }
    answer %= MOD;
    std::cout << answer;

    return 0;
}
