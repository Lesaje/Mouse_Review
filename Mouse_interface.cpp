#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

const int64_t MOD = 1000000007;

/*
Matrix multiplication with integer values not exceeding 1 000 000 007
*/
void matrix_multiplication(const std::vector<int64_t>& first_matrix,
    const std::vector<int64_t>& second_matrix,
    std::vector<int64_t>* result_matrix)
    
    
std::vector<int64_t> make_identity_matrix(const int64_t matrix_size)
    

/*
Raises adjacency_matrix to a power
*/
std::vector<int64_t> binpow(int64_t power,
    const std::vector<int64_t>& adjacency_matrix)
    

std::vector<int64_t> make_adjacency_matrix(const int64_t number_of_edges,
    const int64_t matrix_size, std::istream& in)
    

std::tuple<int64_t, int64_t, int64_t> read(std::istream& in)

    
int64_t get_answer(const std::vector<int64_t>& result_matrix)

    
void solve_task(std::istream& in)

    
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve_task(std::cin);

    return 0;
}
