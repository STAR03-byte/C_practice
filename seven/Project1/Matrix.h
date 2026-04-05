#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
using namespace std;

class Matrix {
private:
    int rows, cols;
    vector<vector<double>> data;

public:
    Matrix(int r = 1, int c = 1) : rows(r), cols(c), data(r, vector<double>(c, 0)) {}

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void input() {
        cout << "请输入矩阵的行数: ";
        cin >> rows;
        cout << "请输入矩阵的列数: ";
        cin >> cols;

        if (rows <= 0 || cols <= 0) {
            throw runtime_error("矩阵维度必须是正数！");
        }

        data.assign(rows, vector<double>(cols));

        cout << "请输入矩阵元素 (" << rows << "行 " << cols << "列):" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "元素[" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
        }
    }

    void readFromFile(const string& filename) {
        ifstream fin(filename);
        if (!fin) throw runtime_error("文件无法打开！");
        fin >> rows >> cols;
        data.assign(rows, vector<double>(cols));
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                fin >> data[i][j];
        fin.close();
    }


    void randomGenerate(int r, int c, int minVal = 0, int maxVal = 9) {
        rows = r;
        cols = c;
        data.assign(rows, vector<double>(cols)); 
        srand(static_cast<unsigned int>(time(0)));
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                data[i][j] = minVal + rand() % (maxVal - minVal + 1);
    }

    void display() const {
        for (const auto& row : data) {
            for (double val : row)
                cout << setw(10) << fixed << setprecision(2) << val;
            cout << endl;
        }
    }

    Matrix add(const Matrix& m) const {
        if (rows != m.rows || cols != m.cols)
            throw runtime_error("矩阵维度不一致！");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + m.data[i][j];
        return result;
    }

    Matrix subtract(const Matrix& m) const {
        if (rows != m.rows || cols != m.cols)
            throw runtime_error("矩阵维度不一致！");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] - m.data[i][j];
        return result;
    }

    Matrix multiply(const Matrix& m) const {
        if (cols != m.rows)
            throw runtime_error("矩阵不可乘！");
        Matrix result(rows, m.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < m.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * m.data[k][j];
        return result;
    }

    double determinant() const {
        if (rows != cols)
            throw runtime_error("非方阵无法求行列式！");
        return calcDet(data);
    }

    double determinantAbs() const {
        return fabs(determinant());
    }

    Matrix inverse() const {
        if (rows != cols)
            throw runtime_error("非方阵无法求逆！");
        double det = this->determinant();
        if (fabs(det) < 1e-9)
            throw runtime_error("矩阵不可逆 (行列式为0)！");

        int n = rows;
        Matrix res(n, n);
        vector<vector<double>> temp = data;
        for (int i = 0; i < n; ++i)
            res.data[i][i] = 1.0;

        for (int i = 0; i < n; ++i) {
            int pivot_row = i;
            for (int k = i + 1; k < n; ++k) {
                if (fabs(temp[k][i]) > fabs(temp[pivot_row][i])) {
                    pivot_row = k;
                }
            }
            swap(temp[i], temp[pivot_row]);
            swap(res.data[i], res.data[pivot_row]);

            double pivot = temp[i][i];
            for (int j = 0; j < n; ++j) {
                temp[i][j] /= pivot;
                res.data[i][j] /= pivot;
            }
            for (int k = 0; k < n; ++k) {
                if (k == i) continue;
                double factor = temp[k][i];
                for (int j = 0; j < n; ++j) {
                    temp[k][j] -= factor * temp[i][j];
                    res.data[k][j] -= factor * res.data[i][j];
                }
            }
        }
        return res;
    }

private:
    double calcDet(const vector<vector<double>>& mat) const {
        size_t n = mat.size();
        vector<vector<double>> temp = mat;
        double det = 1.0;

        for (size_t i = 0; i < n; i++) {
            size_t pivot = i;
            for (size_t j = i + 1; j < n; j++) {
                if (abs(temp[j][i]) > abs(temp[pivot][i])) {
                    pivot = j;
                }
            }
            if (pivot != i) {
                swap(temp[i], temp[pivot]);
                det *= -1;
            }
            if (abs(temp[i][i]) < 1e-9) {
                return 0.0;
            }
            det *= temp[i][i];
            for (size_t j = i + 1; j < n; j++) {
                for (size_t k = i + 1; k < n; k++) {
                    temp[j][k] -= temp[i][k] * temp[j][i] / temp[i][i];
                }
            }
        }
        return det;
    }
};