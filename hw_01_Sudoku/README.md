实现两个类：Grid类（二维方阵容器）和Sudoku类（数独，负责状态和规则），其中Grid类为Sudoku类的父类，这两个类满足以下要求：

1. 语言要求：
    - 静态类型语言，这里指定为CPP。
    - 动态类型语言，这里指定为Python。

2. 功能要求：
    - 业务代码：实现Grid和Sudoku的基本逻辑。
    - 测试代码：编写测试Sudoku逻辑的代码。
    - 文档：提供必要的文档说明。

3. 设计要求：
    - 抽象数据类型（ADT）：定义Grid的数据结构。
    - 继承：如果适用，使用继承Grid类来设计Sudoku类结构。

4. Grid属性：
    - grid：将输入的字符串存成2维方阵
    - BOX_SIZE：3x3格子
    - GRID_SIZE：9宫格
    - getRow(row)
    - getColumn(col)
    - getBox(row, col)
    - check() 检测grid是否合法有效
    - checkStr(string s, int sudokuSize): 检查输入的字符串（正则表达式）和sudoku的边界长度是否合法（为完全平方数）
    - parse(string s, int sudokuSize)：解析输入的字符串，初始化对象
4. Sudoku属性：
    - getInference()：得到所有单元格的所有候选值
    - getCandidates(row, col)：得到当前单元格的所有候选值
    - getSameBox(row, col)：得到当前3x3格子中的值


5. 业务功能：
   - 输入：解析字符串输入，得到Sudoku实例。
   - 推理棋盘：得到各单元格的候选值。
   - 其他合理功能：根据需求实现其他功能。

6. 测试用例：
   - 提供的测试字符串：`017903600000080000900000507072010430000402070064370250701000065000030000005601720`
   - 更多测试用例可以从 [Sudoku维基](https://www.sudokuwiki.org/) 获取。

7. 实现细节：
   - 实现一个Sudoku类，包含初始化、显示、验证和解决Sudoku的方法。
   - 使用静态类型语言实现时，需要考虑类型安全和内存管理。
   - 使用动态类型语言实现时，需要考虑代码的灵活性和简洁性。