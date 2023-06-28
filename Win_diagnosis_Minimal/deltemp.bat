@echo off

echo Czyszcze Pliki tymczasowe...

C:

cd %temp%
DEL /q *

echo Wyczyszczono!

timeout /t 10 /nobreak