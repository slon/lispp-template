# lispp - Интерпретатор scheme

## Введение

Первым делом прочтите первые 5 глав из http://ds26gte.github.io/tyscheme/index.html

Прочитали? Тогда продолжим :)

## Описание задания

В этом домашнем задании вам нужно будет написать интерпретатор для языка
scheme. Интерпретатор должен поддерживать 4 типа данных (symbol, list, number и boolean),
7 специальных форм (quote, if, and, or, set!, lambda и define) и некоторое количество
встроенных функций.

По конкретным вопросам реализации какой-то функциональности смотрите тесты в этом репозитории.

Интерпретатор должен работать в режиме REPL (read-eval-print-loop), тоесть
читать с stdin по одной форме, выполнять эту форму и печатать на stdout результат выполнения.

### Детали реализации

* Ваш интерпретатор должен различать 3 вида ошибок:

  1. Ошибки синтаксиса. Возникают когда программа не соответствует формальному синтаксису языка.
     В случае возникновения синтаксической ошибки интерпретатор должен печатать сообщение 
    `syntax error` и завершаться.

  2. Ошибки обращения к неопределённым переменным.
 
     В случае возникновения подобной ошибки интерпретатор должен прекращать выполнение текущей формы,
     печатать на экран сообщение `name error` и переходить к слещующей итерации цикла REPL.

  3. Ошибки времени исполнения. К этим ошибкам относятся все остальные ошибки которые могу возникнуть
     во время выполнения программы. Например: неправильное количество аргументов передано в функцию, 
     неправильный тип аргумента.
    
     В случае возникновения этой ошибки интерпретатор должен печатать `runtime error` и переходить к
     следующей итерации цикла REPL.

* Для представления чисел используйте целочисленный тип int64_t, считайте что
переполнение не происходит.

* В логическом контексте, ложным является только значение `#f`, все остальные значения
(в том числе `0` и пустой список `'()`) являются истинными.

* Ваша реализация должна использовать case-sensetive идентификаторы. `plus` и `PLUS` - должны
быть разными переменными.

## Как пользоваться тестами

В этом репозитории лежит набор тестов, на котором вы можете проверять свою реализацию.
Тесты используют библиотеку gtest.

Чтобы начать ими пользоваться, вам нужно реализовать 5 методов внутри класса LispTest
(файл test/lisp_test.h). Сейчас в этих методах находятся заглушки.

Класс LispTest используется как TestFixture во всех тестах(прочитайте в документации на gtest что это означает).

Все тесты находятся в состоянии DISABLED(посмотрите в документации на gtest что это значит).
Это сделано для того, чтобы вы могли активировать их по мере реализации очередной функциональности.
Так вам не нужно будет запускать тесты, которые заведомо падают.

Общий алгоритм вашей работы должен быть примерно такой:
1. Выбрать очередную фичу.
2. Убрать DISABLED из имени соответствующих тестов, убедиться что они падают.
3. Разобраться с тем как фича должна быть реализована, реализовать, убедиться что тесты проходят.
4. goto 1.

## Советы по реализации

1. В начале разберитесь с представлением основных структур данных в вашей программе.
Разберитесь с тем, как должен быть реализован list.

2. Продумайте стратегию управления памятью. Используйте std::shared_ptr.

3. Алгоритм чтения форм из потока лучше отделить от алгоритма разделения потока на токены.
Смотрите как это было сделано в задаче про калькулятор.

## Формальный синтаксис языка

```
<program> ->  <form>*
<form>    ->  <definition> | <expression>
```

```
<definition> -> <variable definition>
              | <function definition>

<variable definition> -> (define <variable> <expression>)

<function definition> -> (define (<variable> <variable>*) <body>)
<body>                -> <expression>+

<variable> -> <identifier>
```

```
<expression> -> <constant>
              | <variable>
              | (quote <datum>) | '<datum>
              | (lambda (<variable>+) <body>)
              | (set! <variable> <expression>)
              | (and <expression>*) | (or <expression>*)
              | (if <expression> <expression> <expression>) | (if <expression> <expression>)
              | <application>

<application> -> (<expression> <expression>*)
<constant>    -> <boolean> | <number>
```

```
<identifier> -> <initial> <subsequent>* | <plus> | <minus>
<initial>    -> <letter> | ! | $ | % | & | * | / | : | < | = | > | ? | ~ | _ | ^
<subsequent> -> <initial> | <digit> | . | + | -
```

*Идентификатор не может начинаться с + или -, за исключением особых случаев + и -.*
*'+1' - это число, а '+' - это идентификатор +*

```
<datum>   -> <boolean> | <number> | <symbol> | <list>
<boolean> -> #t | #f
<number>  -> <digit>+ | <plus><digit>+ | <minus><digit>+
<symbol>  -> <identifier>
<list>    -> ( <datum>* ) | ( <datum>+ . <datum> )
```
