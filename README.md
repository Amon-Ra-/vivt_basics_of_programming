#Решения заданий по курсу Основы программирования в ВИВТ
Задания требуется выполнить на языке программирования C++

Все задания выполнились в IDE Visual Studio Code с установленными расширениями и компилятором.

##Инструкция развертывания окружения для разработки на C++

1. Установить Visual Studio Code. Скачать дитрибутив можно [отсюда](https://code.visualstudio.com/Download "Скачать VSC")
2. Установить и настроить раширения для работы с C++
   1. [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) от Microsoft.  Важное примечание! Для корректной работы этого расширения нам понадобится установленный и добавленный в PATH компилятор MinGW. Подробную видео инструкция установки компилятора можно посмотреть [здесь](https://youtu.be/sXW2VLrQ3Bs "Смотреть видео с индусом, который подробно рассказывает об установке MinGW")
   2. [C++ Intellisense](https://marketplace.visualstudio.com/items?itemName=austin.code-gnu-global) от austin
   3. [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner) от Jun Han. Данное расширение поможет быстро настроить запуск отладку кода на C++ при этом не будет требоваться долго настраивать сам VSC для запуска отладки.
    Небольшие настройки расширения Code Runner:
        Выберите File -> Preferences -> Settings.
Введите “code runner run in terminal” в поле поиска и установите галку в чекбоксе:
Выберите File -> Preferences -> Settings.
Введите в поиске “Run Code Configuration”.
Определите местонахождение “Code-runner: Executor Map” и выберите “Edit in settings.json”. Это откроет файл settings.json. Добавьте туда следующий код:
"code-runner.executorMap": {    "cpp": "cd $dir && g++ -std=c++14 $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt"}