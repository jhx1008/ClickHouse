Функции для работы с URL
------------------------

Все функции работают не по RFC - то есть, максимально упрощены ради производительности.

Функции, извлекающие часть URL-а.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Если в URL-е нет ничего похожего, то возвращается пустая строка.

protocol
""""""""
Возвращает протокол. Примеры: http, ftp, mailto, magnet...

domain
""""""
Возвращает домен.

domainWithoutWWW
""""""""""""""""
Возвращает домен, удалив не более одного 'www.' с начала, если есть.

topLevelDomain
""""""""""""""
Возвращает домен верхнего уровня. Пример: .ru.

firstSignificantSubdomain
"""""""""""""""""""""""""
Возвращает "первый существенный поддомен". Это понятие является нестандартным и специфично для Яндекс.Метрики. Первый существенный поддомен - это домен второго уровня, если он не равен одному из com, net, org, co, или домен третьего уровня, иначе. Например, firstSignificantSubdomain('https://news.yandex.ru/') = 'yandex', firstSignificantSubdomain('https://news.yandex.com.tr/') = 'yandex'. Список "несущественных" доменов второго уровня и другие детали реализации могут изменяться в будущем.

cutToFirstSignificantSubdomain
""""""""""""""""""""""""""""""
Возвращает часть домена, включающую поддомены верхнего уровня до "первого существенного поддомена" (см. выше). 

Например, ``cutToFirstSignificantSubdomain('https://news.yandex.com.tr/') = 'yandex.com.tr'``.

path
""""
Возвращает путь. Пример: ``/top/news.html`` Путь не включает в себя query string.

pathFull
""""""""
То же самое, но включая query string и fragment. Пример: /top/news.html?page=2#comments

queryString
"""""""""""
Возвращает query-string. Пример: page=1&lr=213. query-string не включает в себя начальный знак вопроса, а также # и всё, что после #.

fragment
""""""""
Возвращает fragment identifier. fragment не включает в себя начальный символ решётки.

queryStringAndFragment
""""""""""""""""""""""
Возвращает query string и fragment identifier. Пример: страница=1#29390.

extractURLParameter(URL, name)
""""""""""""""""""""""""""""""
Возвращает значение параметра name в URL, если такой есть; или пустую строку, иначе; если параметров с таким именем много - вернуть первый попавшийся. Функция работает при допущении, что имя параметра закодировано в URL в точности таким же образом, что и в переданном аргументе.

extractURLParameters(URL)
"""""""""""""""""""""""""
Возвращает массив строк вида name=value, соответствующих параметрам URL. Значения никак не декодируются.

extractURLParameterNames(URL)
"""""""""""""""""""""""""""""
Возвращает массив строк вида name, соответствующих именам параметров URL. Значения никак не декодируются.

URLHierarchy(URL)
"""""""""""""""""
Возвращает массив, содержащий URL, обрезанный с конца по символам /, ? в пути и query-string. Подряд идущие символы-разделители считаются за один. Резка производится в позиции после всех подряд идущих символов-разделителей. Пример:

URLPathHierarchy(URL)
"""""""""""""""""""""
То же самое, но без протокола и хоста в результате. Элемент / (корень) не включается. Пример:
Функция используется для реализации древовидных отчётов по URL в Яндекс.Метрике.

.. code-block:: text

  URLPathHierarchy('https://example.com/browse/CONV-6788') =
  [
      '/browse/',
      '/browse/CONV-6788'
  ]

decodeURLComponent(URL)
"""""""""""""""""""""""
Возвращает декодированный URL.
Пример:

.. code-block:: sql

  SELECT decodeURLComponent('http://127.0.0.1:8123/?query=SELECT%201%3B') AS DecodedURL;

.. code-block:: text
  
  ┌─DecodedURL─────────────────────────────┐
  │ http://127.0.0.1:8123/?query=SELECT 1; │
  └────────────────────────────────────────┘
  
Функции, удаляющие часть из URL-а
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Если в URL-е нет ничего похожего, то URL остаётся без изменений.

cutWWW
""""""
Удаляет не более одного 'www.' с начала домена URL-а, если есть.

cutQueryString
""""""""""""""
Удаляет query string. Знак вопроса тоже удаляется.

cutFragment
"""""""""""
Удаляет fragment identifier. Символ решётки тоже удаляется.

cutQueryStringAndFragment
"""""""""""""""""""""""""
Удаляет query string и fragment identifier. Знак вопроса и символ решётки тоже удаляются.

cutURLParameter(URL, name)
""""""""""""""""""""""""""
Удаляет параметр URL с именем name, если такой есть. Функция работает при допущении, что имя параметра закодировано в URL в точности таким же образом, что и в переданном аргументе.
