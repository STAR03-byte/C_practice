#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Matrix {
private:
    std::vector<std::vector<double>> data;
    int rows, cols;

public:
    Matrix(int r = 0, int c = 0) : rows(r), cols(c) {
        data.resize(r, std::vector<double>(c, 0.0));
    }

    void input() {
        std::cout << "请输入 " << rows << "x" << cols << " 矩阵数据：\n";
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                std::cin >> data[i][j];
    }

    bool loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) return false;
        file >> rows >> cols;
        data.resize(rows, std::vector<double>(cols));
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                file >> data[i][j];
        return true;
    }

    void generateRandom(int min = 0, int max = 9) {
        srand((unsigned)time(nullptr));
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                data[i][j] = min + rand() % (max - min + 1);
    }

    void display(const std::string& name = "") const {
        if (!name.empty()) std::cout << "矩阵 " << name << ":\n";
        for (const auto& row : data) {
            for (double val : row)
                std::cout << std::setw(8) << val << " ";
            std::cout << "\n";
        }
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw std::runtime_error("加法维度不匹配");
        Matrix res(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                res.data[i][j] = data[i][j] + other.data[i][j];
        return res;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw std::runtime_error("减法维度不匹配");
        Matrix res(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                res.data[i][j] = data[i][j] - other.data[i][j];
        return res;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows)
            throw std::runtime_error("乘法维度不匹配");
        Matrix res(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    res.data[i][j] += data[i][k] * other.data[k][j];
        return res;
    }

    double determinant() const {
        if (rows != cols) throw std::runtime_error("非方阵无行列式");
        Matrix temp = *this;
        double det = 1;
        for (int i = 0; i < rows; ++i) {
            int pivot = i;
            while (pivot < rows && std::fabs(temp.data[pivot][i]) < 1e-9) ++pivot;
            if (pivot == rows) return 0;
            if (pivot != i) {
                std::swap(temp.data[i], temp.data[pivot]);
                det *= -1;
            }
            det *= temp.data[i][i];
            for (int j = i + 1; j < rows; ++j) {
                double factor = temp.data[j][i] / temp.data[i][i];
                for (int k = i; k < cols; ++k)
                    temp.data[j][k] -= factor * temp.data[i][k];
            }
        }
        return std::fabs(det);
    }

    Matrix inverse() const {
        if (rows != cols) throw std::runtime_error("非方阵不可逆");
        int n = rows;
        Matrix A = *this;
        Matrix I(n, n);
        for (int i = 0; i < n; ++i)
            I.data[i][i] = 1.0;

        for (int i = 0; i < n; ++i) {
            double pivot = A.data[i][i];
            if (std::fabs(pivot) < 1e-9)
                throw std::runtime_error("矩阵不可逆");

            for (int j = 0; j < n; ++j) {
                A.data[i][j] /= pivot;
                I.data[i][j] /= pivot;
            }

            for (int k = 0; k < n; ++k) {
                if (k == i) continue;
                double factor = A.data[k][i];
                for (int j = 0; j < n; ++j) {
                    A.data[k][j] -= factor * A.data[i][j];
                    I.data[k][j] -= factor * I.data[i][j];
                }
            }
        }
        return I;
    }
};

int main() {
    try {
        std::cout << "========= 矩阵运算测试 =========\n";

        // 随机生成矩阵 A（3x3）
        Matrix A(3, 3);
        A.generateRandom();
        A.display("A (随机生成)");

        // 从文件读取矩阵 B（或输入）
        Matrix B;
        if (B.loadFromFile("matrix.txt")) {
            B.display("B (来自文件)");
        }
        else {
            std::cout << "未找到文件，请输入矩阵 B（3x3）:\n";
            B = Matrix(3, 3);
            B.input();
        }

        // 测试加法
        Matrix C = A + B;
        C.display("A + B");

        // 测试减法
        Matrix D = A - B;
        D.display("A - B");

        // 测试乘法
        Matrix E = A * B;
        E.display("A * B");

        // 测试行列式
        std::cout << "det(A) 的模值 = " << A.determinant() << "\n";

        // 测试逆矩阵
        Matrix Ainv = A.inverse();
        Ainv.display("A 的逆矩阵");

    }
    catch (const std::exception& e) {
        std::cerr << "\n错误: " << e.what() << std::endl;
    }
    return 0;
}