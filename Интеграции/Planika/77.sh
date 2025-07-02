#!/bin/bash

### ВОЗМОЖНО ПРИДЕТСЯ УСТАНОВИТЬ xxd (apt install xxd)


hexstr=$(echo $3 | xxd -p -r);
IFS=':' read -r -a params <<< "$hexstr"
# Проверяем количество аргументов
if [ "$#" -ne 3 ]; then
    echo "Использование: $0 <scr> $1 <scr> $2 <addr> $3 <URL:функция>"
    echo "Доступные функции: start, on, plus, minus, lock, unlock"
    exit 1
fi

URL=${params[0]};
FUNCTION=${params[1]};

# Функция для отправки POST-запроса
PostButton() {
    local button_id=$1
    local params="__SL_P_UBT=$button_id"
    
    curl -X POST "$URL" \
        -H "Content-type: application/x-www-form-urlencoded" \
        -H "Content-length: ${#params}" \
        -H "Connection: close" \
        -d "$params" \
        > /dev/null 2>&1
}

# Определяем какую функцию вызвать
case $FUNCTION in
    start)
        PostButton "ButtonStart"
        ;;
    on)
        PostButton "ButtonStop"
        ;;
    plus)
        PostButton "ButtonPlus"
        ;;
    minus)
        PostButton "ButtonMinus"
        ;;
    lock)
        PostButton "ButtonLockON"
        ;;
    unlock)
        PostButton "ButtonLockOFF"
        ;;
    *)
        echo "Неизвестная функция: $FUNCTION"
        echo "Доступные функции: start, on, plus, minus, lock, unlock"
        exit 1
        ;;
esac

echo "Команда $FUNCTION выполнена"
