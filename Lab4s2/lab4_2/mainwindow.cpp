#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

using namespace std;

std::string programTxt = "";
mstring results;

mstring tmp;

std::vector<const char*> var_data;
std::vector<const char*> var_type;
std::vector<const char*> types_set;
std::vector<int> types_cnt;

std::vector<const char*> classes_names;
std::vector<pair<const char*, const char*>> objects_names;
std::vector<const char*> mass_names;

std::vector<const char*> functions_names;
std::vector<const char*> functions_data;
std::vector<int> functions_positions;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->show();
    ui->comboBox->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonFile_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"Open","D:\\Desktop","Cpp file (*.cpp)");
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this,"Ошибка","Не удалось открыть файл");
        return;
    }
    programTxt = file.readAll().toStdString();
    file.close();
    ui->textEdit->setText(QString::fromStdString(programTxt));
    on_comboBox_currentIndexChanged(ui->comboBox->currentIndex());
}

void MainWindow::on_pushButtonLine_clicked()
{
    qDebug()<<1;

    programTxt.clear();
    programTxt = ui->textEdit->toPlainText().toStdString().c_str();

    if(!programTxt.length()){
        QMessageBox::information(this,"Ошибка","Проверьте введенный текст");
        ui->comboBox->setEnabled(false);
        return;
    }
    ui->comboBox->setEnabled(true);
    on_comboBox_currentIndexChanged(ui->comboBox->currentIndex());
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->textBrowser->clear();
    switch (index)
    {
    case 0:
        getVarsData();
        showVarsData();
        break;
    case 1:
        showObjsAndArsData(getObjsAndArsData());
        break;
    case 2:
        qDebug()<<1;
        getFunctionsData();
        showFunctionsData();
        break;
    case 3:
        coordinatesOfChanges();
        return;
        break;
    case 4:
        localsCoordinates();
        break;
    case 5:
        overloadsCoordinates();
        break;
    case 6:
        qDebug()<<1;
        depthBranch();
        break;
    case 7:
        logicalErrors();
        break;
    default:
        break;
    }
    qDebug()<<QString::fromStdString(results.toCsStdString());
    ui->textBrowser->setText(QString::fromStdString(results.toCsStdString()));

}

void MainWindow::getVarsData()
{
    var_data.clear();
    var_type.clear();

    std::regex regular("(([\\w]+)\\*?\\ \\*?)((\\w+)[\\s\\w=\\[\\],\\(\\)]*);");
    std::smatch result;
    std::string tmp = programTxt;
    mstring a;

    while(std::regex_search(tmp, result, regular))
    {
        if(result[1]=="delete "||result[1]=="return "||result[1]=="using ")
        {
            tmp = result.suffix();
            continue;
        }
        qDebug()<< bool(result[1]=="delete ") <<tmp.length();
        char* a = new char[mstring::len(result[1].str().c_str())];
        char* b = new char[mstring::len(result[3].str().c_str())];
        memcpy(a,result[1].str().c_str(),mstring::len(result[1].str().c_str()));
        var_type.push_back(a);
        memcpy(b,result[3].str().c_str(),mstring::len(result[3].str().c_str()));
        var_data.push_back(b);
        qDebug()<<result[0].str().c_str() <<"fffff"<<  result[1].str().c_str() <<"fffff"<< result[2].str().c_str() <<"fffff"<< result [3].str().c_str() <<"fffff"<< result [4].str().c_str() <<"fffff"<< result[5].str().c_str();
        tmp = result.suffix();
        qDebug()<<"\n"<<var_type.size();
    }
}

void MainWindow::showVarsData()
{

    qDebug()<<"showVars";
    results = "";
    types_set.clear();
    types_cnt.clear();
    bool is = true;
    for(size_t i = 0; i < var_type.size();i++)
    {

        qDebug()<<var_type[i] << " " << var_data[i] << "asdasdasdasdasda\n\n\n\n\n\n";
        results+=var_type[i];
        results+=var_data[i];
        results+="\n";
        for(size_t g = 0; g<types_set.size();g++)
        {
            if(string(var_type[i])==string(types_set[g]))
            {
                types_cnt[g]+= mstring::count(var_data[i],',')+1;
                is = false;
                break;
            }
        }
        if(is)
        {
            types_set.push_back(var_type[i]);
            int a = mstring::count(var_data[i],',')+1;
            types_cnt.push_back(a);
        }
        is = true;
    }
    results+="\n";
    results+="Количество:";
    qDebug()<<types_set.size();
    for(size_t i = 0; i<types_set.size();i++)
    {
        results+="\n";
        results+=types_set[i];
        results+=QString::number(types_cnt[i]).toStdString().c_str();
    }
}

int* MainWindow::getObjsAndArsData()
{
    classes_names.clear();
    mass_names.clear();
    objects_names.clear();

    std::string tmp = programTxt;
    std::regex classes_regex("(class|struct)\\s*(\\w+)\\s*\\{");
    std::smatch result;
    mstring a;
    while(std::regex_search(tmp, result, classes_regex))
    {
        char* a = new char[mstring::len(result[2].str().c_str())];
        memcpy(a,result[2].str().c_str(),mstring::len(result[2].str().c_str()));
        classes_names.push_back(result[2].str().c_str());
        tmp = result.suffix().str().c_str();
    }

    tmp = programTxt;

    size_t class_count = 0;

    size_t size = classes_names.size();
    for(size_t i = 0; i < size; ++i)
    {
        int pos = tmp.find(classes_names[i]);
        std::stack<char> brackets_stack;
        brackets_stack.push('{');
        size_t first_bracket = tmp.find('{', pos);
        size_t last_bracket, counter = first_bracket + 1;
        while(!brackets_stack.empty() && counter < tmp.length())
        {
            if(tmp[counter] == '{')
            {
                brackets_stack.push('{');
            }
            if(tmp[counter] == '}')
            {
                brackets_stack.pop();
            }
            ++counter;
        }
        last_bracket = counter - 1;

        if(counter != tmp.length())
        {
            tmp.erase(first_bracket, last_bracket - first_bracket + 1);
        }

    }

    size_t pos;
    for(size_t i = 0; i < classes_names.size(); ++i)
    {
        pos = tmp.find(classes_names[i]);
        while(pos != std::string::npos)
        {
            if(pos > tmp.find("int main()")) ++class_count;
            tmp.erase(pos, mstring::len(classes_names[i]));
            pos = tmp.find(classes_names[i]);
        }
    }

    std::string init_object_regex_str("\\s*[\\*]*\\s*([\\w]+)\\s*(=\\s*[\\w+ ]*|\\([\\w]+\\))?(\\{[\\w ,]+\\})?;");
    for(size_t i = 0; i < classes_names.size(); ++i)
    {
        tmp = programTxt;
        std::regex init_obj_regex("\\s*" + std::string(classes_names[i]) + init_object_regex_str);
        while(std::regex_search(tmp, result, init_obj_regex))
        {
            //qDebug()<<result[0];
            char* a = new char[mstring::len(result[1].str().c_str())];
            memcpy(a,result[1].str().c_str(),mstring::len(result[1].str().c_str()));
            objects_names.push_back(std::make_pair(a, classes_names[i]));
            tmp = result.suffix().str().c_str();
        }
    }

    std::regex arrays_decl_regex("\\s*\\w+\\s+(\\w+)\\s*((\\[[\\w]*\\])+)\\s*=?\\s*(\\{[^;]*\\})?\\s*;");

    tmp = programTxt;

    while (std::regex_search(tmp, result, arrays_decl_regex))
    {
        char* a = new char[mstring::len(result[1].str().c_str())];
        memcpy(a,result[1].str().c_str(),mstring::len(result[1].str().c_str()));
        mass_names.push_back(a);
        tmp = result.suffix().str().c_str();
    }
    size_t array_count = 0;

    tmp = programTxt;

    for(size_t i = 0; i < mass_names.size(); ++i)
    {
        if(tmp.find(mass_names[i]) != -1)
        {
            ++array_count;
            tmp.erase(tmp.find(mass_names[i]), mstring::len(mass_names[i]));
        }
    }
    int* nums = new int[2];
    nums[0] = class_count;
    nums[1] = array_count;
    return nums;
}

void MainWindow::showObjsAndArsData(int* nums)
{
    results = "";

    results += "Объекты : ";
    results+= QString::number(nums[0]).toStdString().c_str();
    results+= "\n";
    results+= "Массивы : ";
    results+= QString::number(nums[1]).toStdString().c_str();
    results+= "\n";

    delete[] nums;
}

void MainWindow::getFunctionsData()
{

    qDebug()<<"start";
    std::regex func_reg("\\s*((\\w+)\\*?\\ \\*?([\\w\\:]+)\\(([\\w\\,\\ ]*)\\))[\\s\\{\\;]*");

    functions_data.clear();
    functions_names.clear();
    functions_positions.clear();

    std::smatch result;
    std::string tmp = programTxt;


    while(std::regex_search(tmp, result, func_reg))
    {
        if (result[2].str()=="new"|| result[2].str() =="QFile")
        {
            tmp = result.suffix();
            continue;
        }

        char* a = new char[mstring::len(result[1].str().c_str())];
        char* c = new char[mstring::len(result[3].str().c_str())];
        std::memmove(a,result[1].str().c_str(),mstring::len(result[1].str().c_str()));
        std::memmove(c,result[3].str().c_str(),mstring::len(result[3].str().c_str()));
        qDebug()<<c;
        functions_data.push_back(a);
        functions_names.push_back(c);
        int b = tmp.find(result.str().c_str());
        functions_positions.push_back(b);
        tmp = result.suffix();
    }
    qDebug()<<2;
}

void MainWindow::showFunctionsData()
{
    qDebug()<<1;
    results = "";
    results = "Прототипы функций :\n";
    for(size_t i = 0; i<functions_data.size();i++)
    {
        qDebug()<<1;
        results+= functions_data[i];
        results+= "\n";
    }
}

void MainWindow::coordinatesOfChanges()
{
    std::regex reg("[\\};]\\s*(([\\*]*\\s*)?\\w+(\\[\\w+\\])?\\s*?(([+|-|^|*|\\/|&|\\|]?=)|\\++|--))");

    std::smatch res;

    std::string tmp = programTxt;

    while(std::regex_search(tmp, res, reg))
    {
        tmp = res.suffix().str().c_str();

        ui->textBrowser->append(QString::number(ui->textEdit->toPlainText().mid(0, (ui->textEdit->toPlainText().size() - tmp.length())).count('\n') + 1));
    }
}

void MainWindow::localsCoordinates()
{
    results = "";

    getObjsAndArsData();
    QStringList str = QString::fromStdString(programTxt).split('\n');
    std::vector<string> rows;
    for(int i = 0; i < str.size(); ++i)
    {
        rows.push_back(str[i].toStdString());
    }
    int balance = 0;
    std::vector<int> position;
    std::regex variables_init_regex("(([A-Za-z0-9\\_\\:]+)\\*?\\ \\*?)((\\w+)[\\s\\w=\\[\\],\\(\\)]*);");
    for(size_t i = 0; i < rows.size(); ++i){
        for(size_t j = 0; j < rows[i].size(); ++j)
        {
            if(rows[i][j] == '{')
            {
                ++balance;
            }
            if(rows[i][j] == '}')
            {
                --balance;
            }
        }
        if(std::regex_search(rows[i], variables_init_regex))
        {
            if(balance != 0)
            {
                position.push_back(i);
            }
        }
    }
    std::string class_init_regex_str("\\s*(=\\s*[\\w+ ]*|\\([\\w]+\\))?(\\{[\\w ,]+\\})?;");
    for(size_t i = 0; i < rows.size(); ++i){
        for(size_t j = 0; j < rows[i].size(); ++j)
        {
            if(rows[i][j] == '{')
            {
                ++balance;
            }
            if(rows[i][j] == '}')
            {
                --balance;
            }
        }
        if(balance != 0){
            for(size_t k = 0; k < objects_names.size(); ++k)
            {
                std::regex obj_regex(string(objects_names[k].first) + "\\s*" + objects_names[k].second + class_init_regex_str);
                if(std::regex_search(rows[i], obj_regex)){
                    position.push_back(i);
                }
            }
        }

    }

    results = "Количество локальных переменных : ";
    results += QString::number(position.size()).toStdString().c_str();
    results += "\n";
    results += "Строки, в кототых они содержатся : \n";
    for(size_t i = 0; i < position.size(); ++i)
    {
        results += QString::number(position[i]).toStdString().c_str();
        results += "\n";
    }
}

void MainWindow::overloadsCoordinates()
{
    results = "";

    getFunctionsData();
    QStringList str = QString::fromStdString(programTxt).split('\n');
    std::vector<std::string> rows;
    for(int i = 0; i < str.size(); ++i)
    {
        rows.push_back(str[i].toStdString());
    }

    qDebug()<<"over";
    int count_of_overload_funcs = 0;
    std::vector<int> positions;
    std::vector<bool> visited(functions_names.size(), false);
    for(size_t i = 0; i < functions_names.size(); ++i)
    {
        for(size_t j = i + 1; j < functions_names.size(); ++j)
        {
            if(string(functions_names[i]) == string(functions_names[j]) && !visited[i] && !visited[j])
            {
                count_of_overload_funcs += 2;
                visited[i] = visited[j] = true;
                positions.push_back(functions_positions[i]);
                positions.push_back(functions_positions[j]);
            }
        }
    }
    results += "Позиции:\n";
    for(size_t i = 0; i < positions.size(); ++i)
    {
        results += QString::number(positions[i]).toStdString().c_str();
        results += "\n";
    }
    results += "Количество перегруженных функций :";
    results+= QString::number(count_of_overload_funcs).toStdString().c_str();
    results+= "\n";
}

void MainWindow::depthBranch()
{
    results = "";

    string tmp = programTxt;
    std::vector<int> depth;
    int amount = 0;

    std::stack<char> pos;
    for(size_t i = 0; i < tmp.length() - 5; ++i)
    {
        if(tmp[i] != 'e' && tmp[i + 1] != 'l' && tmp[i + 2] != 's' && tmp[i + 3] != 'e'
                && tmp[i + 4] == 'i' && tmp[i + 5] == 'f')
        {
            ++amount;
            pos.push('{');
        }
        if(tmp[i] == 'e' && tmp[i + 1] == 'l' && tmp[i + 2] == 's' && tmp[i + 3] == 'e'
                && tmp[i + 4] == 'i' && tmp[i + 5] == 'f')
        {
            pos.push('{');
        }
        if(!pos.empty() && tmp[i] == '}')
        {
            depth.push_back(amount);
            --amount;
            pos.pop();
        }
    }

    for(size_t i = 0; i < depth.size() - depth.size()/3; ++i)
    {
        results += QString::number(depth[i]).toStdString().c_str();
        results += "\n";
    }
}

void MainWindow::logicalErrors()
{
    results = "";

    QStringList list = QString::fromStdString(programTxt).split('\n');
    std::vector<std::string> code_Vector;
    for(int i = 0; i < list.size(); ++i)
    {
        code_Vector.push_back(list[i].toStdString());
    }

    std::regex regular_while_false("\\s*while\\(\\s*false\\s*\\)");
    for(size_t i = 0; i < code_Vector.size(); ++i)
    {
        if(std::regex_search(code_Vector[i], regular_while_false))
        {
            results += "while(false) {...} в ";
            results+= QString::number(i).toStdString().c_str();
            results+= "-ой строке\n";
        }
    }

    std::regex regular_while_true("\\s*while\\(\\s*true\\s*\\)\\s*?\\{\\s*\\}");
    for(size_t i = 0; i < code_Vector.size(); ++i)
    {
        if(std::regex_search(code_Vector[i], regular_while_true))
        {
            results += "while(true) {*пустота*} в ";
            results+= QString::number(i).toStdString().c_str();
            results+= "-ой строке\n";
        }
    }

    std::regex regular_if_true("if\\(\\s*true\\s*\\)");
    for(size_t i = 0; i < code_Vector.size(); ++i)
    {
        if(std::regex_search(code_Vector[i], regular_if_true))
        {
            results += "if(true) {...} в ";
            results+= QString::number(i).toStdString().c_str();
            results += "-ой строке\n";
        }
    }

    std::regex regular_if_false("if\\(\\s*false\\s*\\)");
    for(size_t i = 0; i < code_Vector.size(); ++i)
    {
        if(std::regex_search(code_Vector[i], regular_if_false))
        {
           results += "if(false) {...} в ";
           results+= QString::number(i).toStdString().c_str();
           results+= "-ой строке\n";
        }
    }

    std::regex regular_empty_if("if\\(\\s*\\)");
    for(size_t i = 0; i < code_Vector.size(); ++i)
    {
        if(std::regex_search(code_Vector[i], regular_empty_if))
        {
            results += "if() {...} в ";
            results+= QString::number(i).toStdString().c_str();
            results+= "-ой строке\n";
        }
    }
}

