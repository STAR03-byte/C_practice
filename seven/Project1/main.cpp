#include "Matrix.h" 
#include <iostream>

// 辅助函数：创建一个用于测试文件读取功能的文本文件
void createTestFile() {
    std::ofstream outFile("test_matrix.txt");
    if (outFile.is_open()) {
        // 写入一个 3x4 的矩阵
        outFile << 3 << " " << 4 << std::endl;
        outFile << 10 << " " << 20 << " " << 30 << " " << 40 << std::endl;
        outFile << 50 << " " << 60 << " " << 70 << " " << 80 << std::endl;
        outFile << 90 << " " << 11 << " " << 22 << " " << 33 << std::endl;
        outFile.close();
        std::cout << "(已自动创建 'test_matrix.txt' 文件用于测试)\n";
    }
    else {
        std::cerr << "无法创建测试文件！\n";
    }
}


int main() {
    try {
        // --- 1. 测试键盘输入功能 ---
        std::cout << "--- 1. 测试键盘输入 ---\n";
        Matrix A;
        A.input();
        std::cout << "\n您输入的矩阵 A 是:\n";
        A.display();
        std::cout << "\n----------------------------------------\n";

        // --- 2. 测试随机生成功能 ---
        std::cout << "\n--- 2. 测试随机矩阵生成 ---\n";
        Matrix B;
        B.randomGenerate(3, 3, 1, 99); // 生成一个 3x3 的，元素在 1-99 之间的矩阵
        std::cout << "随机生成的 3x3 矩阵 B:\n";
        B.display();
        std::cout << "\n----------------------------------------\n";

        // --- 3. 测试文件读取功能 ---
        std::cout << "\n--- 3. 测试从文件读取 ---\n";
        createTestFile();
        Matrix C;
        C.readFromFile("test_matrix.txt");
        std::cout << "从 'test_matrix.txt' 读取的矩阵 C:\n";
        C.display();
        std::cout << "\n----------------------------------------\n";

        // --- 4. 测试加法和减法 ---
        std::cout << "\n--- 4. 测试加法和减法 ---\n";
        Matrix M1, M2;
        M1.randomGenerate(2, 3, 1, 10);
        M2.randomGenerate(2, 3, 1, 10);
        std::cout << "矩阵 M1:\n";
        M1.display();
        std::cout << "\n矩阵 M2:\n";
        M2.display();

        Matrix M_add = M1.add(M2);
        std::cout << "\n结果: M1 + M2 =\n";
        M_add.display();

        Matrix M_sub = M1.subtract(M2);
        std::cout << "\n结果: M1 - M2 =\n";
        M_sub.display();
        std::cout << "\n----------------------------------------\n";

        // --- 5. 测试乘法 ---
        std::cout << "\n--- 5. 测试乘法 ---\n";
        Matrix M3, M4;
        M3.randomGenerate(2, 3, 1, 5); // 2x3 矩阵
        M4.randomGenerate(3, 2, 1, 5); // 3x2 矩阵
        std::cout << "矩阵 M3 (2x3):\n";
        M3.display();
        std::cout << "\n矩阵 M4 (3x2):\n";
        M4.display();

        Matrix M_mul = M3.multiply(M4);
        std::cout << "\n结果: M3 * M4 =\n";
        M_mul.display();
        std::cout << "\n----------------------------------------\n";

        // --- 6. 测试行列式和逆矩阵 ---
        std::cout << "\n--- 6. 测试行列式与逆矩阵 ---\n";
        std::cout << "请输入一个方阵 (例如 3x3) 来进行测试:\n";
        Matrix G;
        G.input();
        std::cout << "\n您输入的方阵 G:\n";
        G.display();

        if (G.getRows() != G.getCols()) {
            std::cout << "\n这是一个非方阵，跳过行列式和求逆测试。\n";
        }
        else {
            double detAbs = G.determinantAbs(); // 
            std::cout << "\n行列式的模值为: " << std::fixed << std::setprecision(2) << detAbs << std::endl; // 

            std::cout << "\n矩阵 G 的逆矩阵:\n";
            Matrix G_inv = G.inverse(); // 
            G_inv.display();
        }
        std::cout << "\n----------------------------------------\n";

        // --- 7. 测试异常处理 ---
        std::cout << "\n--- 7. 测试异常处理 ---\n";
        std::cout << "现在，我们将故意尝试一个非法操作 (将 M1(2x3) 与 M2(3x2) 相加)...\n";
        try {
            // M1 是 2x3, M4 是 3x2, 维度不匹配
            M1.add(M4);
        }
        catch (const std::runtime_error& e) {
            std::cout << "成功捕获到预期的错误: " << e.what() << std::endl;
        }

    }
    catch (const std::runtime_error& e) {
        // 捕获所有未被单独处理的错误
        std::cerr << "\n!!! 程序运行中发生严重错误: " << e.what() << std::endl;
    }

    std::cout << "\n所有测试已执行完毕。\n";
    return 0;
    system("pause");
}