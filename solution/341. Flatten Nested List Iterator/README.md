# 341. Flatten Nested List Iterator

## 使用 stack (341_01.cpp)
每次遇到 List 時，都把 List 中的元素從後往前入棧。

## 使用 deque (341_02.cpp)
使用雙向隊列也可以實現同樣效果，從隊列頭取元素，如果是list，再逐個放回隊列頭，直至第一個元素是integer。
