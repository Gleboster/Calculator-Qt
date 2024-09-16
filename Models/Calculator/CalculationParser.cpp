#include "CalculationParser.h"

using namespace std;

double CalculationParser::Calculate(QString calculationLine)
{
    tokens texpr, pexpr;
    string expr = calculationLine.toStdString();

    CreateTokensFromExpression(expr, texpr);

    CreatePostfixFromTokens(texpr, pexpr);

    return ResultExpr(pexpr);
}

void CalculationParser::CreateSetOfDelimiters() {
    for (int i = 0; i < DELIMETERS.size(); i++)
        DelimSet.insert(DELIMETERS[i]);
    return;
}

bool CalculationParser::IsDelimiter(char sym) {
    return DelimSet.count(sym) > 0;
}

void CalculationParser::CreateTokensFromExpression(string &expr, CalculationParser::tokens &texpr) {
    CreateSetOfDelimiters();
    string ex = expr + " ";
    string name;

    //Получаем имя токена
    int i = 0;
    while (i < ex.size() - 1) {
        name = "";
        //Если текущий символ разделитель
        if (IsDelimiter(ex[i])) {
            if (ex[i] == ' ') { //Пробел просто перепрыгиваем
                i++;
                continue;
            }
            name = ex[i]; //Любой другой добавляем в имя токена
            i++;
        }

        else {
            while (!IsDelimiter(ex[i])) {
                /*Если не разделитель непример, переменная или имя массива,
                    Считываем его польностью */
                name += ex[i];
                i++;
            }
        }
        //Заносим получившийся токен в список токенов
        texpr.push_back(token(name, tokentype::unknow));
    }

    //Раздаем получившимся токенам типы
    for (int j = 0; j < texpr.size(); j++) {
        if (texpr[j].name[0] == '(') {
            texpr[j].type = op_br;
            continue;
        }
        if (texpr[j].name[0] == ')') {
            texpr[j].type = cl_br;
            continue;
        }
        if (isdigit(texpr[j].name[0])) {
            texpr[j].type = num;
            continue;
        }


        texpr[j].type = op;
    }

    //Проверяем минус и !, что это префиксные операции
    for (int j = 0; j < texpr.size(); j++) {
        if (texpr[j].name == "-" && (j == 0 || texpr[j - 1].type == op_br))
            texpr[j].name = "opposite";
        if (texpr[j].name == "%" && (j == texpr.size() - 1 || texpr[j + 1].type == cl_br || texpr[j + 1].type == op))
            texpr[j].name = "proccent";
    }

    return;
}

double CalculationParser::op_plus(stack<double> &s)
{
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return a + b;
}

double CalculationParser::op_minus(stack<double> &s) {
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return b - a;
}

double CalculationParser::op_mul(stack<double> &s) {
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return a * b;
}

double CalculationParser::op_div(stack<double> &s) {
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return b / a;
}

double CalculationParser::op_opposite(stack<double> &s) {
    double a;
    a = s.top();
    s.pop();
    return -a;
}

double CalculationParser::op_proccent_two(stack<double> &s) {
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return a / 100.0 * b;
}

double CalculationParser::op_proccent_once(stack<double> &s) {
    double a;
    a = s.top();
    s.pop();
    return a / 100.0;
}

void CalculationParser::CreateOps() {
    ops["+"] = op_plus;
    ops["-"] = op_minus;
    ops["*"] = op_mul;
    ops["/"] = op_div;
    ops["opposite"] = op_opposite;
    ops["%"] = op_proccent_two;
    ops["proccent"] = op_proccent_once;

    return;
}

void CalculationParser::CreatePrior() {
    prior["+"] = 10;
    prior["-"] = 10;
    prior["*"] = 20;
    prior["/"] = 20;
    prior["opposite"] = 10;
    prior["%"] = 20;
    prior["proccent"] = 20;
}

void CalculationParser::CreatePostfixFromTokens(CalculationParser::tokens &texpr, CalculationParser::tokens &pexpr) {
    //Задаем приоритеты операций
    CreatePrior();
    stack <token> TStack;

    //Ловим токены и работаем по алгоритму
    for (int i = 0; i < texpr.size(); i++) {
        switch (texpr[i].type) {
        case num:
            pexpr.push_back(texpr[i]);
            break;

        case op_br:
            TStack.push(texpr[i]);
            break;

        case cl_br:
            while (TStack.top().type != op_br) {
                pexpr.push_back(TStack.top());
                TStack.pop();
            }
            TStack.pop();
            break;

        case op:
            if (TStack.size()) {
                while (TStack.size() && ((TStack.top().type == op && prior[texpr[i].name] <= prior[TStack.top().name]))) {
                    pexpr.push_back(TStack.top());
                    TStack.pop();
                }
            }
            TStack.push(texpr[i]);
            break;
        }
    }

    while (TStack.size()) {
        pexpr.push_back(TStack.top());
        TStack.pop();
    }

    return;
}

double CalculationParser::ResultExpr(CalculationParser::tokens &pexpr) {
    CreateOps();
    stack <double> s;

    for (int i = 0; i < pexpr.size(); i++) {
        switch (pexpr[i].type) {
        case num: {
            s.push(atof(pexpr[i].name.c_str()));
        }
            break;

        case op: {
            Ops::iterator Oit;
            for (Oit = ops.begin(); Oit != ops.end(); Oit++) {
                if (Oit->first == pexpr[i].name) {
                    s.push(Oit->second(s));
                    break;
                }
            }
        }
            break;
        }
    }

    return s.top();
}
