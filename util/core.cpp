#include "core.h"
#include "screen/screenwelcome.h"
#include "screen/screenabout.h"
#include "screen/screendescription.h"
#include "screen/screenquestion.h"
#include "screen/screensummary.h"
#include "task/screentask1.h"
#include "task/screentask2.h"
#include "task/screentask3.h"
#include "task/screentask4.h"
#include "task/screentask5.h"
#include "task/screentask6.h"
#include "task/screentask7.h"
#include "task/screentask8.h"
#include "task/screentask9.h"
#include "task/screentask10.h"
#include "task/screentask11.h"
#include "task/screentask12.h"
#include <iostream>
#include <chrono>
#include <algorithm>

Core::Core() {}

void Core::init(WindowController *window) {
    this->window = window;
}

void Core::generate() {
    std::chrono::milliseconds msec = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    );
    generate(msec.count());
}

void Core::generate(unsigned int seed) {
    // clear questions
    for (Question* question : this->questions) {
        delete question;
    }
    this->questions.clear();
    // clear tasks
    for (Task* task : this->tasks) {
        delete task;
    }
    this->tasks.clear();
    // reset progress
    this->questionsOrder.clear();
    this->currentTask = 0;
    this->showedTask = 0;
    this->score = Static::scoreInitial;
    this->seed = seed;
    ScreenController::clean();
    ScreenController::srnd(seed);
    // ------------------------------
    // HERE GOES DEFINITIONS OF QUESTIONS
    // EVERY QUESTION SHOULD BE ADDED TO QUESTIONS VECTOR BELOW
    // SHOULD BE MINIMUM 10 QUESTIONS
    // ------------------------------
    questions.push_back(new Question("При каком условии группа G называется коммутативной, или абелевой?", std::vector<QString>{"Если групповая бинарная операция является коммутативной", "Если в группе существует нейтральный элемент", "Если для каждого ненулевого элемента существует обратный элемент", "Если нейтральный элемент является коммутативным"}));
    questions.push_back(new Question("Определение простого поля GF(p)", std::vector<QString>{"Это конечное поле порядка р (р – простое число), образованное полной системой вычетов по модулю числа р", "Это конечное поле порядка р (р – простое число), образованное полной системой вычетов по модулю числа р за исключением нулевого элемента", "Это конечное поле порядка р (р – простое число), образованное полной системой вычетов по модулю числа р за исключением единичного элемента", "Это конечное поле порядка р (р – простое число), образованное системой четных вычетов по модулю числа р"}));
    questions.push_back(new Question("В поле GF(11) найти мультипликативно обратный элемент для а=8", std::vector<QString>{"8^(-1) = 7", "8^(-1) = 8", "8^(-1) = 9", "8^(-1) = 6"}));
    questions.push_back(new Question("Какой полином требуется для задания расширенного поля Галуа?", std::vector<QString>{"Неприводимый", "Примитивный", "Минимальный", "Сопряженный"}));
    questions.push_back(new Question("Какой полином называется примитивным?", std::vector<QString>{"Это неприводимый полином, корнями которого являются примитивный элемент и его р-сопряженные элементы", "Это полином, корнями которого являются р-сопряженные элементы", "Это полином, который имеет 2t последовательных корней", "Это полином, корнями которого являются все примитивные элементы поля"}));
    questions.push_back(new Question("Какой полином называется минимальным полиномом для элемента а?", std::vector<QString>{"Это полином минимальной степени, корнями которого являются элемент а и его р-сопряженные элементы", "Это неприводимый полином, корни которого имеют минимальный период", "Это примитивный полином, корнями которого являются минимальные элементы", "Это полином минимальной степени, корнями которого являются элемент а и его последовательные степени"}));
    questions.push_back(new Question("Какие периоды могут иметь элементы конечного поля GF(3^4)?", std::vector<QString>{"80, 40, 20, 16, 10, 8, 4, 2, 1", "80, 40, 20, 10, 4, 2, 1", "80, 40, 20, 16, 10, 8, 4, 2, 1", "80, 40, 24, 20, 16, 10, 8, 4, 2, 1"}));
    questions.push_back(new Question("Какие периоды могут иметь элементы конечного поля GF(2^6)?", std::vector<QString>{"63, 21, 9, 7, 3, 1", "63, 42, 21, 9, 7, 3, 1", "63, 9, 7, 3, 1", "63, 7, 3, 1"}));
    questions.push_back(new Question("Какие периоды могут иметь элементы конечного поля GF(2^10), если 2^10 -1=1*3*11*31?", std::vector<QString>{"1023, 1, 3, 11, 31, 33, 93, 343", "1023, 511, 3, 11, 31, 33, 93, 343", "1023, 511, 255, 127, 63, 31", "1023, 1, 3, 11, 31, 33, 93, 99, 343"}));
    questions.push_back(new Question("Сколько элементов в поле GF(2^4) имеют период, равный 5?", std::vector<QString>{"4", "1", "2", "0"}));
    questions.push_back(new Question("Сколько элементов в поле GF(2^4) имеют период, равный 7?", std::vector<QString>{"0", "6", "7", "4"}));
    questions.push_back(new Question("Сколько элементов в поле GF(3^3) имеют период, равный 13?", std::vector<QString>{"12", "9", "13", "6"}));
    questions.push_back(new Question("В поле GF(2^6) период элемента а равен 21. Чему равен период элемента b=a^9?", std::vector<QString>{"7", "21", "63", "3"}));
    questions.push_back(new Question("В поле GF(2^4) определить р-сопряженные элементы для элемента а^3", std::vector<QString>{"а^3, а^6, а^12, а^9", "а^3, а^6, а^9, а^12, а^15", "а^3, а^4, а^5, а^6", "а^3, а^6, а^3, а^6"}));
    questions.push_back(new Question("В поле GF(2^3) чему равна функция следа для элемента а^0?", std::vector<QString>{"1", "0", "-1", "7"}));
    questions.push_back(new Question("Вычислить: (2х^10+4х^8+7х^7+8х^5+4х^4+7) modd(х^4, 3)", std::vector<QString>{"1", "x", "2", "х^3"}));
    questions.push_back(new Question("Чему равен порядок аддитивной группы простого поля GF(13)?", std::vector<QString>{"13", "11", "12", "10"}));
    questions.push_back(new Question("Чему равен порядок мультипликативной группы поля GF(13)?", std::vector<QString>{"12", "13", "11", "10"}));
    questions.push_back(new Question("Выражение для канонического степенного базиса в поле GF(p^s) (а-примитивный элемент)?", std::vector<QString>{"{a^0, a^1,..., a^(s–1)}", "{a^1, a^2,..., a^(s–1)}", "{a^1, a^2,..., a^(2s–1)}", "{a^0, a^1,..., a^(2s–1)}"}));
    questions.push_back(new Question("Для каких значений длин векторов n может быть выполнено прямое n-точечное ФМС–преобразование над конечным полем GF(2^4)?", std::vector<QString>{"3, 5, 15", "3, 6, 9, 12, 15", "3, 5, 10, 15", "5, 10, 15"}));
    questions.push_back(new Question("Даны матрица А размерности (7*9) и матрица В размерности (9*4). Сколько элементов будет в матрице С=А*В?", std::vector<QString>{"28", "63", "81", "36"}));
    questions.push_back(new Question("Определить третью строку (начиная с первой) матрицы Ф прямого ФМС-преобразования над полем GF(3^2)", std::vector<QString>{"а^0, а^2, а^4, а^6, а^0, а^2, а^4, а^6", "а^0, а^2, а^4, а^6, а^8, а^0, а^2, а^4", "а^0, а^3, а^6, а^1, а^4, а^7, а^2, а^5", "а^0, а^2, а^4, а^0, а^2, а^4, а^0, а^2"}));
    questions.push_back(new Question("Определение канонического базиса", std::vector<QString>{"Это базис, каждая компонента которого содержит всего одну единицу, а остальные – нули", "Это базис, каждая компонента которого содержит всего один нуль, а остальные – единицы", "Это базис, каждая компонента которого содержит нечетное число единиц", "Это базис, все компоненты которого линейно независимы"}));
    questions.push_back(new Question("Определение базиса S-мерного векторного пространства", std::vector<QString>{"Это набор из S линейно независимых векторов, с помощью линейных комбинаций которых можно получить все векторы этого пространства", "Это набор линейно независимых векторов, с помощью линейных комбинаций которых можно получить S векторов этого пространства", "Это набор из 2^S линейно независимых векторов, с помощью линейных комбинаций которых можно получить все векторы этого пространства", "Это набор из (2^S-1) линейно независимых векторов, с помощью линейных комбинаций которых можно получить все векторы этого пространства"}));
    questions.push_back(new Question("Какой базис называется нормальным примитивным базисом поля GF(2^S)?", std::vector<QString>{"Это базис вида {g, g^2, g^4,..., g^q}, где q = 2^(S–1), g - примитивный элемент поля GF(2^S), причем след tr s1 g = 1", "Это базис вида {g, g^2, g^3,..., g^q}, где q = 2^(S–1), g - примитивный элемент поля GF(2^S), причем след tr s1 g = 1", "Это базис вида {g, g^2, g^4,..., g^2q}, где q = 2^(S–1), g - примитивный элемент поля GF(2^S), причем след tr s1 g = 1", "Это базис вида {g, g^2, g^4,..., g^q}, где q = 2^(S–1), g - примитивный элемент поля GF(2^S), причем след tr s1 g = 0"}));
    questions.push_back(new Question("Какие элементы называются р-сопряженными элементами?", std::vector<QString>{"Элементы а^(р^i), где i=0,1,…", "Элементы а^(р^2i), где i=0,1,…", "Элементы а^(р^i-1), где i=1,2,…", "Элементы а^(р^2i), где i=1,2,…"}));
    // ------------------------------
    unsigned int size = questions.size() < 10 ? questions.size() : 10;
    while (true) {
        int current = rand() % questions.size();
        if (!(std::find(questionsOrder.begin(), questionsOrder.end(), current) != questionsOrder.end())) {
            questionsOrder.push_back(current);
        }
        if (questionsOrder.size() >= size) {
            break;
        }
    }
    // ------------------------------
    // HERE GOES DEFINITIONS OF TASKS
    // EVERY TASK SHOULD BE ADDED TO TASKS VECTOR BELOW
    // TASK'S VIEWS DEFINES AT Core::getView(int id)
    // ------------------------------
    // intro part
    tasks.push_back(new Task(0,  0,  "Практическое занятие"));
    /*tasks.push_back(new Task(1,  0,  "Практическое занятие"));
    tasks.push_back(new Task(2,  0,  "Практическое занятие"));
    // questions part
    tasks.push_back(new Task(3,  1,  "Входной контрольный опрос: вопрос 1",  false));
    tasks.push_back(new Task(4,  2,  "Входной контрольный опрос: вопрос 2",  false));
    tasks.push_back(new Task(5,  3,  "Входной контрольный опрос: вопрос 3",  false));
    tasks.push_back(new Task(6,  4,  "Входной контрольный опрос: вопрос 4",  false));
    tasks.push_back(new Task(7,  5,  "Входной контрольный опрос: вопрос 5",  false));
    tasks.push_back(new Task(8,  6,  "Входной контрольный опрос: вопрос 6",  false));
    tasks.push_back(new Task(9,  7,  "Входной контрольный опрос: вопрос 7",  false));
    tasks.push_back(new Task(10, 8,  "Входной контрольный опрос: вопрос 8",  false));
    tasks.push_back(new Task(11, 9,  "Входной контрольный опрос: вопрос 9",  false));
    tasks.push_back(new Task(12, 10, "Входной контрольный опрос: вопрос 10", false));*/
    // tasks part
    //tasks.push_back(new Task(13, 1,  "Вычисления над простым полем GF(p)"));
    //tasks.push_back(new Task(14, 2,  "Построение расширенного поля Галуа GF(2^3)"));
    //tasks.push_back(new Task(15, 3,  "Вычисления над расширенным полем GF(p^s) в каноническом базисе"));
    //tasks.push_back(new Task(16, 4,  "Вычисления над расширенным полем GF(p^s) в нормальном базисе"));
    //tasks.push_back(new Task(17, 5,  "Построение матрицы Ф прямого ФМС-преобразования"));
    //tasks.push_back(new Task(18, 6,  "Построение матрицы Ф(-1) обратного ФМС-преобразования"));
    //tasks.push_back(new Task(19, 7,  "Вычисление прямого ФМС-преобразования"));
    //tasks.push_back(new Task(20, 8,  "Вычисление обратного ФМС-преобразования"));
    //tasks.push_back(new Task(21, 9,  "Решение квадратного уравнения над полем GF(2^3)"));
    //tasks.push_back(new Task(22, 10, "Решение квадратного уравнения над полем GF(2^8)"));
    //tasks.push_back(new Task(23, 11, "Построение расширенного поля Галуа GF(3^2)"));
    tasks.push_back(new Task(24, 12, "Решение квадратного уравнения над полем GF(3^2)"));

    // summary part
    tasks.push_back(new Task(99, 0, "Результат", false));
    // ------------------------------
    window->setMaxProgress(tasks.size());
    window->setNextEnabled(true);
    window->setResetEnabled(true);
}

ScreenController* Core::getView(int id) {
    // ------------------------------
    // HERE GOES VIEWS OF TASKS
    // EVERY TASK VIEW SHOULD BE ADDED BELOW
    // ------------------------------
    switch (id) {
        // intro part
        case 0:  return new ScreenWelcome; break;
        case 1:  return new ScreenAbout; break;
        case 2:  return new ScreenDescription; break;
        // questions part
        case 3:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(0))); break;
        case 4:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(1))); break;
        case 5:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(2))); break;
        case 6:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(3))); break;
        case 7:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(4))); break;
        case 8:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(5))); break;
        case 9:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(6))); break;
        case 10: return ScreenQuestion::get(this, questions.at(questionsOrder.at(7))); break;
        case 11: return ScreenQuestion::get(this, questions.at(questionsOrder.at(8))); break;
        case 12: return ScreenQuestion::get(this, questions.at(questionsOrder.at(9))); break;
        // tasks part
        case 13: return new ScreenTask1;  break;
        case 14: return new ScreenTask2;  break;
        case 15: return new ScreenTask3;  break;
        case 16: return new ScreenTask4;  break;
        case 17: return new ScreenTask5;  break;
        case 18: return new ScreenTask6;  break;
        case 19: return new ScreenTask7;  break;
        case 20: return new ScreenTask8;  break;
        case 21: return new ScreenTask9;  break;
        case 22: return new ScreenTask10; break;
        case 23: return new ScreenTask11; break;
        case 24: return new ScreenTask12; break;
        // summary part
        case 99: return ScreenSummary::get(this); break;
        default: return NULL;
    }
    // ------------------------------
}

void Core::next() {
    next(false);
}

void Core::next(bool force) {
    QString message;
    if (showedTask == 0 || window->getWidget() == nullptr || window->getWidget()->validate(this, &message)) {
        if (force || (score >= 0 && showedTask < tasks.size())) {
            showedTask++;
            show(message);
        } else {
            showedTask = tasks.size() - 1;
            next(true);
        }
    }
}

void Core::back() {
    if (showedTask > 0) {
        showedTask--;
        show("");
    }
}

void Core::reset() {
    generate();
    next();
}

void Core::changeScore(int delta) {
    this->score += delta;
}

int Core::getScore() {
    return score;
}

void Core::show(QString message) {
    if (currentTask < showedTask) {
        currentTask = showedTask;
    }
    Task *task = tasks.at(showedTask - 1);
    window->setStep(task->getNumber(), task->getTitle());
    window->setProgress(showedTask);
    window->setScore(score);
    window->setMessage(message);
    window->setWidget(getView(task->getId())->init(task->getId(), currentTask != showedTask));
    window->setNextEnabled(currentTask == showedTask ? task->getNextButtonActive() : true);
    window->setBackEnabled(showedTask > 1);
}

unsigned int Core::getSeed() {
    return seed;
}
