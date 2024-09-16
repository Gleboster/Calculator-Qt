#ifndef CALCULATIONRESOLVER_H
#define CALCULATIONRESOLVER_H

#include <QString>

#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <fstream>
#include <string>


class CalculationParser{
    typedef double(*func_type)(std::stack<double>&);
    typedef std::map<std::string, func_type> Ops;

    enum tokentype {
        //Неопр, константа, (, ), операция
        unknow, num, op_br, cl_br, op
    };

    struct token {
        std::string name;
        tokentype type;

        token(std::string str, tokentype typ) {
            name = str;
            type = typ;
        }
        token() {}
    };

    const std::string DELIMETERS = " ()+/*-%";

    std::set<char> DelimSet;

    typedef std::vector<token> tokens;

    std::map <std::string, int> prior;
    Ops ops;

public:
    double Calculate(QString calculationLine);

private:
    void CreateSetOfDelimiters();

    void CreateOps();

    void CreatePrior();

    void CreatePostfixFromTokens(tokens& texpr, tokens& pexpr);

    //Разбиваем выражение на токены
    void CreateTokensFromExpression(std::string& expr, tokens& texpr);
    //Проверка, является ли символ разделителем
    bool IsDelimiter(char sym);

    //Считаем результат выражения
    double ResultExpr(tokens& pexpr);

   static double op_plus(std::stack <double>& s);
   static double op_minus(std::stack <double>& s);
   static double op_mul(std::stack <double>& s);
   static double op_div(std::stack <double>& s);
   static double op_proccent_two(std::stack<double> &s);
   static double op_proccent_once(std::stack<double> &s);
   static double op_opposite(std::stack <double>& s);
};

#endif // CALCULATIONRESOLVER_H
